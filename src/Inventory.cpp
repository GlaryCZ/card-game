#include "Inventory.h"

Inventory::Inventory() {
    backButton.setPos((Vector2){GetScreenWidth()-50, 10});
}

void Inventory::run(int &showScreen) {
    handleEvents(showScreen);
    draw();
}

void Inventory::handleEvents(int &showScreen) {
    mousePoint = GetMousePosition();
    if (backButton.IsPressed(mousePoint)) {
        showScreen = 0;
    }
}

void Inventory::draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    backButton.draw(mousePoint);

    EndDrawing();
}