

#include "Player.h"
Player::Player(const QString& image, int width, int height, int hIndex, int vIndex):horizontalIndex(hIndex),verticalIndex(vIndex) {
    QPixmap pixmap(image);
    pixmap = pixmap.scaled(3 * width / 8, 3 * width / 8);
    setPixmap(pixmap);
    horizontalMovement = width;
    verticalMovement = height;
    setPos(hIndex*horizontalMovement+horizontalMovement/4, vIndex*verticalMovement+verticalMovement/4);
}


void Player::moveToRight() {
        setPos((++horizontalIndex)*horizontalMovement+horizontalMovement/4, verticalIndex*verticalMovement+verticalMovement/4);
    }

void Player::moveToLeft() {
    setPos((--horizontalIndex)*horizontalMovement+horizontalMovement/4, verticalIndex*verticalMovement+verticalMovement/4);
    }

void Player::moveToUp() {
    setPos(horizontalIndex*horizontalMovement+horizontalMovement/4, (--verticalIndex)*verticalMovement+verticalMovement/4);
    }

void Player::moveToDown() {
    setPos(horizontalIndex*horizontalMovement+horizontalMovement/4, (++verticalIndex)*verticalMovement+verticalMovement/4);
    }
int Player::bombRadius;