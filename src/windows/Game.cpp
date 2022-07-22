
#include "Game.h"
#include<ctime>

Game::Game(const QString &name1, const QString &name2, const QString &lives, QString setting[3])
        : QGraphicsView(), numOfWalls(15) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QImage(":/images/gameBG"));
    setScene(scene);
    this->numOfBoxes = setting[0].toInt();
    horizontalMovement = width() / numOfWalls;
    verticalMovement = height() / numOfWalls;
    timer = new QTimer;
    addWalls();
    addBoxes();
    addPlayers(name1, name2, lives.toInt(), setting[2].toInt(), setting[1].toInt());
    showDetails();
    addBomb();
}

Game::~Game() {
    delete scene;
    for (int i = 0; i < numOfWalls; ++i)
        delete walls.at(i);
    for (int i = 0; i < boxes.size(); ++i)
        delete boxes.at(i);

    for (int i = 0; i < explosion.size(); ++i)
        delete explosion.at(i);
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
    delete timer;
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
        } else
            k--;
    }
    connect(timer, &QTimer::timeout, this, &Game::addBoxesOnTimer);
    timer->start(30);


}
bool Game::checkBoxPosition(int i, int j) const {
    for (int k = 0; k < boxes.size() - 1; k++) {
        if (boxes.at(k)->horizontalIndex == i && boxes.at(k)->verticalIndex == j)
            return false;
    }
    return true;
}

void Game::addBoxesOnTimer() {
    scene->addItem(boxes.at(boxIndex++));
    if (boxIndex == numOfBoxes) {
        disconnect(timer, &QTimer::timeout, this, &Game::addBoxesOnTimer);
        timer->stop();
    }
}
void Game::addBomb() {
    bomb1 = new Bomb(horizontalMovement, verticalMovement);
    bomb2 = new Bomb(horizontalMovement, verticalMovement);
    for (int i = 0; i < (8 * Player::bombRadius + 2); ++i)
        explosion.append(new Explosion(horizontalMovement, verticalMovement));
}

void Game::addPlayers(QString playerName1, QString playerName2, int numberOfLives, int bombRadius, int speed) {
    player1 = new Player(":/images/player1", horizontalMovement, verticalMovement, 1,
                         1);
    player2 = new Player(":/images/player2", horizontalMovement, verticalMovement, numOfWalls - 2,
                         numOfWalls - 2);
    player1->name = std::move(playerName1);
    player2->name = std::move(playerName2);
    player1->lifeCount = numberOfLives;
    player2->lifeCount = numberOfLives;
    Player::bombRadius = bombRadius;
    Player::speed = speed;
    scene->addItem(player1);
    scene->addItem(player2);
}
void Game::showDetails() {
    name1 = new Label(25,"red");
    name1->setPlainText(player1->name);
    scene->addItem(name1);
    name1->setPos(width() / numOfWalls, width() / (numOfWalls * 25));

    name2 = new Label(25,"black");
    name2->setPlainText(player2->name);
    scene->addItem(name2);
    name2->setPos(9 * width() / numOfWalls, width() / (numOfWalls * 25));

    exitButton = new Button(width() / numOfWalls, height() / numOfWalls);
    exitButton->setPlainText("  EXIT");
    scene->addItem(exitButton);
    exitButton->setPos(7 * width() / numOfWalls, width() / (numOfWalls * 25));
    connect(exitButton, &Button::press, this, &Game::exit);

    score1 = new Label(25,"red");
    score1->setPlainText("Score :\t       " + QString::number(player1->score));
    scene->addItem(score1);
    score1->setPos(2 * width() / numOfWalls, width() / (numOfWalls * 25));

    life1 = new Label(25,"red");
    life1->setPlainText("Life :\t        " + QString::number(player1->lifeCount));
    scene->addItem(life1);
    life1->setPos(4 * width() / numOfWalls, width() / (numOfWalls * 25));

    score2 = new Label(25,"black");
    score2->setPlainText("Score :\t       " + QString::number(player2->score));
    scene->addItem(score2);
    score2->setPos(10 * width() / numOfWalls, width() / (numOfWalls * 25));

    life2 = new Label(25,"black");
    life2->setPlainText("Life :\t        " + QString::number(player2->lifeCount));
    scene->addItem(life2);
    life2->setPos(12 * width() / numOfWalls, width() / (numOfWalls * 25));
}
void Game::exit() {
    timer->stop();
        if (player1->score > player2->score)
            (new Final(player1,"red", player2,"black"))->show();
        else if (player2->score > player1->score)
            (new Final(player2,"black", player1,"red"))->show();
    close();
}

void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    //player1 movement
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
                connect(bomb1->bombTimer, &QTimer::timeout, this, &Game::explodeTime1);
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
                connect(bomb2->bombTimer, &QTimer::timeout, this, &Game::explodeTime2);
                playersMovement(player2, 'B', bomb2);
            }
        }
    }
}

