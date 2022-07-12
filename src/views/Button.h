

#ifndef PLAY_WITH_FIRE_2_BUTTON_H
#define PLAY_WITH_FIRE_2_BUTTON_H
#include <QGraphicsTextItem>



class Button : public QGraphicsTextItem {
Q_OBJECT
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int width;
    int height;
public:
    Button(int width,int height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void press();
};


#endif //PLAY_WITH_FIRE_2_BUTTON_H


