# LUV
<<<<<<< HEAD

Ce projet est un réseau social avec les fonctionnalités suivantes :
- Chat 1v1 et chat de groupe
- Création de threads et réponses
- Envoi de fichiers
- Système de vote pour recommander les threads

````
mon_reseau_social/
├── backend/
│   ├── app/
│   │   ├── controllers/
│   │   │   └── chat_controller.rb
│   │   ├── models/
│   │   │   ├── user.rb
│   │   │   └── thread.rb
│   │   └── views/
│   ├── config/
│   │   └── routes.rb
│   ├── db/
│   └── main.c
├── docker-compose.yml
├── frontend/
│   ├── assets/
│   │   ├── images/
│   │   └── sounds/
│   ├── conf.lua
│   └── src/
│       ├── api.lua
│       ├── chat.lua
│       ├── main.lua
│       ├── profile.lua
│       └── threads.lua
└── README.md
# LUV
=======

gcc -o server main.c -I/opt/homebrew/opt/libmicrohttpd/include -L/opt/homebrew/opt/libmicrohttpd/lib -lmicrohttpd

gcc -o server main.c -I/opt/homebrew/opt/libmicrohttpd/include -L/opt/homebrew/opt/libmicrohttpd/lib -lmicrohttpd -lsqlite3

gcc -o server main.c -I/opt/homebrew/opt/libmicrohttpd/include -L/opt/homebrew/opt/libmicrohttpd/lib -lmicrohttpd -lsqlite3
./server

gcc -o server main.c -I/opt/homebrew/opt/libmicrohttpd/include -L/opt/homebrew/opt/libmicrohttpd/lib -lmicrohttpd -lsqlite3
