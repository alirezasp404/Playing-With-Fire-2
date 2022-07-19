
#include "Game.h"
#include<ctime>

Game::Game(const QString &name1, const QString &name2, QString numberOfLives, const QString& numberOfBoxes)
        : QGraphicsView(), numOfWalls(15) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
    setScene(scene);
    this->numOfBoxes = numberOfBoxes.toInt();
    this->numberOfLives = numberOfLives.toInt();
    horizontalMovement = width() / numOfWalls;
    verticalMovement = height() / numOfWalls;
    addWalls();
    addBoxes();
    addPlayers();
    player1->name = name1;
    player2->name = name2;
    player1->lifeCount=numberOfLives.toInt();
    player2->lifeCount=numberOfLives.toInt();
    showDetails();
    bomb1 = new Bomb(horizontalMovement, verticalMovement, ":/images/bomb1");
    bomb2 = new Bomb(horizontalMovement, verticalMovement, ":/images/bomb2");
}

Game::~Game() {
    delete scene;
    for (int i = 0; i < numOfWalls; ++i) {
        delete walls.at(i);
    }
    for (int i = 0; i < boxes.size(); ++i) {
        delete boxes.at(i);
    }
    delete name1;
    delete name2;
    delete player1;
    delete player2;
    delete exitButton;
    delete bomb1;
    delete bomb2;
}

void Game::addWalls() {
    int wallIndex = 0;
    for (int i = 0; i < numOfWalls; ++i) {
        for (int j = 0; j < numOfWalls; ++j) {
            if (i != 0 && i != numOfWalls - 1 && j != 0 && j != numOfWalls - 1 && (j % 2 != 0 || i % 2 != 0))
                continue;
            walls.append(new Wall(horizontalMovement, verticalMovement, i, j));
            scene->addItem(walls.at(wallIndex));
            wallIndex++;
        }
    }
}

void Game::addBoxes() {
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
        if (boxIsNotNearPlayer && boxIsNotOnWall && checkBoxPosition(i, j)) {
            boxes.append(new class Box(horizontalMovement, verticalMovement, i, j));
            scene->addItem(boxes.at(k));
        } else
            k--;
    }
}

bool Game::checkBoxPosition(int i, int j) const {
    for (int k = 0; k < boxes.size() - 1; k++) {
        if (boxes.at(k)->horizontalIndex == i && boxes.at(k)->verticalIndex == j)
            return false;
    }
    return true;
}

void Game::showDetails() {
    name1 = new Button(2 * width() / numOfWalls, height() / numOfWalls);
    name1->setPlainText(player1->name);
    scene->addItem(name1);
    name1->setPos(width() / numOfWalls, width() / (numOfWalls * 25));

    name2 = new Button(2 * width() / numOfWalls, height() / numOfWalls);
    name2->setPlainText(player2->name);
    scene->addItem(name2);
    name2->setPos(12 * width() / numOfWalls, width() / (numOfWalls * 25));

    exitButton = new Button(width() / numOfWalls, height() / numOfWalls);
    exitButton->setPlainText("   EXIT");
    scene->addItem(exitButton);
    exitButton->setPos(7 * width() / numOfWalls, width() / (numOfWalls * 25));
    connect(exitButton, &Button::press, this, &Game::exit);

}

void Game::addPlayers() {
    player1 = new Player(":/images/player1", horizontalMovement, verticalMovement, 1,
                         1);
    player2 = new Player(":/images/player2", horizontalMovement, verticalMovement, numOfWalls - 2,
                         numOfWalls - 2);
    scene->addItem(player1);
    scene->addItem(player2);
}

void Game::exit() {
    if (player2->lifeCount == 0)
        (new Final(player1, player2))->show();
    else if (player1->lifeCount == 0)
        (new Final(player2, player1))->show();
    else {
        if (player1->score > player2->score)
            (new Final(player1, player2))->show();
        else if (player2->score > player1->score)
            (new Final( player2,player1))->show();
    }
    close();
}

