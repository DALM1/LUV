local api = {}

function api.send_message(message)
    local http = require("socket.http")
    local ltn12 = require("ltn12")

    local response_body = {}
    local res, code, headers, status = http.request {
        url = "http://localhost:3000/messages",
        method = "POST",
        headers = {
            ["Content-Type"] = "application/json"
        },
        source = ltn12.source.string(message),
        sink = ltn12.sink.table(response_body)
    }

    if code == 201 then
        print("Message envoyé avec succès !")
    else
        print("Erreur lors de l'envoi du message.")
    end
end

return api
