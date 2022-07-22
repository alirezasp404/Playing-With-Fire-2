
#ifndef PLAYING_WITH_FIRE_2_FINAL_H
#define PLAYING_WITH_FIRE_2_FINAL_H

#include <QGraphicsView>
#include "../views/Button.h"
#include "../views/Label.h"
#include "../views/Player.h"
#include "../views/FinalBG.h"

class Final : public QGraphicsView {
public:
    Final(Player *winner, QString color1, Player *player, QString color2);

    ~Final() override;

protected:
    QGraphicsScene *scene;
    Button *finish;
    Label *winnerName;
    Label *playerName1;
    Label *playerName2;
    FinalBG *background;
public slots:

    void Finish();

};


#endif //PLAYING_WITH_FIRE_2_FINAL_H
