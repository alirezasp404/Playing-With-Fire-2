//
// Created by Reza on 7/12/2022.
//

#include "Label.h"
#include <QFont>
#include <QTextDocument>

Label::Label() {
    setDefaultTextColor(QColor("#585858"));
    QFont font;
    font.setPixelSize(23);
    font.setBold(true);
    setFont(font);
    document()->setDocumentMargin(10);

};