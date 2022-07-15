
#include "Game.h"
#include<ctime>

Game::Game(QString name1, QString name2, QString lives) : QGraphicsView(), numOfWalls(15), numOfBoxes(130) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/gamebg"));
    setScene(scene);
    int blockWidth = width() / numOfWalls;
    int blockHeight = height() / numOfWalls;
    addWalls(blockWidth, blockHeight);
    addBoxes(blockWidth, blockHeight);
    showDetails(name1, name2, lives);
    addPlayers(blockWidth, blockHeight);
//    controller = new Controller();
}

Game::~Game() {
    delete scene;
    for (int i = 0; i < numOfWalls; ++i) {
        for (int j = 0; j < numOfWalls; ++j) {
            delete wall[i][j];
        }
    }
    for (int i = 0; i < numOfBoxes; ++i) {
        for (int j = 0; j < numOfBoxes; ++j) {
            delete box[i][j];
        }
    }
    delete name1;
    delete name2;
    delete lives;
    delete player1;
    delete player2;
    delete exitButton;
}

void Game::addWalls(int wallWidth, int wallHeight) {
    for (int i = 0; i < numOfWalls; ++i) {
        for (int j = 0; j < numOfWalls; ++j) {
            if (i != 0 && i != numOfWalls - 1 && j != 0 && j != numOfWalls - 1 && (j % 2 != 0 || i % 2 != 0))
                continue;
            wall[i][j] = new Wall(wallWidth, wallHeight);
            scene->addItem(wall[i][j]);
            wall[i][j]->setPos(wallWidth * i, wallHeight * j);
        }
    }
}

void Game::addBoxes(int boxWidth, int boxHeight) {
    int boxPosition[130][2];
    setBoxPosition(boxPosition);
    for (int i = 0; i < numOfBoxes; ++i) {
        int x = boxPosition[i][0];
        int y = boxPosition[i][1];
        box[x][y] = new class Box(boxWidth, boxHeight);
        scene->addItem(box[x][y]);
        box[x][y]->setPos(boxWidth * x, boxHeight * y);
    }
}

void Game::setBoxPosition(int boxPosition[15][2]) const {
    srand(time(nullptr));
    for (int i = 0; i < numOfBoxes; ++i) {
        int x = (rand() + 1) % (numOfWalls - 1) + 1;
        int y = (rand() + x) % (numOfWalls - 1) + 1;
        bool boxIsNotOnWall =
                x != 0 && x != numOfWalls - 1 && y != 0 && y != numOfWalls - 1 && (y % 2 != 0 || x % 2 != 0);
        bool boxIsNotNearPlayer = !(x == 1 && y == 1) && !(x == 2 && y == 1) && !(x == 1 && y == 2) &&
                                  !(x == (numOfWalls - 3) && y == (numOfWalls - 2)) &&
                                  !(x == (numOfWalls - 2) && y == (numOfWalls - 3)) &&
                                  !(x == (numOfWalls - 2) && y == (numOfWalls - 2));
        if (boxIsNotNearPlayer && boxIsNotOnWall) {
            boxPosition[i][0] = x;
            boxPosition[i][1] = y;
        } else
            i--;
    }
}

void Game::showDetails(const QString &firstName, const QString &secondName, QString numLives) {
    name1 = new Button(200, 55);
    name1->setPlainText(firstName);
    scene->addItem(name1);
    name1->setPos(106, 3);
    name2 = new Button(200, 55);
    name2->setPlainText(secondName);
    scene->addItem(name2);
    name2->setPos(width() - 310, 3);
    exitButton = new Button(90, 55);
    exitButton->setPlainText("  EXIT");
    scene->addItem(exitButton);
    exitButton->setPos(width() - 815, 3);
    connect(exitButton, &Button::press, this, &Game::exit);

}

void Game::addPlayers(int width, int height) {
    player1 = new Player(true, width / 2, 10);
    player2 = new Player(false, width / 2, 10);
    scene->addItem(player1);
    scene->addItem(player2);
    player1->setPos(120, 60);
    player1->positionX = 120;
    player1->positionY = 60;
    player2->setPos(1350, 742);
    player2->positionX = 1350;
    player2->positionY = 742;
}

void Game::exit() {
    close();
}