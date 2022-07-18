//
// Created by Reza on 7/18/2022.
//

#ifndef PLAYING_WITH_FIRE_2_BOMB_H
#define PLAYING_WITH_FIRE_2_BOMB_H
#include <QGraphicsPixmapItem>


class Bomb: public QGraphicsPixmapItem{
public:
    int positionX;
    int positionY;
    Bomb(int ,int ,int ,int);
};


#endif //PLAYING_WITH_FIRE_2_BOMB_H
