

#include "Home.h"
#include "../windows/Game.h"

Home::Home(QString numOfBoxes, QString gameSpeed) {
    QString line1, line2, line3;
    QFile file("test.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out >> line1 >> line2 >> line3;
    }
    file.close();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QImage(":/images/homeBG"));
    setScene(scene);
    this->gameSpeed = gameSpeed;
    this->numOfBoxes = numOfBoxes;

    back= new Background();
    scene->addItem(back);

    firstLabel = new Label();
    firstLabel->setPlainText("First Player Name:");
    scene->addItem(firstLabel);
    firstLabel->setPos(width() / 2.33, height() / 2.07);

    secondLabel = new Label();
    secondLabel->setPlainText("Second Player Name:");
    scene->addItem(secondLabel);
    secondLabel->setPos(width() / 2.33, height() / 1.75);

    thirdLabel = new Label();
    thirdLabel->setPlainText("Number Of Lives:");
    scene->addItem(thirdLabel);
    thirdLabel->setPos(width() / 2.33, height() / 2.55);

    numberOfLife = new TextField(200, 55);//textfield3
    numberOfLife->setPlainText(line3);
    scene->addItem(numberOfLife);
    numberOfLife->setPos(width() / 2.3, height() / 2.3);

    textField1 = new TextField(200, 55);
    textField1->setPlainText(line1);
    scene->addItem(textField1);
    textField1->setPos(width() / 2.3, height() / 1.9);

    textField2 = new TextField(200, 55);
    textField2->setPlainText(line2);
    scene->addItem(textField2);
    textField2->setPos(width() / 2.3, height() / 1.62);

    button = new Button(200, 150);
    button->setPlainText("         START");
    scene->addItem(button);
    button->setPos(width() / 2.3, height() / 1.42);

    connect(button, &Button::press, this, &Home::start);
}

Home::~Home() {
    delete firstLabel;
    delete secondLabel;
    delete textField1;
    delete textField2;
    delete thirdLabel;
    delete numberOfLife;
    delete button;
    delete scene;
    delete back;

}

void Home::start() {
    auto name1 = textField1->toPlainText();
    auto name2 = textField2->toPlainText();
    auto numLives = numberOfLife->toPlainText();
    writeFile(textField1->toPlainText(), textField2->toPlainText(), numberOfLife->toPlainText());
    (new Game(name1, name2, numLives, numOfBoxes,gameSpeed))->show();
    close();
}

void Home::writeFile(const QString &name1, const QString &name2, const QString &lives) {

    QFile file("test.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << name1 << "\n" << name2 << "\n" << lives;
    }
    file.close();
}
