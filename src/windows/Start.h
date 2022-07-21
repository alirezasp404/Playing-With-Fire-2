

#ifndef PLAYING_WITH_FIRE_2_START_H
#define PLAYING_WITH_FIRE_2_START_H
#include <QGraphicsView>
#include "../views/TextField.h"
#include "../windows/Home.h"
#include "../windows/Setting.h"
#include "../windows/Guide.h"
#include "../views/Button.h"
#include "../views/Background.h"


class Start : public QGraphicsView{
private:
    QGraphicsScene* scene;
    Button* button1;
    Button* button2;
    Button* button3;
    Button* button4;
    Background* background;
    QString settings[3];
public:
    Start(QString numOfBoxes="100",QString gameSpeed="1",QString bombRadius="2");
    ~Start();

public slots:
    void startGame();
    void guide();
    void setting();
    void exit();
};


#endif //PLAYING_WITH_FIRE_2_START_H
