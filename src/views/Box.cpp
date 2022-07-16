
#include "Box.h"

Box::Box(int blockWidth, int blockHeight) {
    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(blockWidth,blockHeight);
    setPixmap(pixmap);
}
