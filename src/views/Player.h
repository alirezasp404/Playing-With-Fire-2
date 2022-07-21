

#ifndef PLAYING_WITH_FIRE_2_PLAYER_H
#define PLAYING_WITH_FIRE_2_PLAYER_H


#include <QString>
#include <QGraphicsPixmapItem>

class Player:public QGraphicsPixmapItem{
public:
    QString name;
    int score{};
    int bombRadius;
    int lifeCount{};
    int speed;
    int horizontalIndex{};
    int verticalIndex{};
    int horizontalMovement{};
    int verticalMovement{};
    QString Image;
public:
    QString getImage();
    Player(const QString& image,int width,int height, int hIndex, int vIndex);
    void moveToRight();
    void moveToLeft();
    void moveToUp();
    void moveToDown();

};

#endif //PLAYING_WITH_FIRE_2_PLAYER_H
