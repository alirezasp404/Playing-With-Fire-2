

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
    scene->setBackgroundBrush(QImage(":/images/homebg"));
    setScene(scene);
    textField = new TextField(200, 55);
    textField->setPlainText("Enter your name");
    scene->addItem(textField);
    textField->setPos(width() / 2-100, height() / 2);

    textField = new TextField(200, 55);
    textField->setPlainText("Enter your name");
    scene->addItem(textField);
    textField->setPos(width() / 2-100, height() / 2+100);

    firstLabel = new Label();
    firstLabel->setPlainText("First Player Name:");
    scene->addItem(firstLabel);
    firstLabel->setPos(width() / 2 - 100, height() / 2 - firstLabel->boundingRect().height());

    secondLabel = new Label();
    secondLabel->setPlainText("Second Player Name:");
    scene->addItem(secondLabel);
    secondLabel->setPos(width() / 2 - 100, height() / 2 - secondLabel->boundingRect().height() + 100);

    button = new Button(200,150);
    button->setPlainText("    Start Game");
    scene->addItem(button);
    button->setPos(width() / 2-100, height() / 2 + secondLabel->boundingRect().height() + 145);

    connect(button,&Button::press, this,&Home::start);
}

Home::~Home() {
    delete firstLabel;
    delete secondLabel;
    delete textField;
    delete scene;
}
void Home::start(){
    auto name=textField->toPlainText();
    (new Game())->show();
    close();


}