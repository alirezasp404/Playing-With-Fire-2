
#include "Final.h"

Final::Final(Player *winner, Player *player) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("black"));
    setScene(scene);

    winnerImage = new Player(winner->getImage(), width() / 3, width() / 3, 1, 1);
    scene->addItem(winnerImage);
    winnerImage->name = winner->name;

    finish = new Button(width() / 12, height() / 20);
    finish->setPlainText("  FINISH");
    scene->addItem(finish);
    finish->setPos(14 * width() / 30, height() / 1.1);

    winnerName = new Label();
    winnerName->setPlainText(winner->name + "  WON");
    scene->addItem(winnerName);
    winnerName->setPos(14 * width() / 30, height() / 3);

    playerName1 = new Label();
    playerName1->setPlainText(winner->name);
    scene->addItem(playerName1);
    playerName1->setPos(width() / 10, height() / 3);


    playerName2 = new Label();
    playerName2->setPlainText(player->name);
    scene->addItem(playerName2);
    playerName2->setPos(9*width() / 10, height() / 2);

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