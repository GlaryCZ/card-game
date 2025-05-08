#ifndef GAME_H
#define GAME_H

#include "Battle.h"
#include "Inventory.h"
#include "MainMenu.h"
#include <vector>

class Game {
private:
    int showScreen;
    Battle battle;
    Inventory inventory;
    MainMenu mainMenu;
    std::vector<Card> allCardsInInventory;
public:
    Game();
    void run();
};



#endif