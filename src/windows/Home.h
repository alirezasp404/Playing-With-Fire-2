
#ifndef PLAY_WITH_FIRE_2_HOME_H
#define PLAY_WITH_FIRE_2_HOME_H
#include <QGraphicsView>
#include "../views/TextField.h"
class Home : public QGraphicsView{
private:
    QGraphicsScene* scene;
    TextField* textField;
public:
    Home();
    ~Home();
};


#endif //PLAY_WITH_FIRE_2_HOME_H
