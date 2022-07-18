
#ifndef PLAYING_WITH_FIRE_2_GUIDE_H
#define PLAYING_WITH_FIRE_2_GUIDE_H
#include <QGraphicsView>
#include "../views/Button.h"
#include "../views/Player.h"
#include "../windows/Start.h"


class Guide: public QGraphicsView{
protected:
    Player* player1;
    Player* player2;
    Button* guideText1;
    Button* guideText2;
    Button* back;
    QGraphicsScene* scene;
public:
    Guide();
    ~Guide();
public slots:
    void backToStart();
};


#endif //PLAYING_WITH_FIRE_2_GUIDE_H
