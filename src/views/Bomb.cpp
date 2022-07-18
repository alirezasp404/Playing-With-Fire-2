//
// Created by Reza on 7/18/2022.
//

#include "Bomb.h"
Bomb::Bomb(int width,int height,int x,int y) {
    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(3 * width / 8, 3 * width / 8);
    positionX=x;
    positionY=y;
    setPos(x,y);
}