//
// Created by Reza on 7/13/2022.
//

#ifndef PLAYING_WITH_FIRE_2_START_H
#define PLAYING_WITH_FIRE_2_START_H
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <string>
#include "../views/TextField.h"
#include "../windows/Home.h"
#include "../views/Button.h"


class start : public QGraphicsView{
private:
    QGraphicsScene* scene;
    Button* button1;
    Button* button2;
    Button* button3;

public:
    start();
    ~start();

public slots:
    void startGame();
    void exit();
};


#endif //PLAYING_WITH_FIRE_2_START_H
