
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