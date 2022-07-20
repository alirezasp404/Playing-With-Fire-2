
#include "Game.h"
#include<ctime>

Game::Game(const QString &name1, const QString &name2, QString lives, const QString &numberOfBoxes,QString gameSpeed)
        : QGraphicsView(), numOfWalls(15) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
//    scene->setSceneRect(0,0,width(),height());
    setScene(scene);
    Player::speed=gameSpeed.toInt();
    this->numOfBoxes = numberOfBoxes.toInt();
    numberOfLives = lives.toInt();
    horizontalMovement = width() / numOfWalls;
    verticalMovement = height() / numOfWalls;
    addWalls();
    addBoxes();
    addPlayers();
    player1->name = name1;
    player2->name = name2;
    player1->lifeCount = numberOfLives;
    player2->lifeCount = numberOfLives;
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
    delete score1;
    delete score2;
    delete life1;
    delete life2;
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
    int timer = 0;
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
            connect(boxes.at(k)->timer, &QTimer::timeout, this, &Game::addBoxesOnTimer);
            boxes.at(k)->timer->start(timer);
            timer += 50;
        } else
            k--;
    }
}

void Game::addBoxesOnTimer() {
    scene->addItem(boxes.at(boxIndex));
    delete boxes.at(boxIndex++)->timer;
}
bool Game::checkBoxPosition(int i, int j) const {
    for (int k = 0; k < boxes.size() - 1; k++) {
        if (boxes.at(k)->horizontalIndex == i && boxes.at(k)->verticalIndex == j)
            return false;
    }
    return true;
}

void Game::showDetails() {
    name1 = new Label;
    name1->setPlainText(player1->name);
    scene->addItem(name1);
    name1->setPos(width() / numOfWalls, width() / (numOfWalls * 25));

    name2 = new Label;
    name2->setPlainText(player2->name);
    scene->addItem(name2);
    name2->setPos(9 * width() / numOfWalls, width() / (numOfWalls * 25));

    exitButton = new Button(width() / numOfWalls, height() / numOfWalls);
    exitButton->setPlainText("   EXIT");
    scene->addItem(exitButton);
    exitButton->setPos(7 * width() / numOfWalls, width() / (numOfWalls * 25));
    connect(exitButton, &Button::press, this, &Game::exit);

    score1 = new Label;
    score1->setPlainText("Score :\t"+QString::number(player1->score));
    scene->addItem(score1);
    score1->setPos(2*width() / numOfWalls, width() / (numOfWalls * 25));

    life1 = new Label;
    life1->setPlainText("Life :\t"+QString::number(player1->lifeCount));
    scene->addItem(life1);
    life1->setPos(4*width() / numOfWalls, width() / (numOfWalls * 25));

    score2 = new Label;
    score2->setPlainText("Score :\t"+QString::number(player2->score));
    scene->addItem(score2);
    score2->setPos(10*width() / numOfWalls, width() / (numOfWalls * 25));

    life2 = new Label;
    life2->setPlainText("Life :\t"+QString::number(player2->lifeCount));
    scene->addItem(life2);
    life2->setPos(12*width() / numOfWalls, width() / (numOfWalls * 25));
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
            (new Final(player2, player1))->show();
    }
    close();
}

void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    //player1 movement
    if (player1->lifeCount != 0 && player2->lifeCount != 0) {
        if (boxIndex == numOfBoxes) {
            if (event->key() == Qt::Key::Key_D)
                playersMovement(player1, 'R');
            else if (event->key() == Qt::Key::Key_A)
                playersMovement(player1, 'L');
            else if (event->key() == Qt::Key::Key_W)
                playersMovement(player1, 'U');
            else if (event->key() == Qt::Key::Key_S)
                playersMovement(player1, 'D');
            else if (event->key() == Qt::Key::Key_E) {
                if (bomb1->bombExploded) {
                    connect(bomb1->timer, &QTimer::timeout, this, &Game::explodeTime1);
                    playersMovement(player1, 'B', bomb1);
                }
            }
            //player2 movement
            if (event->key() == Qt::Key::Key_Right)
                playersMovement(player2, 'R');
            else if (event->key() == Qt::Key::Key_Left)
                playersMovement(player2, 'L');
            else if (event->key() == Qt::Key::Key_Up)
                playersMovement(player2, 'U');
            else if (event->key() == Qt::Key::Key_Down)
                playersMovement(player2, 'D');
            else if (event->key() == Qt::Key::Key_Shift) {
                if (bomb2->bombExploded) {
                    connect(bomb2->timer, &QTimer::timeout, this, &Game::explodeTime2);
                    playersMovement(player2, 'B',bomb2);
                }
            }
        }
    } else
        exit();
}
void Game::playersMovement(Player *player, char direction, Bomb *bomb) {
    if (direction == 'R') {
        for (int i = 0; i < Player::speed; ++i) {
            if (checkMovement(player->horizontalIndex + 1,
                              player->verticalIndex) == -2)
                player->moveToRight();
        }
    } else if (direction == 'L') {
        for (int i = 0; i < Player::speed; ++i) {
            if (checkMovement(player->horizontalIndex - 1,
                              player->verticalIndex) == -2)
                player->moveToLeft();
        }
    } else if (direction == 'U') {
        for (int i = 0; i < Player::speed; ++i) {
            if (checkMovement(player->horizontalIndex, player->verticalIndex - 1) == -2)
                player->moveToUp();
        }
    } else if (direction == 'D') {
        for (int i = 0; i < Player::speed; ++i) {
            if (checkMovement(player->horizontalIndex, player->verticalIndex + 1) == -2)
                player->moveToDown();
        }
    } else if (direction == 'B') {
        bomb->horizontalIndex = player->horizontalIndex;
        bomb->verticalIndex = player->verticalIndex;
        bomb->setPos(bomb->horizontalIndex * horizontalMovement + horizontalMovement / 4,
                     bomb->verticalIndex * verticalMovement + verticalMovement / 4);
        scene->addItem(bomb);
        bomb->timer->start(2000);
        bomb->bombExploded = false;
    }
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
        removeBoxes(bomb2->horizontalIndex, bomb2->verticalIndex, player2, player1);
    }
}

