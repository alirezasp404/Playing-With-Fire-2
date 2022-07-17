#ifndef PLAYING_WITH_FIRE_2_BLOCK_H
#define PLAYING_WITH_FIRE_2_BLOCK_H
#include <QGraphicsPixmapItem>

class Block :public QGraphicsPixmapItem{
public:
int horizontalIndex,verticalIndex;
    Block(int hIndex,int vIndex);

};


#endif //PLAYING_WITH_FIRE_2_BLOCK_H
