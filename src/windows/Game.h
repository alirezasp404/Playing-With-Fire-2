
#ifndef PLAY_WITH_FIRE_2_GAME_H
#define PLAY_WITH_FIRE_2_GAME_H

#include <QGraphicsView>
#include <QString>
#include <QFile>
#include "../views/Wall.h"
#include "../views/Box.h"
#include "../views/Button.h"
#include "../views/Label.h"
#include "../views/Player.h"


class Game : public QGraphicsView {
private:
    const int numOfWalls;
    const int numOfBoxes;
    Wall *wall[15][15];

    class Box *box[130][130];

    QGraphicsScene *scene;
    Player *player1;
    Player *player2;

    void addWalls(int width, int height);

    void addBoxes(int width, int height);

    void addPlayers(int width, int height);

    void setBoxPosition(int [][2]) const;

    void showDetails( const QString&,const QString&, QString);

    Button *name1;
    Button *name2;
    Button *lives;
    Button *exitButton;

public:
    Game(QString, QString, QString);

    ~Game();

    void addPLayers(int width, int height);

public slots:

    void exit();
};


#endif //PLAY_WITH_FIRE_2_GAME_H
