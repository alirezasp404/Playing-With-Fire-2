#include <QApplication>
#include <QPushButton>
#include "src/windows/Home.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Home home;
    home.show();
    return QApplication::exec();
}
