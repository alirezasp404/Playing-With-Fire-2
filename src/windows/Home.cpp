

#include "Home.h"
#include "../views/Label.h"
#include "../views/Button.h"
#include "../windows/Game.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("#a8a002"));
    setScene(scene);
    textField = new TextField(200, 55);
    textField->setPlainText("Enter your name");
    scene->addItem(textField);
    textField->setPos(width() / 2-100, height() / 2);

    textField = new TextField(200, 55);
    textField->setPlainText("Enter your name");
    scene->addItem(textField);
    textField->setPos(width() / 2-100, height() / 2+100);

    auto label1 = new Label();
    label1->setPlainText("First Player Name:");
    scene->addItem(label1);
    label1->setPos(width() / 2-100, height() / 2-label1->boundingRect().height());

    auto label2 = new Label();
    label2->setPlainText("Second Player Name:");
    scene->addItem(label2);
    label2->setPos(width() / 2-100, height() / 2-label2->boundingRect().height()+100);

    auto button = new Button(200,150);
    button->setPlainText("    Start Game");
    scene->addItem(button);
    button->setPos(width() / 2-100, height() / 2+label2->boundingRect().height()+145);

    connect(button,&Button::press, this,&Home::start);
}

Home::~Home() {
    delete textField;
    delete scene;
}
void Home::start(){
    auto name=textField->toPlainText();
    close();
    (new Game())->show();

}