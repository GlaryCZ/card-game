#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Button.h"
#include "Background.h"
#include "Card.h"
// #include "Enemy.h"
// #include "Player.h"

class Battle {
private:
    class Player {
        Texture2D texture;
        Vector2 pos;
        public: // TODO remove public
        int hp;
        int damage;
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
    };
    class Enemy {

    };
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