void Game::playersMovement(Player *player, char direction, Bomb *bomb) {
    for (int i = 0; i < Player::speed; ++i) {
        if (direction == 'R') {
            if (checkMovement(player->horizontalIndex + 1,
                              player->verticalIndex) == -2)
                player->moveToRight();
        } else if (direction == 'L') {
            if (checkMovement(player->horizontalIndex - 1,
                              player->verticalIndex) == -2)
                player->moveToLeft();
        } else if (direction == 'U') {
            if (checkMovement(player->horizontalIndex, player->verticalIndex - 1) == -2)
                player->moveToUp();
        } else if (direction == 'D') {
            if (checkMovement(player->horizontalIndex, player->verticalIndex + 1) == -2)
                player->moveToDown();
        } else if (direction == 'B') {
            bomb->horizontalIndex = player->horizontalIndex;
            bomb->verticalIndex = player->verticalIndex;
            bomb->setPos(bomb->horizontalIndex * horizontalMovement + horizontalMovement / 4,
                         bomb->verticalIndex * verticalMovement + verticalMovement / 4);
            scene->addItem(bomb);
            bomb->bombTimer->start(2000 / Player::speed);
            bomb->bombExploded = false;
            break;
        }
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
        connect(bomb2->explosionTimer, &QTimer::timeout, this, &Game::removeExplosion2);
        bomb2->explosionIndex=explosion.size()/2;
        removeBoxes(bomb2->horizontalIndex, bomb2->verticalIndex, player2, player1,bomb2);
    }
    bomb2->bombTimer->stop();
}

void Game::explodeTime1() {
    if (!bomb1->bombExploded) {
        scene->removeItem(bomb1);
        bomb1->bombExploded = true;
        connect(bomb1->explosionTimer, &QTimer::timeout, this, &Game::removeExplosion1);
        bomb1->explosionIndex=0;
        removeBoxes(bomb1->horizontalIndex, bomb1->verticalIndex, player1, player2,bomb1);
    }
    bomb1->bombTimer->stop();
}

void Game::removeBoxes(int horizontalIndex, int verticalIndex, Player *player, Player *enemy,Bomb* bomb) {
    //add explosion to bomb position
    explosion.at(bomb->explosionIndex)->setPos(horizontalIndex * horizontalMovement + horizontalMovement / 4,
                                         verticalIndex * verticalMovement + verticalMovement / 4);
    scene->addItem(explosion.at(bomb->explosionIndex++));
    if (player->horizontalIndex == horizontalIndex && player->verticalIndex == verticalIndex)
        player->lifeCount--;
    if (enemy->horizontalIndex == horizontalIndex && enemy->verticalIndex == verticalIndex) {
        enemy->lifeCount--;
        player->score += 50;
    }
    int position[4][2]{{-1, 0},//left
                       {1,  0},//right
                       {0,  -1},//up
                       {0,  1}};//down
    for (int j = 0; j < 4; ++j) {
        int hIndex = horizontalIndex;
        int vIndex = verticalIndex;
        for (int i = 0; i < Player::bombRadius; ++i) {
            hIndex += position[j][0];
            vIndex += position[j][1];
            //checking  the position to find out it's box or wall or nothing
            int check = checkMovement(hIndex, vIndex);
            if (check == -1)
                break;
            else if (check == -2) {
                explosion.at(bomb->explosionIndex)->setPos(hIndex * horizontalMovement + horizontalMovement / 4,
                                                     vIndex * verticalMovement + verticalMovement / 4);
                scene->addItem(explosion.at(bomb->explosionIndex++));
            } else if (check >= 0) {
                explosion.at(bomb->explosionIndex)->setPos(hIndex * horizontalMovement + horizontalMovement / 4,
                                                     vIndex * verticalMovement + verticalMovement / 4);
                scene->addItem(explosion.at(bomb->explosionIndex++));
                scene->removeItem(boxes.at(check));
                delete boxes.at(check);
                boxes.removeAt(check);
                player->score += 5;
                break;
            }
            if (player->horizontalIndex == hIndex && player->verticalIndex == vIndex)
                player->lifeCount--;
            if (enemy->horizontalIndex == hIndex && enemy->verticalIndex == vIndex) {
                enemy->lifeCount--;
                player->score += 50;
            }
        }
    }
    bomb->explosionTimer->start(800/Player::speed);
    //update score and life
    score1->setPlainText("Score :\t       " + QString::number(player1->score));
    life1->setPlainText("Life :\t        " + QString::number(player1->lifeCount));
    score2->setPlainText("Score :\t       " + QString::number(player2->score));
    life2->setPlainText("Life :\t        " + QString::number(player2->lifeCount));
    if (player1->lifeCount == 0 || player2->lifeCount == 0) {
        connect(timer, &QTimer::timeout, this, &Game::exit);
        timer->start(1000);
    }

}

void Game::removeExplosion1() {
    bomb1->explosionTimer->stop();
    disconnect(bomb1->explosionTimer, &QTimer::timeout, this, &Game::removeExplosion1);
    for (int i = 0; i < bomb1->explosionIndex; ++i)
        scene->removeItem(explosion.at(i));
}
void Game::removeExplosion2() {
    bomb2->explosionTimer->stop();
    disconnect(bomb2->explosionTimer, &QTimer::timeout, this, &Game::removeExplosion2);
    for (int i = explosion.size()/2; i < bomb2->explosionIndex; ++i)
        scene->removeItem(explosion.at(i));
}







