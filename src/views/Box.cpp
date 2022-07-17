
#include "Box.h"

Box::Box(int blockWidth, int blockHeight,int horizontalIndex,int verticalIndex): Block(horizontalIndex,verticalIndex) {
    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(blockWidth,blockHeight);
    setPixmap(pixmap);
    setPos(horizontalIndex*blockWidth,verticalIndex*blockHeight);
}
