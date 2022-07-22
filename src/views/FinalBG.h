//
// Created by Reza on 7/22/2022.
//

#ifndef PLAYING_WITH_FIRE_2_FINALBG_H
#define PLAYING_WITH_FIRE_2_FINALBG_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class FinalBG :public QGraphicsPixmapItem {

public:
    bool initialized{false};
    FinalBG(QGraphicsItem *parent=nullptr);
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //PLAYING_WITH_FIRE_2_FINALBG_H
