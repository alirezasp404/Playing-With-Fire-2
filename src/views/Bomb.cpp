
#include "Bomb.h"
Bomb::Bomb(int width,int height,int hIndex,int vIndex):horizontalIndex(hIndex),verticalIndex(vIndex) {
    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(3 * width / 8, 3 * width / 8);
    setPos(hIndex*width,vIndex*height);
}