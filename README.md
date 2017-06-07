# Project to reimplement League of Legends Season 1 server
*The main focus of this Project is to accurately reimplement the Season 1 League of Legends server.*
#### Current Todo: 
1. Get in game
    * Some reworking needed for stats
    * Replication needs improvement
    * R3d framing
    * Stats loading
2. Items
3. Skillshots/spells
4. etc...
5. pathing?
6. movement?



# Setup guide

#### Download and setup client files
* Download version 1.0.0.673 or 1.0.0.106/1.0.0.105 of League client (https://drive.google.com/uc?id=0B6s8bt_HRu-gV21Ed1RWVnlLUXc&export=download)

* After extracting the league client, copy the contents of these 5 folders: 
    * `X:/Path/To/Extracted/LoL-1.0.0.673/RADS/projects/lol_game_client/managedfiles/0.0.0.0/`
    * `X:/Path/To/Extracted/LoL-1.0.0.673/RADS/projects/lol_game_client/managedfiles/0.0.0.1/`
    * `X:/Path/To/Extracted/LoL-1.0.0.673/RADS/projects/lol_game_client/managedfiles/0.0.0.2/`
    * `X:/Path/To/Extracted/LoL-1.0.0.673/RADS/projects/lol_game_client/managedfiles/0.0.0.3/`
    * `X:/Path/To/Extracted/LoL-1.0.0.673/RADS/solutions/lol_game_client_sln/releases/0.0.0.2/deploy/`

    and paste the contents into `X:/Path/To/Extracted/LoL-1.0.0.673/`


#### Install Qt and setup project
* Install Qt. http://download.qt.io/official_releases/online_installers/ (note: During installation, needed components are Qt 5.8, 32bit compiler of choice, and QtCreator)
* Clone the git repository
* Open OGLeague2.pro project file in QtCreator
* Open main.cpp and change `gameinfo.basePaths = { "C:/lol/LoL-1.0.0.673" };` to `X:/Path/To/Extracted/LoL-1.0.0.673/`
* Rebuild and run


# Running the client

#### To run the game, make a .bat file:
```
@echo off
cd "X:/Path/To/Extracted/LoL-1.0.0.673/"
start "" "League of Legends.exe" "8394" "LoLLauncher.exe" "" "127.0.0.1 5119 GLzvuWtyCfHyGhF2 1"
```

