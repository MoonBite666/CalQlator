#include "squarebutton.h"

SquareButton::SquareButton(const QString &text, QWidget *parent) : QPushButton(text,parent) {
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void SquareButton::mousePressEvent(QMouseEvent *event) {
    QPushButton::mousePressEvent(event);
    emit buttonClicked(this->text());
}


// void SquareButton::resizeEvent(QResizeEvent *event) {
//     int side = qMin(event->size().width(), event->size().height());
//     setFixedSize(side, side);
// }
