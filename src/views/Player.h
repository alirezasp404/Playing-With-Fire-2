

#ifndef PLAYING_WITH_FIRE_2_PLAYER_H
#define PLAYING_WITH_FIRE_2_PLAYER_H


#include <QString>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
class Player:   public QGraphicsPixmapItem{
public:
    QString name;
    int score{};
    static int bombRadius;
    static int speed;
    int lifeCount{};
    int horizontalIndex{};
    int verticalIndex{};
    static int horizontalMovement;
    static int verticalMovement;
public:
    Player(const QString& image,int width,int height, int hIndex, int vIndex);
    void moveToRight();
    void moveToLeft();
    void moveToUp();
    void moveToDown();
};

#endif //PLAYING_WITH_FIRE_2_PLAYER_H
