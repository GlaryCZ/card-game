#ifndef MAINMENU_H
#define MAINMENU_H

#include "Button.h"
#include "Background.h"

class MainMenu {
    Button playButton;
    Button showInventoryButton;
    Vector2 mousePoint;
    Background background;
    void handleEvents(int &showScreen);
    void draw();
public:
    MainMenu();
    void run(int &showScreen);
};

#endif