#include "Button.h"
#include<string>

Button::Button() {
    texture = LoadTexture("resources/default_button.png");
    textureRect = (Rectangle){0, 0, texture.width, texture.height / 3};
    position = (Vector2){0, 0};
    collisionRect = (Rectangle){position.x, position.y, texture.width, texture.height / 3};
    hasClickFunction = false;
    text = "";
}

Button::Button(int x_pos, int y_pos) {
    texture = LoadTexture("resources/default_button.png");
    textureRect = (Rectangle){0, 0, texture.width, texture.height / 3};
    position = (Vector2){x_pos, y_pos};
    collisionRect = (Rectangle){position.x, position.y, texture.width, texture.height / 3};
    hasClickFunction = false;
    text = "";
}

Button::Button(int x_pos, int y_pos, char* texturePath) {
    texture = LoadTexture(texturePath);
    textureRect = (Rectangle){0, 0, texture.width, texture.height / 3};
    position = (Vector2){x_pos, y_pos};
    collisionRect = (Rectangle){position.x, position.y, texture.width, texture.height / 3};
    hasClickFunction = false;
    text = "";
}

void Button::draw(Vector2 mousePoint) {
    if (!CheckCollisionPointRec(mousePoint, collisionRect)) {
        textureRect.y = texture.height / 3 * 0;
    } else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        textureRect.y = texture.height / 3 * 2;
    } else {
        textureRect.y = texture.height / 3 * 1;
    }
    DrawTextureRec(texture, textureRect, position, WHITE);
    if (text != "") {
        DrawText(text.c_str(), position.x, position.y, fontSize, BLUE);
        // DrawTextPro(GetFontDefault(), text.c_str(), position, (Vector2){0, 0}, 0, fontSize, 5, BLUE);
    }
}

bool Button::IsPressed(Vector2 mousePoint) {
    return CheckCollisionPointRec(mousePoint, collisionRect) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Button::setPos(Vector2 pos) {
    if (pos.x >= 0 && pos.x <= GetScreenWidth() && pos.y >= 0 && pos.y <= GetScreenHeight()) {
        position = pos;
        collisionRect = (Rectangle){position.x, position.y, texture.width, texture.height / 3};
        return true;
    }
    return false;
}

void Button::addText(std::string pText, float pFontSize) {
    text = pText;
    
    fontSize = pFontSize;
}