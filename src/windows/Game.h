
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
    QList<Wall *>walls;
    QList< class Box *>boxes;
    QGraphicsScene *scene{};
    Player *player1;
    Player *player2;
    Button *name1;
    Button *name2;
    Button *lives;
    Button *exitButton;
    int horizontalMovement{};
    int verticalMovement{};
    void addWalls(int width, int height);

    void addBoxes(int width, int height);

    void addPlayers(int width, int height);

    bool checkBoxPosition(int i, int j) const;

    void showDetails(const QString &, const QString &, const QString &);
protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    Game(const QString &, const QString &, QString,QString);

    ~Game() override;
    bool checkMovement( int horizontalIndex,int verticalIndex) const;
public slots:

    void exit();
};


#endif //PLAY_WITH_FIRE_2_GAME_H
