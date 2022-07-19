

#ifndef PLAYING_WITH_FIRE_2_BOMB_H
#define PLAYING_WITH_FIRE_2_BOMB_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Player.h"


class Bomb: public QGraphicsPixmapItem{
public:
    int horizontalIndex;
    int verticalIndex;
    bool bombExploded{true};
    Bomb(int width,int height,const QString& bombImage);
    ~Bomb();
    QTimer* timer;
};


#endif //PLAYING_WITH_FIRE_2_BOMB_H
