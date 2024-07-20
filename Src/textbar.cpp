
#include "textbar.h"
#include <QVBoxLayout>

TextBar::TextBar(QWidget *parent) : QWidget(parent) {
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter your expression here");
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setStyleSheet("font-size: 30px");
    lineEdit->resize(440, 40);
    connect(lineEdit, &QLineEdit::textChanged, this, &TextBar::textChanged);

    resultLabel = new QLabel(this);
    resultLabel->setText("0");
    resultLabel->setAlignment(Qt::AlignRight);
    resultLabel->setStyleSheet("font-size: 18px");
    resultLabel->resize(440, 20);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(resultLabel);
    layout->setSpacing(5);

    this->setLayout(layout);
}


TextBar::~TextBar() = default;

void TextBar::textChanged(const QString &text) {
    qDebug() << text;
}