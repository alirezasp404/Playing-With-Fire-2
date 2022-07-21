
#ifndef PLAYING_WITH_FIRE_2_BACKGROUND_H
#define PLAYING_WITH_FIRE_2_BACKGROUND_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Background :public QGraphicsPixmapItem{

public:
    bool intialized{false};
    Background(QGraphicsPixmapItem *parent=nullptr);
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif //PLAYING_WITH_FIRE_2_BACKGROUND_H
