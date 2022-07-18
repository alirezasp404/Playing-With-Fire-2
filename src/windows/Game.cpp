
#include "Game.h"
#include<ctime>
#include <utility>

Game::Game(const QString &name1, const QString &name2, QString lives, QString numberOfBoxes)
        : QGraphicsView(), numOfWalls(15) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
    setScene(scene);
    this->numOfBoxes= numberOfBoxes.toInt();
    horizontalMovement = width() / numOfWalls;
    verticalMovement = height() / numOfWalls;
    addWalls(horizontalMovement, verticalMovement);
    addBoxes(horizontalMovement, verticalMovement);
    addPlayers(horizontalMovement, verticalMovement);
    player1->name = name1;
    player2->name = name2;
    showDetails(name1, name2, std::move(lives));

}

Game::~Game() {
    delete scene;
    for (int i = 0; i < numOfWalls; ++i) {
        delete walls.at(i);
    }
    for (int i = 0; i < numOfBoxes; ++i) {
        delete boxes.at(i);
    }
    delete name1;
    delete name2;
    delete lives;
    delete player1;
    delete player2;
    delete exitButton;
}

void Game::addWalls(int wallWidth, int wallHeight) {
    int wallIndex = 0;
    for (int i = 0; i < numOfWalls; ++i) {
        for (int j = 0; j < numOfWalls; ++j) {
            if (i != 0 && i != numOfWalls - 1 && j != 0 && j != numOfWalls - 1 && (j % 2 != 0 || i % 2 != 0))
                continue;
            walls.append(new Wall(wallWidth, wallHeight, i, j));
            scene->addItem(walls.at(wallIndex));
            wallIndex++;
        }
    }
}

void Game::addBoxes(int boxWidth, int boxHeight) {
    srand(time(nullptr));
    for (int k = 0; k < numOfBoxes; ++k) {
        int i = (rand() + 1) % (numOfWalls - 1) + 1;
        int j = (rand() + i) % (numOfWalls - 1) + 1;
        bool boxIsNotOnWall =
                i != 0 && i != numOfWalls - 1 && j != 0 && j != numOfWalls - 1 && (j % 2 != 0 || i % 2 != 0);
        bool boxIsNotNearPlayer = !(i == 1 && j == 1) && !(i == 2 && j == 1) && !(i == 1 && j == 2) &&
                                  !(i == (numOfWalls - 3) && j == (numOfWalls - 2)) &&
                                  !(i == (numOfWalls - 2) && j == (numOfWalls - 3)) &&
                                  !(i == (numOfWalls - 2) && j == (numOfWalls - 2));
        if (boxIsNotNearPlayer && boxIsNotOnWall && checkBoxPosition(i,j)) {
            boxes.append(new class Box(boxWidth, boxHeight, i, j));
            scene->addItem(boxes.at(k));
        } else
            k--;
    }
}

bool Game::checkBoxPosition(int i, int j) const {
    for (int k = 0; k < boxes.size()-1; k++) {
        if (boxes.at(k)->horizontalIndex == i && boxes.at(k)->verticalIndex == j)
            return false;
    }
    return true;
}
void Game::showDetails(const QString &firstName, const QString &secondName, const QString &numLives) {
    name1 = new Button(2 * width() / numOfWalls, height() / numOfWalls);
    name1->setPlainText(firstName);
    scene->addItem(name1);
    name1->setPos(width() / numOfWalls, width() / (numOfWalls * 25));

    name2 = new Button(2 * width() / numOfWalls, height() / numOfWalls);
    name2->setPlainText(secondName);
    scene->addItem(name2);
    name2->setPos(12 * width() / numOfWalls, width() / (numOfWalls * 25));

    exitButton = new Button(width() / numOfWalls, height() / numOfWalls);
    exitButton->setPlainText("   EXIT");
    scene->addItem(exitButton);
    exitButton->setPos(7 * width() / numOfWalls, width() / (numOfWalls * 25));
    connect(exitButton, &Button::press, this, &Game::exit);

}

void Game::addPlayers(int blockWidth, int blockHeight) {
    player1 = new Player(":/images/player1", blockWidth, blockHeight, 1,
                         1);
    player2 = new Player(":/images/player2", blockWidth, blockHeight, numOfWalls - 2,
                         numOfWalls - 2);
    scene->addItem(player1);
    scene->addItem(player2);
}

void Game::exit() {
    (new Final(player1,player2))->show();
    close();
}

void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    //player1 movement
    if (event->key() == Qt::Key::Key_D) {
        if (checkMovement(player1->horizontalIndex + 1,
                          player1->verticalIndex)) {
            player1->moveToRight();

        }
    } else if (event->key() == Qt::Key::Key_A) {
        if (checkMovement(player1->horizontalIndex - 1,
                          player1->verticalIndex)) {
            player1->moveToLeft();

        }
    } else if (event->key() == Qt::Key::Key_W) {
        if (checkMovement(player1->horizontalIndex, player1->verticalIndex - 1)) {
            player1->moveToUp();
        }
    } else if (event->key() == Qt::Key::Key_S) {
        if (checkMovement(player1->horizontalIndex, player1->verticalIndex + 1)) {
            player1->moveToDown();
        }
    }
    //player2 movement
    if (event->key() == Qt::Key::Key_Right) {
        if (checkMovement(player2->horizontalIndex + 1,
                          player2->verticalIndex))
            player2->moveToRight();
    } else if (event->key() == Qt::Key::Key_Left) {
        if (checkMovement(player2->horizontalIndex - 1,
                          player2->verticalIndex))
            player2->moveToLeft();
    } else if (event->key() == Qt::Key::Key_Up) {
        if (checkMovement(player2->horizontalIndex, player2->verticalIndex - 1))
            player2->moveToUp();
    } else if (event->key() == Qt::Key::Key_Down) {
        if (checkMovement(player2->horizontalIndex, player2->verticalIndex + 1))
            player2->moveToDown();
    }
}

bool Game::checkMovement(int horizontalIndex, int verticalIndex) const {
    if (horizontalIndex == 0 || horizontalIndex == numOfWalls - 1 || verticalIndex == 0 ||
        verticalIndex == numOfWalls - 1 || (verticalIndex % 2 == 0 && horizontalIndex % 2 == 0)) {
        return false;
    }
    for (int k = 0; k < numOfBoxes; ++k) {
        if (boxes.at(k)->horizontalIndex == horizontalIndex && boxes.at(k)->verticalIndex == verticalIndex)
            return false;
    }
    return true;
}