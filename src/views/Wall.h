

#ifndef PLAYING_WITH_FIRE_2_WALL_H
#define PLAYING_WITH_FIRE_2_WALL_H


#include "Block.h"

class Wall :public Block{
public:
    Wall(int width,int height,int horizontalIndex,int verticalIndex);
};


#endif //PLAYING_WITH_FIRE_2_WALL_H
