# LUV

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
