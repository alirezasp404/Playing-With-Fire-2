
#ifndef PLAY_WITH_FIRE_2_GAME_H
#define PLAY_WITH_FIRE_2_GAME_H

#include <QGraphicsView>
#include <QString>
#include <QFile>
#include "../views/Wall.h"
#include "../views/Box.h"
#include "../views/Bomb.h"
#include "../views/Button.h"
#include "../views/Label.h"
#include "../views/Player.h"
#include "../windows/Final.h"
#include <QKeyEvent>

class Game : public QGraphicsView {
private:
    const int numOfWalls;
    int numOfBoxes;
    QList<Wall *> walls;
    QList<class Box *> boxes;
    QGraphicsScene *scene{};
    Player *player1;
    Player *player2;
    Button *name1;
    Button *name2;
    Bomb *bomb1;
    Bomb *bomb2;
    int numberOfLives;
    Button *exitButton;
    int horizontalMovement{};
    int verticalMovement{};

    void addWalls();

    void addBoxes();

    void addPlayers();

    bool checkBoxPosition(int i, int j) const;

    int checkMovement(int horizontalIndex, int verticalIndex) const;

    void removeBoxes(int hIndex, int vIndex,int& score);

    void removeLeftBoxes(int hIndex, int vIndex,int& score ,bool checkAgain = false);

    void removeRightBoxes(int hIndex, int vIndex,int& score, bool checkAgain = false);

    void removeUpBoxes(int hIndex, int vIndex,int& score, bool checkAgain = false);

    void removeDownBoxes(int hIndex, int vIndex,int& score, bool checkAgain = false);

    void showDetails();


protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    Game(const QString &, const QString &, QString, const QString&);

    ~Game() override;

public slots:

    void explodeTime1();

    void explodeTime2();

    void exit();
};


#endif //PLAY_WITH_FIRE_2_GAME_H
