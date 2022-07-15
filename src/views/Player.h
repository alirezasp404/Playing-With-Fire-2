

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
    int positionX{};
    int positionY{};
    int horizontalMovement{};
    int verticalMovement{};
    bool checkHorizontalMovement( int position);
    bool checkVerticalMovement( int position);
public:
    Player(QString image,int width,int height,int x,int y);
    void moveToRight();
    void moveToLeft();
    void moveToUp();
    void moveToDown();
};

#endif //PLAYING_WITH_FIRE_2_PLAYER_H
