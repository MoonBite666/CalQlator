

#include "resultbar.h"


ResultBar::ResultBar(QWidget *parent) : QWidget(parent) {
    resultLabel = new QLabel(this);
    resultLabel->setText("0");
    resultLabel->setAlignment(Qt::AlignRight);
    resultLabel->setFixedHeight(30);
    resultLabel->setStyleSheet("font-size: 13px");
    resultLabel->resize(440, 30);
}

ResultBar::~ResultBar() = default;

void ResultBar::textChanged(const QString &text) {
    qDebug() << "Result:" << text;
}