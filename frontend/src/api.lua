local api = {}

function api.send_message(message)
    local http = require("socket.http")
    local ltn12 = require("ltn12")

    local response_body = {}
    local res, code, headers, status = http.request {
        url = "http://localhost:8888",
        method = "POST",
        headers = {
            ["Content-Type"] = "application/x-www-form-urlencoded"
        },
        source = ltn12.source.string("message=" .. message),
        sink = ltn12.sink.table(response_body)
    }

    if code == 200 then
        print("Message envoyé !")
    else
        print("Erreur lors de l'envoi du message.")
    end
end

return api
