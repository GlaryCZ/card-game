#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <raylib.h>
#include <iostream>

class Background {
private:
    Rectangle rect;
    Texture2D texture;
public:
    Background();
    Background(char *texturePath);
    void draw(Vector2 mousePoint);
    void setTexture(std::string path);
};

#endif // BACKGROUND_H