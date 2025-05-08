#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Button.h"
#include "Background.h"
#include "battle/Enemy.h"
#include "battle/Player.h"

class Battle {
private:
    Button backButton;
    Vector2 mousePoint;
    Background background;
    Enemy enemy;
    Player player;
    int game_over; // 1 - win, -1 - loss
    double elapsedTime;
    void draw();
    void handleEvents(int &showScreen);
public:
    Battle();
    void run(int &showScreen);
};

#endif