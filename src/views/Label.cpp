
#include "Label.h"
#include <QFont>
#include <QTextDocument>

Label::Label(): QGraphicsTextItem() {
    setDefaultTextColor(QColor("#a8a002"));
    QFont font;
    font.setPixelSize(23);
    font.setBold(true);
    setFont(font);
    document()->setDocumentMargin(10);

}