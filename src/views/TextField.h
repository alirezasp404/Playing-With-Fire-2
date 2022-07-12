
#ifndef PLAY_WITH_FIRE_2_TEXTFIELD_H
#define PLAY_WITH_FIRE_2_TEXTFIELD_H

#include <QGraphicsTextItem>

class TextField : public QGraphicsTextItem {
private:
    int width{};
    int height{};
public:
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TextField(int width, int height);
};


#endif //PLAY_WITH_FIRE_2_TEXTFIELD_H
