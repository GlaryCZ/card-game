#ifndef INVENTORY_H
#define INVENTORY_H

#include "Button.h"

class Inventory {
    Button backButton;
    Vector2 mousePoint;
    void draw();
    void handleEvents(int &showScreen);
public:
    Inventory();
    void run(int &showScreen);
};

#endif