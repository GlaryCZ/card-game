#include "Background.h"

Background::Background() {
    texture = LoadTexture("resources/default_background.png");
    rect = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
}

Background::Background(char *texturePath) {
    texture = LoadTexture(texturePath);
    rect = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
}

void Background::draw(Vector2 mousePoint) {
    DrawTextureRec(texture, rect, (Vector2){0, 0}, WHITE);
}

void Background::setTexture(std::string path) {
    texture = LoadTexture(path.c_str());
}