

#include "Start.h"

#include <utility>
#include "../windows/Game.h"
Start::Start(QString numOfBoxes,QString gameSpeed) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("black"));
    setScene(scene);

    back= new Background();
    scene->addItem(back);

    this->numOfBoxes=std::move(numOfBoxes);
    this->gameSpeed=std::move(gameSpeed);
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

    connect(button1,&Button::press, this,&Start::startGame);
    connect(button2,&Button::press, this,&Start::guide);
    connect(button3,&Button::press, this,&Start::setting);
    connect(button4,&Button::press, this,&Start::exit);

}
Start::~Start() {
    delete button1;
    delete button2;
    delete button3;
    delete button4;
    delete scene;
    delete back;

}
void Start::startGame(){
    (new Home(numOfBoxes,gameSpeed))->show();
    close();

}
void Start::exit(){
    close();
}
void Start::setting(){
    (new Setting)->show();
    close();
}
void Start::guide() {
    (new Guide)->show();
    close();
}
