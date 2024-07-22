
#include "textbar.h"
#include "calculate.h"


TextBar::TextBar(QWidget *parent) : QFrame(parent) {
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter your expression...");
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setStyleSheet("font-size: 30px");
    lineEdit->resize(440, 40);
    connect(lineEdit, &QLineEdit::textChanged, this, &TextBar::changeResult);

    resultLabel = new QLabel(this);
    resultLabel->setText("0");
    resultLabel->setAlignment(Qt::AlignRight);
    resultLabel->setStyleSheet("font-size: 18px");
    resultLabel->resize(440, 20);


    auto *layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(resultLabel);
    layout->setSpacing(5);
    layout->setContentsMargins(0,0,0,5);

    this->setLayout(layout);
}


TextBar::~TextBar() = default;

void TextBar::receiveText(const QString &text) const {
    lineEdit->insert(text);
}


void TextBar::changeResult(const QString &text) const {
    qDebug() << "result:" << text;
    resultLabel->setText(solve(text));
}
