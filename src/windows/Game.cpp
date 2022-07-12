
#include "Game.h"
#include<time.h>

Game::Game() : QGraphicsView(), numOfWalls(15),numOfBoxes(130) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("white"));
    setScene(scene);
    int blockWidth = width() / numOfWalls;
    int blockHeight = height() / numOfWalls;
    addWalls(blockWidth, blockHeight);
    addBoxes(blockWidth, blockHeight);
}

Game::~Game() {
    delete scene;
    for (int i = 0; i < numOfWalls; ++i) {
        for (int j = 0; j < numOfWalls; ++j) {
            delete wall[i][j];
        }
    }
    for (int i = 0; i < numOfBoxes; ++i) {
        for (int j = 0; j < numOfBoxes; ++j) {
            delete box[i][j];
        }
    }
}
