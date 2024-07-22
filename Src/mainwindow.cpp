

#include "mainwindow.h"
#include "textbar.h"
#include "numpad.h"
#include "calculate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    resize(520, 600);
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    auto *textBar = new TextBar(this);
    auto *numpad = new Numpad(this);

    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(30,25,30,25);

    mainLayout->addWidget(textBar);
    mainLayout->addWidget(numpad);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    QDebug(QtMsgType::QtInfoMsg) << solve("(2+3)×5");


}

MainWindow::~MainWindow() = default;