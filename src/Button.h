#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>
#include<string>

class Button {
    Rectangle textureRect;
    Texture2D texture;
    Vector2 position;
    Rectangle collisionRect;
    bool hasClickFunction;
    std::string text;
    float fontSize; 
public:
    Button();
    Button(int x_pos, int y_pos);
    Button(int x_pos, int y_pos, char* texturePath);
    void draw(Vector2 mousePoint);
    bool IsPressed(Vector2 mousePoint);
    bool setPos(Vector2 pos);
    // void addClickFunction(std::function<void()>);
    void addText(std::string pText, float fontSize);
};

#endif // BUTTON_H