
#include "Label.h"
#include <QFont>
#include <QTextDocument>

Label::Label(): QGraphicsTextItem() {
    setDefaultTextColor(QColor("white"));
    QFont font;
    font.setPixelSize(23);
    font.setBold(true);
    setFont(font);
    document()->setDocumentMargin(10);

}
Label::Label(int a,QString b="white"): QGraphicsTextItem() {
    setDefaultTextColor(QColor(b));
    QFont font;
    font.setPixelSize(a);
    font.setBold(true);
    setFont(font);
    document()->setDocumentMargin(10);

}