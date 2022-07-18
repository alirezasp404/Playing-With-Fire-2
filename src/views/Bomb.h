

#ifndef PLAYING_WITH_FIRE_2_BOMB_H
#define PLAYING_WITH_FIRE_2_BOMB_H
#include <QGraphicsPixmapItem>


class Bomb: public QGraphicsPixmapItem{
public:
    int horizontalIndex;
    int verticalIndex ;
    Bomb(int ,int ,int ,int);
};


#endif //PLAYING_WITH_FIRE_2_BOMB_H
