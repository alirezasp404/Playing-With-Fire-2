

#include "Background.h"
Background::Background(QGraphicsPixmapItem* parent): QGraphicsPixmapItem(parent){


}
void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter,option,widget);
    if(!intialized){
        auto sceneWidth=scene()->sceneRect().width();
        auto sceneHeight=scene()->sceneRect().height();
        QPixmap pixmap(":/images/homeBG");
        pixmap=pixmap.scaled(sceneWidth,sceneHeight,Qt::KeepAspectRatio);
        setPixmap(pixmap);
        setPos(0,0);
        intialized= true;
    }

    }
