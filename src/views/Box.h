#ifndef PLAYING_WITH_FIRE_2_BOX_H
#define PLAYING_WITH_FIRE_2_BOX_H


#include "Block.h"
#include <QTimer>

class Box : public Block {
public:
    Box(int width, int height, int horizontalIndex, int verticalIndex);
};

#endif //PLAYING_WITH_FIRE_2_BOX_H
