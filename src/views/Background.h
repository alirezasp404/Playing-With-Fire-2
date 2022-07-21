
#ifndef PLAYING_WITH_FIRE_2_BACKGROUND_H
#define PLAYING_WITH_FIRE_2_BACKGROUND_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Background :public QGraphicsPixmapItem{

public:
    bool initialized{false};
    Background(QGraphicsItem *parent=nullptr);
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};




#endif //PLAYING_WITH_FIRE_2_BACKGROUND_H
