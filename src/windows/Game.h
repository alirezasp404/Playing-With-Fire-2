
#ifndef PLAY_WITH_FIRE_2_GAME_H
#define PLAY_WITH_FIRE_2_GAME_H

#include <QGraphicsView>
#include <QString>
#include <QFile>
#include <QTimer>
#include "../views/Wall.h"
#include "../views/Box.h"
#include "../views/Bomb.h"
#include "../views/Button.h"
#include "../views/Label.h"
#include "../views/Player.h"
#include "../windows/Final.h"
#include "../views/Explosion.h"
#include <QKeyEvent>

class Game : public QGraphicsView {
private:
    const int numOfWalls;
    int numOfBoxes;
    int boxIndex{0};
    QList<Wall *> walls;
    QList<class Box *> boxes;
    QGraphicsScene *scene{};
    QTimer* timer;
    Player *player1{};
    Player *player2{};
    Label *name1{};
    Label *name2{};
    Label *score1{};
    Label* score2{};
    Label* life1{};
    Label* life2{};
    Bomb *bomb1;
    Bomb *bomb2;
    QList<Explosion*>explosion;
    Button *exitButton{};
    int horizontalMovement{};
    int verticalMovement{};
    void playersMovement(Player* player,char direction,Bomb* bomb= nullptr);
    void addWalls();

    void addBoxes();

    void addBomb();
    void addPlayers(QString,QString,int,int,int);

    bool checkBoxPosition(int i, int j) const;

    int checkMovement(int horizontalIndex, int verticalIndex) const;

    void removeBoxes(int hIndex, int vIndex,Player* player,Player* enemy,Bomb* bomb);

    void showDetails();


protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    Game(const QString &, const QString &, const QString&,QString setting[3]);

    ~Game() override;

public slots:
    void addBoxesOnTimer();

    void explodeTime1();

    void explodeTime2();
void removeExplosion1();
void removeExplosion2();
    void exit();
};


#endif //PLAY_WITH_FIRE_2_GAME_H
