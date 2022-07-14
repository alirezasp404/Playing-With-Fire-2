//
// Created by Reza on 7/13/2022.
//

#include "start.h"
#include "../views/Label.h"
#include "../views/Button.h"
#include "../windows/Game.h"
start::start() {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/homebg"));
    setScene(scene);
    button1 = new Button(200,150);
    button1->setPlainText("    START GAME");
    scene->addItem(button1);
    button1->setPos(width() / 2-100, height() / 2 );

    button2 = new Button(200,150);
    button2->setPlainText("        SETTING");
    scene->addItem(button2);
    button2->setPos(width() / 2-100, height() / 2 +65);

    button3 = new Button(200,150);
    button3->setPlainText("            EXIT");
    scene->addItem(button3);
    button3->setPos(width() / 2-100, height() / 2 +130);
    connect(button1,&Button::press, this,&start::startGame);
    connect(button3,&Button::press, this,&start::exit);


}
start::~start() {
    delete button1;
    delete button2;
    delete button3;
}
void start::startGame(){
    (new Home)->show();
    close();

}
void start::exit(){
    close();
}