
#ifndef PLAY_WITH_FIRE_2_HOME_H
#define PLAY_WITH_FIRE_2_HOME_H
#include <QGraphicsView>
#include "../views/TextField.h"

class Home : public QGraphicsView{
Q_OBJECT
private:
    QGraphicsScene* scene;
    TextField* textField;
public:
    Home();
    ~Home();

public slots:
    void start();
};


#endif //PLAY_WITH_FIRE_2_HOME_H
