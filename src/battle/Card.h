#ifndef CARD_H
#define CARD_H

#include <raylib.h>
#include<functional>
#include "Player.h"
#include "Enemy.h"
#include "Button.h"

class Card {
    // int num;
    std::function<void(Player*, Enemy*)> playFunction;
    // int pos; // 0, 1, 2, 3
    
    bool initialized;
    Button button;
public:
    
    Card();
    Card(std::function<void(Player*, Enemy*)> func);
    void playCard(Player *player, Enemy *enemy);
    void setFunc(std::function<void(Player*, Enemy*)> func);
    /*
    bool setPos(int position) {
        if(position >= 0 && position <= 3) {
            pos = position;
            button.setPos((Vector2){20+200*pos, 300});
            return true;
        }
        return false;
    }
    */
    bool isPlayed(Vector2 mousePoint);
    bool isSet();
    void setButton(Button but);
    void draw(Vector2 mousePoint);
};



#endif // BACKGROUND_H