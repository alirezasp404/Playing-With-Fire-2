//
// Created by Reza on 7/16/2022.
//

#include "Final.h"
Final::Final(Player* winner) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("black"));
    setScene(scene);

    Winner=new Player(":/images/player1", width()/5, height()/7, width()/960,height()/300);
   scene->addItem(Winner);
    Winner->name=winner->name;

    finish = new Button(width()/15, height()/20);
    finish->setPlainText("  FINISH");
    scene->addItem(finish);
    finish->setPos(14*width()/30, height()/1.1);

    winnerName = new Button(width()/15, height()/20);
    winnerName->setPlainText(Winner->name);
    scene->addItem(winnerName);
    winnerName->setPos(width()/2.15,height()/3);

    nameLabel = new Label();
    nameLabel->setPlainText("NAME OF THE WINNER:");
    scene->addItem(nameLabel);
    nameLabel->setPos(width() / 2.33, height() / 3.5);

    connect(finish, &Button::press, this, &Final::Finish);

}
Final::~Final()  {
    delete scene;
    delete finish;
}
void Final:: Finish(){
    close();
};
