
#include "Box.h"

Box::Box(int blockWidth, int blockHeight,int horizontalIndex,int verticalIndex): Block(horizontalIndex,verticalIndex) {
    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(blockWidth/1.1,blockHeight/1.1);
    setPixmap(pixmap);
    setPos(horizontalIndex*blockWidth+blockWidth/15,verticalIndex*blockHeight+blockHeight/15);
}
