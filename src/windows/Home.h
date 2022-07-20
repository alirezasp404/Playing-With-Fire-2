
#ifndef PLAY_WITH_FIRE_2_HOME_H
#define PLAY_WITH_FIRE_2_HOME_H
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QMessageBox>
#include "../views/TextField.h"
#include "../views/Label.h"
#include "../views/Button.h"

class Home : public QGraphicsView{
Q_OBJECT
private:
    QGraphicsScene* scene;
    TextField* textField1;
    TextField* textField2;
    TextField* numberOfLife;
    Label* firstLabel;
    Label* secondLabel;
    Label* thirdLabel;
    Button* button;
    QString numOfBoxes;
    QString gameSpeed;
public:
    Home(QString numOfBoxes,QString gameSpeed);
    ~Home() override;
    static void writeFile(const QString&,const QString&,const QString&);
public slots:
    void start();
};


#endif //PLAY_WITH_FIRE_2_HOME_H