void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    //player1 movement
    if (player1->lifeCount != 0 && player1->lifeCount != 0) {
        if (event->key() == Qt::Key::Key_D) {
            if (checkMovement(player1->horizontalIndex + 1,
                              player1->verticalIndex) == -2) {
                player1->moveToRight();
            }
        } else if (event->key() == Qt::Key::Key_A) {
            if (checkMovement(player1->horizontalIndex - 1,
                              player1->verticalIndex) == -2) {
                player1->moveToLeft();

            }
        } else if (event->key() == Qt::Key::Key_W) {
            if (checkMovement(player1->horizontalIndex, player1->verticalIndex - 1) == -2) {
                player1->moveToUp();
            }
        } else if (event->key() == Qt::Key::Key_S) {
            if (checkMovement(player1->horizontalIndex, player1->verticalIndex + 1) == -2) {
                player1->moveToDown();
            }
        } else if (event->key() == Qt::Key::Key_E) {
            if (bomb1->bombExploded) {
                bomb1->horizontalIndex = player1->horizontalIndex;
                bomb1->verticalIndex = player1->verticalIndex;
                bomb1->setPos(bomb1->horizontalIndex * horizontalMovement + horizontalMovement / 4,
                              bomb1->verticalIndex * verticalMovement + verticalMovement / 4);
                scene->addItem(bomb1);
                connect(bomb1->timer, &QTimer::timeout, this, &Game::explodeTime1);
                bomb1->timer->start(2000);
                bomb1->bombExploded = false;
            }
        }
        //player2 movement
        if (event->key() == Qt::Key::Key_Right) {
            if (checkMovement(player2->horizontalIndex + 1,
                              player2->verticalIndex) == -2)
                player2->moveToRight();
        } else if (event->key() == Qt::Key::Key_Left) {
            if (checkMovement(player2->horizontalIndex - 1,
                              player2->verticalIndex) == -2)
                player2->moveToLeft();
        } else if (event->key() == Qt::Key::Key_Up) {
            if (checkMovement(player2->horizontalIndex, player2->verticalIndex - 1) == -2)
                player2->moveToUp();
        } else if (event->key() == Qt::Key::Key_Down) {
            if (checkMovement(player2->horizontalIndex, player2->verticalIndex + 1) == -2)
                player2->moveToDown();
        } else if (event->key() == Qt::Key::Key_Shift) {
            if (bomb2->bombExploded) {
                bomb2->horizontalIndex = player2->horizontalIndex;
                bomb2->verticalIndex = player2->verticalIndex;
                bomb2->setPos(bomb2->horizontalIndex * horizontalMovement + horizontalMovement / 4,
                              bomb2->verticalIndex * verticalMovement + verticalMovement / 4);
                scene->addItem(bomb2);
                connect(bomb2->timer, &QTimer::timeout, this, &Game::explodeTime2);
                bomb2->timer->start(2000);
                bomb2->bombExploded = false;
            }
        }
    } else
        exit();
}

int Game::checkMovement(int horizontalIndex, int verticalIndex) const {
    if (horizontalIndex == 0 || horizontalIndex == numOfWalls - 1 || verticalIndex == 0 ||
        verticalIndex == numOfWalls - 1 || (verticalIndex % 2 == 0 && horizontalIndex % 2 == 0)) {
        return -1;
    }
    for (int k = 0; k < boxes.size(); ++k) {
        if (boxes.at(k)->horizontalIndex == horizontalIndex && boxes.at(k)->verticalIndex == verticalIndex)
            return k;
    }
    return -2;
}

void Game::explodeTime2() {
    if (!bomb2->bombExploded) {
        scene->removeItem(bomb2);
        bomb2->bombExploded = true;
        if (player2->horizontalIndex == bomb2->horizontalIndex && player2->verticalIndex == bomb2->horizontalIndex)
            player2->lifeCount--;
        if (player1->horizontalIndex == bomb2->horizontalIndex && player1->verticalIndex == bomb2->horizontalIndex) {
            player1->lifeCount--;
            player2->score += 50;
        }
        removeBoxes(bomb2->horizontalIndex, bomb2->verticalIndex, player2->score);
    }
}

void Game::explodeTime1() {
    if (!bomb1->bombExploded) {
        scene->removeItem(bomb1);
        bomb1->bombExploded = true;
        if (player1->horizontalIndex == bomb1->horizontalIndex && player1->verticalIndex == bomb1->horizontalIndex)
            player1->lifeCount--;
        if (player2->horizontalIndex == bomb1->horizontalIndex && player2->verticalIndex == bomb1->horizontalIndex) {
            player2->lifeCount--;
            player1->score += 50;
        }
        removeBoxes(bomb1->horizontalIndex, bomb1->verticalIndex, player1->score);
    }
}

void Game::removeBoxes(int hIndex, int vIndex, int &score) {
    removeLeftBoxes(hIndex, vIndex, score);
    removeRightBoxes(hIndex, vIndex, score);
    removeUpBoxes(hIndex, vIndex, score);
    removeDownBoxes(hIndex, vIndex, score);
}

void Game::removeLeftBoxes(int hIndex, int vIndex, int &score, bool checkAgain) {
    int check = checkMovement(hIndex - 1, vIndex);
    if (check == -2 && !checkAgain) {
        removeLeftBoxes(hIndex - 1, vIndex, score, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        score += 5;
    }
}

void Game::removeRightBoxes(int hIndex, int vIndex, int &score, bool checkAgain) {
    int check = checkMovement(hIndex + 1, vIndex);
    if (check == -2 && !checkAgain) {
        removeRightBoxes(hIndex + 1, vIndex, score, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        score += 5;
    }
}

void Game::removeUpBoxes(int hIndex, int vIndex, int &score, bool checkAgain) {
    int check = checkMovement(hIndex, vIndex - 1);
    if (check == -2 && !checkAgain) {
        removeUpBoxes(hIndex, vIndex - 1, score, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        score += 5;
    }
}

void Game::removeDownBoxes(int hIndex, int vIndex, int &score, bool checkAgain) {
    int check = checkMovement(hIndex, vIndex + 1);
    if (check == -2 && !checkAgain) {
        removeDownBoxes(hIndex, vIndex + 1, score, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        score += 5;
    }
}



