
#include "textbar.h"


TextBar::TextBar(QWidget *parent) : QWidget(parent) {
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter your expression here");
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setFixedHeight(50);
    lineEdit->setStyleSheet("font-size: 20px");
    connect(lineEdit, &QLineEdit::textChanged, this, &TextBar::textChanged);
}

TextBar::~TextBar() = default;

void TextBar::textChanged(const QString &text) {
    qDebug() << text;
}