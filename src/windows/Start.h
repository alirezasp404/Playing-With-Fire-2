

#ifndef PLAYING_WITH_FIRE_2_START_H
#define PLAYING_WITH_FIRE_2_START_H
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <string>
#include "../views/TextField.h"
#include "../windows/Home.h"
#include "../windows/Setting.h"
#include "../windows/Guide.h"
#include "../views/Button.h"


class Start : public QGraphicsView{
private:
    QGraphicsScene* scene;
    Button* button1;
    Button* button2;
    Button* button3;
    Button* button4;
    QString numOfBoxes;
public:
    Start(QString numOfBoxes="100");
    ~Start();

public slots:
    void startGame();
    void guide();
    void setting();
    void exit();
};


#endif //PLAYING_WITH_FIRE_2_START_H
