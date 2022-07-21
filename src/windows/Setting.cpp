

#include "Setting.h"
Setting::Setting() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    setScene(scene);
    background= new Background();
    scene->addItem(background);

    back = new Button(100,100);
    back->setPlainText(" BACK");
    scene->addItem(back);
    back->setPos(width()/10, height()/15 );

    label1 = new Label();
    label1->setPlainText("Number Of Boxes");
    scene->addItem(label1);
    label1->setPos(width() / 2.33, height() /2.7);

    numOfBoxes = new TextField(200, 55);
    numOfBoxes->setPlainText("100");
    scene->addItem(numOfBoxes);
    numOfBoxes->setPos(width() / 2.3, height() / 2.3);

    label2 = new Label();
    label2->setPlainText("Speed");
    scene->addItem(label2);
    label2->setPos(width() / 2.33, height() /2);

    speed = new TextField(200, 55);
    speed->setPlainText("1");
    scene->addItem(speed);
    speed->setPos(width() / 2.3, height() / 1.8);

    label3 = new Label();
    label3->setPlainText("Bomb Radius");
    scene->addItem(label3);
    label3->setPos(width() / 2.33, height() /1.6);

    bombRadius = new TextField(200, 55);
    bombRadius->setPlainText("2");
    scene->addItem(bombRadius);
    bombRadius->setPos(width() / 2.3, height() / 1.45);

    connect(back,&Button::press, this,&Setting::backToStart);

}
Setting::~Setting() {
    delete background;
    delete scene;
    delete back;
    delete numOfBoxes;
    delete label1;
    delete label2;
    delete speed;
    delete label3;
    delete bombRadius;
}
void Setting::backToStart(){

    (new Start(  numOfBoxes->toPlainText(),speed->toPlainText(),bombRadius->toPlainText()))->show();
    close();
}
