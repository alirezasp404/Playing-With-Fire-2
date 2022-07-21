

#include "Wall.h"
Wall::Wall(int width, int height,int horizontalIndex,int verticalIndex): Block(horizontalIndex,verticalIndex) {
    QPixmap pixmap(":/images/wall");
    pixmap=pixmap.scaled(width/1.1,height/1.1);
    setPixmap(pixmap);
    setPos(horizontalIndex*width+width/15,verticalIndex*height+height/15);
}