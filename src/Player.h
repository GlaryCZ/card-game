#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "Enemy.h"
#include <vector>
// #include "Card.h"
class Card;

class Player {
    Texture2D texture;
    Vector2 pos;
    
public: // TODO remove public
    int hp;
    int damage;
    /*
    Card* card1;
    Card* card2;
    Card* card3;
    Card* card4;
    bool hasCard1;
    bool hasCard2;
    bool hasCard3;
    bool hasCard4;
    */
    int cardsCount;
    bool hasCard[4];
    Card *cards[4];
public:
    Player();
    void handleEvents(Vector2 mousePoint, Enemy *enemy);
    void setCards(Card *pCard1, Card *pCard2, Card *pCard3, Card *pCard4);
    bool addCard(Card pCard);
    void draw();
    void drawCards(Vector2 mousePoint);
    bool isDead();
};

#endif // BACKGROUND_H