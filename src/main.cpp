#include<raylib.h>
#include<iostream>
#include<functional>
#include "Game.h"

int main(void) {
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "extrémní karetní hra");
    // SetWindowState(FLAG_WINDOW_RESIZABLE);
    Game game;
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        game.run();
    }

    CloseWindow();
    return 0;
}

// levels -> rewards (coins)
// shop -> new cards, level up cards
