

#ifndef PLAYING_WITH_FIRE_2_PLAYER_H
#define PLAYING_WITH_FIRE_2_PLAYER_H


#include <QString>
#include <QGraphicsPixmapItem>

class Player:public QGraphicsPixmapItem{
public:
    QString name;
    int score{};
    int bombCount{};
    int lifeCount{};
    int speed{};
    int bombRadius{};
    int horizontalIndex{};
    int verticalIndex{};
    int horizontalMovement{};
    int verticalMovement{};
    QString Image;
    QString getImage();
public:
    Player(const QString& image,int width,int height,int x,int y);
    void moveToRight();
    void moveToLeft();
    void moveToUp();
    void moveToDown();

};

#endif //PLAYING_WITH_FIRE_2_PLAYER_H
