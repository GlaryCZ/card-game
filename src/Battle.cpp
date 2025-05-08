#include "Battle.h"
#include "Card.h"

Battle::Battle() {
    backButton.setPos((Vector2){GetScreenWidth()-50, 10});
    elapsedTime = 0;
    Card card1;
    Card card2;
    std::function<void(Player*, Enemy*)> fun = [](Player *player, Enemy *enemy) {
        player->damage += 1;
    };
    card2.setFunc(fun);

    player.addCard(card1);
    player.addCard(card2);
}

void Battle::run(int &showScreen) {
    handleEvents(showScreen);
    draw();
}

void Battle::handleEvents(int &showScreen) {
    mousePoint = GetMousePosition();
    if (backButton.IsPressed(mousePoint)) {
        showScreen = 0;
    }

    player.handleEvents(mousePoint, &enemy);
    enemy.handleEvents(player);
}

void Battle::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    background.draw(mousePoint);
    backButton.draw(mousePoint);
    std::string c = ("Frame time: "+std::to_string(GetFrameTime())+" FPS: "+std::to_string(1/GetFrameTime()));
    DrawText(c.c_str(), 0, 0, 20, RED);

    enemy.draw();
    player.draw();
    player.drawCards(mousePoint);

    if (enemy.isDead()) {
        // TODO
    } else if (player.isDead()) {
        // TODO
    }
    EndDrawing();
}