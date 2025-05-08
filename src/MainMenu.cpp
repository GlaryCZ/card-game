#include "MainMenu.h"

MainMenu::MainMenu() {
    playButton.setPos((Vector2){GetScreenWidth()/2-50, GetScreenHeight()/2-20});
    showInventoryButton.setPos((Vector2){GetScreenWidth()/2-50, GetScreenHeight()/2-20+50});
    background.setTexture("resources/wabbit_alpha.png");

    playButton.addText("  PLAY", 40);
    showInventoryButton.addText("  inventory", 30);
}

void MainMenu::run(int &showScreen) {
    handleEvents(showScreen);
    draw();
}

void MainMenu::handleEvents(int &showScreen) {
    mousePoint = GetMousePosition();
    if (playButton.IsPressed(mousePoint)) {
        showScreen = 1;
    } else if (showInventoryButton.IsPressed(mousePoint)) {
        showScreen = 2;
    }
}

void MainMenu::draw() {
    BeginDrawing();  // draw
    ClearBackground(BLACK);

    background.draw(mousePoint);
    playButton.draw(mousePoint);
    showInventoryButton.draw(mousePoint);

    EndDrawing();
}