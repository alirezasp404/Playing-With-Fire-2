

#include "Player.h"
Player::Player(bool isPlayer1,int width, int height) {
    if(isPlayer1) {
        QPixmap pixmap(":/images/player1");
        pixmap = pixmap.scaled(3*width/4, 3*width/4);
        setPixmap(pixmap);
    }else{
        QPixmap pixmap(":/images/player2");
        pixmap=pixmap.scaled(3*width/4,3*width/4);
        setPixmap(pixmap);
    }
}