void Game::explodeTime1() {
    if (!bomb1->bombExploded) {
        scene->removeItem(bomb1);
        bomb1->bombExploded = true;
        removeBoxes(bomb1->horizontalIndex, bomb1->verticalIndex, player1, player2);
    }
}

void Game::removeBoxes(int hIndex, int vIndex, Player *player, Player *enemy) {
    removeLeftBoxes(hIndex, vIndex, player, enemy);
    removeRightBoxes(hIndex, vIndex, player, enemy);
    removeUpBoxes(hIndex, vIndex, player, enemy);
    removeDownBoxes(hIndex, vIndex, player, enemy);
    if (player->horizontalIndex == hIndex && player->verticalIndex == vIndex)
        player->lifeCount--;
    if (enemy->horizontalIndex == hIndex && enemy->verticalIndex == vIndex) {
        enemy->lifeCount--;
        player->score += 50;
    }
    score1->setPlainText("Score :\t"+QString::number(player1->score));
    score2->setPlainText("Score :\t"+QString::number(player2->score));
    life1->setPlainText("Life :\t"+QString::number(player1->lifeCount));
    life2->setPlainText("Life :\t"+QString::number(player2->lifeCount));

}

void Game::removeLeftBoxes(int hIndex, int vIndex, Player *player, Player *enemy, bool checkAgain) {
    int check = checkMovement(hIndex - 1, vIndex);
    if (check == -2 && !checkAgain) {
        removeLeftBoxes(hIndex - 1, vIndex, player, enemy, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        player->score += 5;
    }
    if (player->horizontalIndex == hIndex - 1 && player->verticalIndex == vIndex)
        player->lifeCount--;
    if (enemy->horizontalIndex == hIndex - 1 && enemy->verticalIndex == vIndex) {
        enemy->lifeCount--;
        player->score += 50;
    }
}

void Game::removeRightBoxes(int hIndex, int vIndex, Player *player, Player *enemy, bool checkAgain) {
    int check = checkMovement(hIndex + 1, vIndex);
    if (check == -2 && !checkAgain) {
        removeRightBoxes(hIndex + 1, vIndex, player, enemy, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        player->score += 5;
    }
    if (player->horizontalIndex == hIndex + 1 && player->verticalIndex == vIndex)
        player->lifeCount--;
    if (enemy->horizontalIndex == hIndex + 1 && enemy->verticalIndex == vIndex) {
        enemy->lifeCount--;
        player->score += 50;
    }
}

void Game::removeUpBoxes(int hIndex, int vIndex, Player *player, Player *enemy, bool checkAgain) {
    int check = checkMovement(hIndex, vIndex - 1);
    if (check == -2 && !checkAgain) {
        removeUpBoxes(hIndex, vIndex - 1, player, enemy, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        player->score += 5;
    }
    if (player->horizontalIndex == hIndex && player->verticalIndex == vIndex - 1)
        player->lifeCount--;
    if (enemy->horizontalIndex == hIndex && enemy->verticalIndex == vIndex - 1) {
        enemy->lifeCount--;
        player->score += 50;
    }
}

void Game::removeDownBoxes(int hIndex, int vIndex, Player *player, Player *enemy, bool checkAgain) {
    int check = checkMovement(hIndex, vIndex + 1);
    if (check == -2 && !checkAgain) {
        removeDownBoxes(hIndex, vIndex + 1, player, enemy, true);
    } else if (check >= 0) {
        scene->removeItem(boxes.at(check));
        delete boxes.at(check);
        boxes.removeAt(check);
        player->score += 5;
    }
    if (player->horizontalIndex == hIndex && player->verticalIndex == vIndex + 1)
        player->lifeCount--;
    if (enemy->horizontalIndex == hIndex && enemy->verticalIndex == vIndex + 1) {
        enemy->lifeCount--;
        player->score += 50;
    }
}





