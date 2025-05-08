#include "Enemy.h"
#include "Player.h"

Enemy::Enemy() {
    texture = LoadTexture("resources/default_enemy.png");
    pos = (Vector2){GetScreenWidth()/4*3, GetScreenHeight()/2-texture.height/2};
    isAttacking = false;
    damage = 3;
    hp = 10;
}
void Enemy::handleEvents(Player &player) {
    if(isAttacking) {
        player.hp -= damage;
        isAttacking = false;
    }
}
void Enemy::draw() {
    DrawTextureV(texture, pos, WHITE);
    DrawText(TextFormat("%d", hp), pos.x, pos.y, 40, BLACK);
}
void Enemy::getAttacked(int damage) {
    hp -= damage;
    isAttacking = true;
}

bool Enemy::isDead() {
    if (this->hp <= 0) {
        return true;
    }
    return false;
}