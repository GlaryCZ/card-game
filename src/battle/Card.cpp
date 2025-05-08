#include "Card.h"
#include "Enemy.h"
#include "Player.h"

Card::Card() {
    std::function<void(Player*, Enemy*)> attack = [](Player *player, Enemy *enemy) {
        enemy->hp -= player->damage;
    };
    playFunction = attack;
    initialized = true;
    
    // TODO, set default pos and func
    // void def(Player *player, Enemy *enemy);
    // playFunction = def;
}

Card::Card(std::function<void(Player*, Enemy*)> func) { // pos = 0,1,2,3
    playFunction = func;
    initialized = true;
    // pos = position;
    // button.setPos((Vector2){20+200*pos, 300});
}

bool Card::isSet() {
    return initialized;
}

void Card::playCard(Player *player, Enemy *enemy) {
    playFunction(player, enemy);
    enemy->isAttacking = true;
}

void Card::setFunc(std::function<void(Player*, Enemy*)> func) {
    playFunction = func;
    initialized = true;
}

void Card::setButton(Button but) {
    button = but;
}

void Card::draw(Vector2 mousePoint) {
    button.draw(mousePoint);
}

bool Card::isPlayed(Vector2 mousePoint) {
    return button.IsPressed(mousePoint);
}