
#include "numpad.h"


Numpad::Numpad(QWidget *parent) : QFrame(parent) {
    // this->setFixedHeight(250);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    auto *layout = new QGridLayout(this);
    layout->setSpacing(5);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            auto *button = new SquareButton(QString::number(i*3 + j + 1), this);
            buttons.append(button);
            layout->addWidget(button, i, j);
            connect(button, &SquareButton::buttonClicked, this, &Numpad::buttonClicked);
        }
    }

    auto *button0 = new SquareButton("0", this);
    buttons.append(button0);
    layout->addWidget(button0, 3, 0, 1, 2);
    connect(button0, &SquareButton::buttonClicked, this, &Numpad::buttonClicked);

    auto *buttonDot = new SquareButton(".", this);
    buttons.append(buttonDot);
    layout->addWidget(buttonDot, 3, 2);
    connect(buttonDot, &SquareButton::buttonClicked, this, &Numpad::buttonClicked);

    layout->setContentsMargins(0, 0, 0, 0);

}

Numpad::~Numpad() = default;

void Numpad::buttonClicked(const QString &text) {
    qDebug() << text;
}