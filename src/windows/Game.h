//
// Created by Reza on 7/12/2022.
//

#ifndef PLAY_WITH_FIRE_2_GAME_H
#define PLAY_WITH_FIRE_2_GAME_H

#include <QGraphicsView>
#include <QString>
#include <QFile>
#include "../views/Wall.h"
#include "../views/Box.h"
#include "../views/Button.h"
#include "../views/Label.h"


class Game : public QGraphicsView {
    const int numOfWalls;
    const int numOfBoxes;
    Wall *wall[15][15];
    class Box *box[130][130];
    QGraphicsScene *scene;

    void addWalls(int width, int height);

    void addBoxes(int width, int height);

    void setBoxPosition(int [][2]);
    void showDetails(QString,QString,QString);
    Button* Name1;
    Button* Name2;
    Button* Lives;

public:
    Game(QString,QString,QString );
    ~Game();
};


#endif //PLAY_WITH_FIRE_2_GAME_H
