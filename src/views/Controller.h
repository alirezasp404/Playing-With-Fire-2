
#ifndef PLAYING_WITH_FIRE_2_CONTROLLER_H
#define PLAYING_WITH_FIRE_2_CONTROLLER_H


#include "Player.h"
#include <QKeyEvent>
class Controller :public QGraphicsPixmapItem{
private:
Player* player1;
Player* player2;
protected:
    void keyPressEvent(QKeyEvent *event) override;
public:
    Controller(Player* player1,Player* player2);
};


#endif //PLAYING_WITH_FIRE_2_CONTROLLER_H
