#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>
class Player;

class Enemy {
    Texture2D texture;
    
    Vector2 pos; // 0, 1, 2
    int damage;
    
public:
    int hp;
    bool isAttacking;
    Enemy();
    void handleEvents(Player &player);
    void draw();
    void getAttacked(int damage);
    bool isDead();
};

#endif // BACKGROUND_H