#include <QApplication>
#include <QPushButton>
#include "src/windows/start.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    start Start;
    Start.show();
    return QApplication::exec();
}