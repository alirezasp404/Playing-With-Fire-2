

#ifndef PLAYING_WITH_FIRE_2_PLAYER_H
#define PLAYING_WITH_FIRE_2_PLAYER_H


#include <QString>
#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{
public:
    QString name;
    int score;
    int bombCount;
    int lifeCount;
    int speed;
    int bombRadius;
    int positionX;
    int positionY;
public:
    Player(bool isPlayer1,int width,int height);
};

#endif //PLAYING_WITH_FIRE_2_PLAYER_H
