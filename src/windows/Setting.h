//
// Created by Reza on 7/15/2022.
//

#ifndef PLAYING_WITH_FIRE_2_SETTING_H
#define PLAYING_WITH_FIRE_2_SETTING_H
#include <QGraphicsView>
#include "../views/Button.h"
#include "../windows/start.h"


class Setting :public QGraphicsView{
protected:
    Button* back;
    QGraphicsScene* scene;

public:
    Setting();
    ~Setting();

public slots:
    void backToStart();
};


#endif //PLAYING_WITH_FIRE_2_SETTING_H
