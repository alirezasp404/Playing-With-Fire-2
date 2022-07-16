
#include "Game.h"
#include<ctime>
#include <utility>

Game::Game(const QString& name1, const QString& name2, QString lives) : QGraphicsView(), numOfWalls(15), numOfBoxes(130) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
//    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
    setScene(scene);
    int blockWidth = width() / numOfWalls;
    int blockHeight = height() / numOfWalls;
    addWalls(blockWidth, blockHeight);
    addBoxes(blockWidth, blockHeight);
    showDetails(name1, name2, std::move(lives));
    addPlayers(blockWidth, blockHeight);
    controller = new Controller(player1,player2);
    scene->addItem(controller);
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
    delete controller;
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

void Game::setBoxPosition(int boxPosition[][2]) const {
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

void Game::showDetails(const QString &firstName, const QString &secondName, const QString& numLives) {
    name1 = new Button(2*width()/numOfWalls, height()/numOfWalls);
    name1->setPlainText(firstName);
    scene->addItem(name1);
    name1->setPos(width()/numOfWalls, width()/(numOfWalls*25));
    name2 = new Button(2*width()/numOfWalls, height()/numOfWalls);
    name2->setPlainText(secondName);
    scene->addItem(name2);
    name2->setPos(12*width()/numOfWalls, width()/(numOfWalls*25));
    exitButton = new Button(width()/numOfWalls, height()/numOfWalls);
    exitButton->setPlainText("  EXIT");
    scene->addItem(exitButton);
    exitButton->setPos(7*width()/numOfWalls, width()/(numOfWalls*25));
    connect(exitButton, &Button::press, this, &Game::exit);

}

void Game::addPlayers(int blockWidth, int blockHeight) {
    player1 = new Player(":/images/player1", blockWidth , blockHeight,blockWidth+blockWidth/4,blockHeight+blockHeight/4);
    player2 = new Player(":/images/player2", blockWidth, blockHeight,13*blockWidth+blockWidth/4,13*blockHeight+blockHeight/4);
    scene->addItem(player1);
    scene->addItem(player2);
}

void Game::exit() {
    close();
}