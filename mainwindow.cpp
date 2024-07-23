

#include "mainwindow.h"
#include "Inc/textbar.h"
#include "Inc/numpad.h"
#include "Inc/calculate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    resize(420, 480);
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    auto *textBar = new TextBar(this);
    auto *numpad = new Numpad(this);
    connect(numpad, &Numpad::addText, textBar, &TextBar::receiveText);

    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(30,25,30,25);

    mainLayout->addWidget(textBar);
    mainLayout->addWidget(numpad);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


}

MainWindow::~MainWindow() = default;