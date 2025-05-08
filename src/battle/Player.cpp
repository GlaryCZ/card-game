#include "Player.h"
#include "Card.h"

Player::Player() {
    texture = LoadTexture("resources/default_player.png");
    pos = (Vector2){GetScreenWidth()/4, GetScreenHeight()/2-texture.height/2};
    hp = 10;
    damage = 5;
    cardsCount = 4;
    for (int i = 0; i < cardsCount; i++) {
        hasCard[i] = false;
    }
}

void Player::handleEvents(Vector2 mousePoint, Enemy *enemy) {
    for (int i = 0; i < cardsCount; i++) {
        if (hasCard[i]) {
            if (cards[i]->isPlayed(mousePoint)) {
                cards[i]->playCard(this, enemy);
            }
        }
    }
}

void Player::setCards(Card *pCard1, Card *pCard2, Card *pCard3, Card *pCard4) {
    addCard(*pCard1);
    addCard(*pCard2);
    addCard(*pCard3);
    addCard(*pCard4);
}

bool Player::addCard(Card pCard) {
    int pos = -1;
    Button tmpBut;

    for (int i = 0; i < cardsCount; i++) {
        if (!hasCard[i]) {
            cards[i] = new Card(pCard);
            tmpBut.setPos((Vector2){20+200*i, 300});
            cards[i]->setButton(tmpBut);
            hasCard[i] = true;
            return true;
        }
    }
    return false;
}

void Player::draw() {
    DrawTextureV(texture, pos, WHITE);
    DrawText(TextFormat("%d", hp), pos.x, pos.y, 40, BLACK);
}

void Player::drawCards(Vector2 mousePoint) {
    for (int i = 0; i < cardsCount; i++) {
        if (hasCard[i]) {
            cards[i]->draw(mousePoint);
        }
    }
}

bool Player::isDead() {
    if (this->hp <= 0) {
        return true;
    }
    return false;

}