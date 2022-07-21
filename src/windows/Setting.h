
#ifndef PLAYING_WITH_FIRE_2_SETTING_H
#define PLAYING_WITH_FIRE_2_SETTING_H

#include <QGraphicsView>
#include "../views/Button.h"
#include "../views/Background.h"
#include "../windows/Start.h"


class Setting : public QGraphicsView {
    Button *back;
    QGraphicsScene *scene;
    TextField *numOfBoxes;
    Label *label1;
    TextField *speed;
    TextField *bombRadius;
    Label *label2;
    Label *label3;
    Background *background;
public:
    Setting();

    ~Setting();

public slots:

    void backToStart();
};


#endif //PLAYING_WITH_FIRE_2_SETTING_H
