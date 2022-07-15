
#include "Guide.h"
Guide::Guide() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("black"));
    setScene(scene);

    guideText1 = new Button(1200,1000);
    guideText1->setPlainText("player1:\n\nmove to up:\t\t\tW\nmove to down:\t\tS\nmove to right:\t\t\tD\nmove to left:\t\t\tA\nbomb:\t\t\t\tE\n");
    scene->addItem(guideText1);
    guideText1->setPos(200,200 );

    guideText2 = new Button(1200,1000);
    guideText2->setPlainText("player2:\n\nmove to up:\t\t\tARROW UP\nmove to down:\t\tARROW DOWN\nmove to right:\t\t\tARROW RIGHT\nmove to left:\t\t\tARROW LEFT\nbomb:\t\t\t\tSHIFT\n");
    scene->addItem(guideText2);
    guideText2->setPos(200,500 );

    back = new Button(100,100);
    back->setPlainText("BACK");
    scene->addItem(back);
    back->setPos(20, 20 );

    player1 = new Player(true, this->width() / 10, 10);
    player2 = new Player(false, this->width() / 10, 10);
    scene->addItem(player1);
    scene->addItem(player2);
    player1->setPos(800,280);
    player2->setPos(800,580);
    connect(back,&Button::press, this,&Guide::backToStart);
};
Guide::~Guide() {
    delete scene;
    delete guideText1;
    delete guideText2;
    delete player1;
    delete player2;
    delete back;
}
void Guide::backToStart(){
    (new start)->show();
    close();
};