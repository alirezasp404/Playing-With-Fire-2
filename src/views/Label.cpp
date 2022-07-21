
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
Label::Label(int size,QString color="white"): QGraphicsTextItem() {
    setDefaultTextColor(QColor(color));
    QFont font;
    font.setPixelSize(size);
    font.setBold(true);
    setFont(font);
    document()->setDocumentMargin(10);

}