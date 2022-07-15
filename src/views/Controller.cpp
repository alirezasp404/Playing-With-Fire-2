#include "Controller.h"
#include <QKeyEvent>

Controller::Controller(Player *player1, Player *player2) {
    setFlags(GraphicsItemFlag::ItemIsFocusable);
    setFocus();
    this->player1 = player1;
    this->player2 = player2;
}

void Controller::keyPressEvent(QKeyEvent *event) {
    QGraphicsItem::keyPressEvent(event);
    //player1 movement
    if (event->key() == Qt::Key::Key_D)
        player1->moveToRight();
    else if (event->key() == Qt::Key::Key_A)
        player1->moveToLeft();
    else if (event->key() == Qt::Key::Key_W)
        player1->moveToUp();
    else if (event->key() == Qt::Key::Key_S)
        player1->moveToDown();
        //player2 movement
    else if (event->key() == Qt::Key::Key_Right)
        player2->moveToRight();
    else if (event->key() == Qt::Key::Key_Left)
        player2->moveToLeft();
    else if (event->key() == Qt::Key::Key_Up)
        player2->moveToUp();
    else if (event->key() == Qt::Key::Key_Down)
        player2->moveToDown();
}



