#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define PORT 8888
#define POST_BUFFER_SIZE 512

static int send_response(struct MHD_Connection *connection, const char *page) {
    struct MHD_Response *response;
    int ret;

    response = MHD_create_response_from_buffer(strlen(page), (void *)page, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return ret;
}

enum MHD_Result answer_to_connection(void *cls, struct MHD_Connection *connection,
                                     const char *url, const char *method,
                                     const char *version, const char *upload_data,
                                     size_t *upload_data_size, void **con_cls) {
    char *page;
    sqlite3 *db;
    char *err_msg = 0;

    page = malloc(POST_BUFFER_SIZE);
    if (page == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return MHD_NO;
    }

    int rc = sqlite3_open("chat.db", &db);
    if (rc != SQLITE_OK) {
        printf("Impossible d'ouvrir la base de données: %s\n", sqlite3_errmsg(db));
        free(page);
        return MHD_NO;
    }

    printf("Base de données utilisée : %s\n", realpath("chat.db", NULL));

    if (strcmp(method, "GET") == 0) {
        char *sql = "SELECT content FROM messages";
        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

        strcpy(page, "<html><body><h1>Messages:</h1>");
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char *content = sqlite3_column_text(stmt, 0);
            strcat(page, "<p>");
            strcat(page, (const char *)content);
            strcat(page, "</p>");
        }
        sqlite3_finalize(stmt);

        strcat(page, "</body></html>");
        send_response(connection, page);

    } else if (strcmp(method, "POST") == 0) {
        if (*upload_data_size > 0) {
            char *message = malloc(POST_BUFFER_SIZE);
            snprintf(message, POST_BUFFER_SIZE, "%s", upload_data);

            const char *sql = "INSERT INTO messages (content) VALUES (?)";
            sqlite3_stmt *stmt;
            sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
            sqlite3_bind_text(stmt, 1, message, -1, SQLITE_STATIC);

            rc = sqlite3_step(stmt);
            if (rc != SQLITE_DONE) {
                printf("Erreur lors de l'insertion du message %s\n", sqlite3_errmsg(db));
                send_response(connection, "<html><body>Erreur lors de l'insertion du message!</body></html>");
            } else {
                send_response(connection, "<html><body>Message enregistré avec succès!</body></html>");
            }

            sqlite3_finalize(stmt);
            free(message);
        } else {
            send_response(connection, "<html><body>Aucune donnée POST reçue.</body></html>");
        }

    } else {
        send_response(connection, "<html><body>Méthode non supportée.</body></html>");
    }

    sqlite3_close(db);
    free(page);
    return MHD_YES;
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                              &answer_to_connection, NULL, MHD_OPTION_END);

    if (NULL == daemon) {
        perror("Erreur lors du démarrage du serveur");
        return 1;
    }

    printf("Serveur démarré sur le port %d\n", PORT);
    getchar();

    MHD_stop_daemon(daemon);

    return 0;
}
