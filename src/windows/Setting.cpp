

#include "Setting.h"
Setting::Setting() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/homebg"));
    setScene(scene);


    back = new Button(100,100);
    back->setPlainText("BACK");
    scene->addItem(back);
    back->setPos(20, 20 );

    connect(back,&Button::press, this,&Setting::backToStart);

};
Setting::~Setting() {
    delete scene;
    delete back;
}
void Setting::backToStart(){
    (new start)->show();
    close();
};
