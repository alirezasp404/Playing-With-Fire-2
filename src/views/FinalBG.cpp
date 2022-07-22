//
// Created by Reza on 7/22/2022.
//

#include "FinalBG.h"
FinalBG::FinalBG(QGraphicsItem* parent): QGraphicsPixmapItem(parent){}
void FinalBG::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter,option,widget);
    if(!initialized){
        auto sceneWidth=scene()->sceneRect().width();
        auto sceneHeight=scene()->sceneRect().height();
        QPixmap pixmap(":/images/final");
        pixmap=pixmap.scaled(sceneWidth,sceneHeight,Qt::IgnoreAspectRatio);
        setPixmap(pixmap);
        setPos(0,0);
        initialized= true;
    }

}