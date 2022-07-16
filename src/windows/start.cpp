//
// Created by Reza on 7/13/2022.
//

#include "start.h"
#include "../windows/Game.h"
start::start() {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/homeBG"));
    setScene(scene);
    button1 = new Button(200,150);
    button1->setPlainText("   START GAME");
    scene->addItem(button1);
    button1->setPos(width() / 2.3, height() / 2 );

    button2 = new Button(200,150);
    button2->setPlainText("   GUIDE GAME");
    scene->addItem(button2);
    button2->setPos(width() / 2.3, height() /1.75);

    button3 = new Button(200,150);
    button3->setPlainText("      SETTING");
    scene->addItem(button3);
    button3->setPos(width() / 2.3, height() / 1.55);

    button4 = new Button(200,150);
    button4->setPlainText("          EXIT");
    scene->addItem(button4);
    button4->setPos(width() / 2.3, height() / 1.39);

    connect(button1,&Button::press, this,&start::startGame);
    connect(button2,&Button::press, this,&start::guide);
    connect(button3,&Button::press, this,&start::setting);
    connect(button4,&Button::press, this,&start::exit);

}
start::~start() {
    delete button1;
    delete button2;
    delete button3;
    delete button4;
    delete scene;
}
void start::startGame(){
    (new Home)->show();
    close();

}
void start::exit(){
    close();
}
void start::setting(){
    (new Setting)->show();
    close();
}
void start::guide() {
    (new Guide)->show();
    close();
}
