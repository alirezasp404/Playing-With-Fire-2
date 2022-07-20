

#include "Setting.h"
Setting::Setting() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/homeBG"));
    setScene(scene);


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
    label2->setPlainText("Game Speed");
    scene->addItem(label2);
    label2->setPos(width() / 2.33, height() /2);

    gameSpeed = new TextField(200, 55);
    gameSpeed->setPlainText("1");
    scene->addItem(gameSpeed);
    gameSpeed->setPos(width() / 2.3, height() / 1.8);

    connect(back,&Button::press, this,&Setting::backToStart);

}
Setting::~Setting() {
    delete scene;
    delete back;
    delete numOfBoxes;
    delete label1;
    delete label2;
    delete gameSpeed;
}
void Setting::backToStart(){

    (new Start(numOfBoxes->toPlainText(),gameSpeed->toPlainText()))->show();
    close();
}
