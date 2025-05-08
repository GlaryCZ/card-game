#ifndef GAME_H
#define GAME_H

#include "Battle.h"
#include "Inventory.h"
#include "MainMenu.h"

class Game {
private:
    int showScreen;
    Battle battle;
    Inventory inventory;
    MainMenu mainMenu;
public:
    Game();
    void run();
};



#endif