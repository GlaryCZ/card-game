#include "Game.h"
#include<iostream>

Game::Game() {
    showScreen = 0;
}

void Game::run() {
    int curPtr;
    switch (showScreen) {
        case 0: mainMenu.run(showScreen); break;
        case 1: battle.run(showScreen); break;
        case 2: inventory.run(showScreen); break;
        default: throw std::invalid_argument("invalid showscreen value"); break;
    }
}