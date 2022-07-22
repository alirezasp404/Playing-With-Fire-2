

#include "Explosion.h"

Explosion::Explosion(int width, int height) {
    QPixmap pixmap(":/images/explosion");
    pixmap = pixmap.scaled(4 * width / 7, 4 * height / 7);
    setPixmap(pixmap);
}
