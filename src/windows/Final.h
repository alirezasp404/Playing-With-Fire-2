//
// Created by Reza on 7/16/2022.
//

#ifndef PLAYING_WITH_FIRE_2_FINAL_H
#define PLAYING_WITH_FIRE_2_FINAL_H
#include <QGraphicsView>
#include "../views/Button.h"
#include "../views/Label.h"
#include "../views/Player.h"


class Final :public QGraphicsView{
public:
    Final(Player* winner,Player* player);
    ~Final() override;

protected:
    QGraphicsScene* scene;
    Button* finish;
    Label* winnerName;
    Label* playerName1;
    Label* playerName2;
    Label* playerScore1;
    Label* playerScore2;
public slots:
    void Finish();
};


#endif //PLAYING_WITH_FIRE_2_FINAL_H
