

#include "Player.h"

Player::Player(const QString& image, int width, int height, int x, int y) {
    QPixmap pixmap(image);
    pixmap = pixmap.scaled(3 * width / 8, 3 * width / 8);
    setPixmap(pixmap);
    horizontalMovement = width;
    verticalMovement = height;
    positionX = x;
    positionY = y;
    setPos(x, y);
    Image=image;
}


void Player::moveToRight() {
    if (checkHorizontalMovement(positionX + horizontalMovement)) {
        positionX = positionX + horizontalMovement;
        setPos(positionX, positionY);
    }
}

void Player::moveToLeft() {
    if (checkHorizontalMovement(positionX - horizontalMovement)) {
        positionX = positionX - horizontalMovement;
        setPos(positionX, positionY);
    }
}

void Player::moveToUp() {
    if(checkVerticalMovement(positionY - verticalMovement)) {
        positionY = positionY - verticalMovement;
        setPos(positionX, positionY);
    }
}

void Player::moveToDown() {
    if(checkVerticalMovement(positionY + verticalMovement)) {
        positionY = positionY + verticalMovement;
        setPos(positionX, positionY);
    }
}

bool Player::checkHorizontalMovement(int position) const {
    if (position >= horizontalMovement * 14 || position <= horizontalMovement)
        return false;
    return true;
}bool Player::checkVerticalMovement(int position) const {
    if (position >= verticalMovement * 14 || position <= verticalMovement)
        return false;
    return true;
}
QString Player:: getImage(){
    return Image;
};

