
#include "Final.h"

#include <utility>

Final::Final(Player *winner, QString color1, Player *player, QString color2) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
    setScene(scene);

    background = new FinalBG();
    scene->addItem(background);

    finish = new Button(width() / 12, height() / 20);
    finish->setPlainText("   FINISH");
    scene->addItem(finish);
    finish->setPos(14 * width() / 30, height() / 1.1);

    winnerName = new Label(90, "yellow");
    winnerName->setPlainText(winner->name + "\nWON");
    scene->addItem(winnerName);
    winnerName->setPos(8 * width() / 20, height() / 3);

    playerName1 = new Label(50, std::move(color1));
    playerName1->setPlainText(winner->name + " :\t" + QString::number(winner->score));
    scene->addItem(playerName1);
    playerName1->setPos(width() / 6.4, height() / 8);


    playerName2 = new Label(50, std::move(color2));
    playerName2->setPlainText(player->name + " :\t" + QString::number(player->score));
    scene->addItem(playerName2);
    playerName2->setPos(width() / 6.4, 5 * height() / 8);


    connect(finish, &Button::press, this, &Final::Finish);

}

Final::~Final() {
    delete background;
    delete scene;
    delete winnerName;
    delete playerName1;
    delete playerName2;
    delete finish;
    }

void Final::Finish() {
    close();
}


