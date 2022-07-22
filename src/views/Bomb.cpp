
#include "Bomb.h"
Bomb::Bomb(int width,int height){
    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(4 * width / 7, 4 * height / 7);
    setPixmap(pixmap);
    bombTimer=new QTimer();
    explosionTimer = new QTimer;
}
Bomb::~Bomb(){
    delete bombTimer;
    delete explosionTimer;
}

