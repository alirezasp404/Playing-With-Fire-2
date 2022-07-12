

#include "Home.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("#a8a002"));
    setScene(scene);
    textField = new TextField(200, 55);
    textField->setPlainText("hello");
    scene->addItem(textField);
    textField->setPos(width() / 2, height() / 2);
}

Home::~Home() {
    delete textField;
    delete scene;
}
