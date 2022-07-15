

#include "Wall.h"
Wall::Wall(int width, int height) {
    QPixmap pixmap(":/images/wall");
    pixmap=pixmap.scaled(width,height);
    setPixmap(pixmap);
}