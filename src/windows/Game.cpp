//
// Created by Reza on 7/12/2022.
//

#include "Game.h"

Game::Game(): QGraphicsView(){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("blue"));
    setScene(scene);

}