//
// Created by Reza on 7/12/2022.
//

#ifndef PLAY_WITH_FIRE_2_GAME_H
#define PLAY_WITH_FIRE_2_GAME_H

#include <QGraphicsView>
#include "../views/Wall.h"
#include "../views/Box.h"

class Game : public QGraphicsView {
    const int numOfWalls;
    const int numOfBoxes;
    Wall *wall[15][15];
    class Box *box[130][130];
    QGraphicsScene *scene;

    void addWalls(int width, int height);

    void addBoxes(int width, int height);

    void setBoxPosition(int [][2]);

public:
    Game();

    ~Game();
};


#endif //PLAY_WITH_FIRE_2_GAME_H
