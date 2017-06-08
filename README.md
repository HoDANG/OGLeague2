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

#### Download and extract client files
* Download version 1.0.0.673 of League client: [(LoL-1.0.0.673.zip)](https://drive.google.com/uc?id=0B6s8bt_HRu-gMDNqT2lWbnpleXc&export=download)
* Extract version 1.0.0.673 League client files like so:
    * `C:/`
        * `lol/`
            * `LoL-1.0.0.673/`
                * `DATA/`
                * `LEVELS/`
                * `League of Legends.exe`

#### Install Qt and setup project
* Install Qt: (http://download.qt.io/official_releases/online_installers/) 
    * Note: *During installation, needed components are Qt 5.8, compiler of choice(mingw/msvc2015/etc.), and QtCreator*
* Clone the git repository
* Open OGLeague2.pro project file in QtCreator
    * Note: *If the path to your 1.0.0.673 folder is not `C:/lol/LoL-1.0.0.673` , you must specify the path to your 1.0.0.673 folder in main.cpp:  `gameinfo.basePaths = { "X:/Path/To/Extracted/LoL-1.0.0.673" };`*
* Rebuild and run

# Running the client

#### To run the game, make a .bat file:
```
@echo off
cd "C:/lol/LoL-1.0.0.673"
start "" "League of Legends.exe" "8394" "LoLLauncher.exe" "" "127.0.0.1 5119 GLzvuWtyCfHyGhF2 1"
```
