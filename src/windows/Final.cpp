
#include "Final.h"

Final::Final(Player *winner, Player *player) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
    setScene(scene);

    finish = new Button(width() / 12, height() / 20);
    finish->setPlainText("    FINISH");
    scene->addItem(finish);
    finish->setPos(14 * width() / 30, height() / 1.1);

    winnerName = new Label(90,"yellow");
    winnerName->setPlainText(winner->name + "\nWON");
    scene->addItem(winnerName);
    winnerName->setPos(9*width()/20, height()/2);
//    14 * width() / 30
    playerName1 = new Label(50,"#fe635f");
    playerName1->setPlainText(winner->name);
    scene->addItem(playerName1);
    playerName1->setPos(width()/6.4, height()/3);


    playerName2 = new Label(50,"#fe635f");
    playerName2->setPlainText(player->name);
    scene->addItem(playerName2);
    playerName2->setPos(width()/1.2, height()/3);

    QString temp1=QString::number(winner->score);
    playerScore1 = new Label(50,"#fe635f");
    playerScore1->setPlainText(temp1);
    scene->addItem(playerScore1);
    playerScore1->setPos(width()/6.4, height()/2.6);

    QString temp2=QString::number(player->score);
    playerScore2 = new Label(50,"#fe635f");
    playerScore2->setPlainText(temp2);
    scene->addItem(playerScore2);
    playerScore2->setPos(width()/1.2, height()/2.6);

    connect(finish, &Button::press, this, &Final::Finish);

}

Final::~Final() {
    delete scene;
    delete winnerName;
    delete playerName1;
    delete playerName2;
    delete finish;
}

void Final::Finish() {
    close();
};
