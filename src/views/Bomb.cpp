
#include "Bomb.h"
Bomb::Bomb(int width,int height,const QString& bombImage){
    QPixmap pixmap(bombImage);
    pixmap = pixmap.scaled(3 * width / 8, 3 * height / 8);
    setPixmap(pixmap);
    timer=new QTimer();
}
Bomb::~Bomb(){
    delete timer;
}

