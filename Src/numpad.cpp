
#include "numpad.h"

Numpad::Numpad(QWidget *parent) : QFrame(parent) {
    // this->setFixedHeight(250);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    auto *layout = new QGridLayout(this);
    layout->setSpacing(5);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            layout->addWidget(createButton(QString::number(i*3 + j + 1)), i, j);
        }
    }

    layout->addWidget(createButton("0"), 3, 0, 1, 2);
    layout->addWidget(createButton("."), 3, 2);
    layout->addWidget(createButton("+"), 0, 3);
    layout->addWidget(createButton("-"), 1, 3);
    layout->addWidget(createButton("×"), 2, 3);
    layout->addWidget(createButton("÷"), 3, 3);

    layout->setContentsMargins(0, 0, 0, 0);

}

Numpad::~Numpad() = default;

SquareButton* Numpad::createButton(const QString &text) {
    auto *button = new SquareButton(text);
    buttons.append(button);
    connect(button, &SquareButton::buttonClicked, this, &Numpad::buttonClicked);
    return button;
}

void Numpad::buttonClicked(const QString &text) {
    emit addText(text);
}