

#include "Wall.h"
Wall::Wall(int width, int height,int horizontalIndex,int verticalIndex): Block(horizontalIndex,verticalIndex) {
    QPixmap pixmap(":/images/wall");
    pixmap=pixmap.scaled(width,height);
    setPixmap(pixmap);
    setPos(horizontalIndex*width,verticalIndex*height);
}