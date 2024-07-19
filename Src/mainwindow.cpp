

#include "mainwindow.h"

#include "resultbar.h"
#include "textbar.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    resize(520, 800);
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    auto *textContainer = new QWidget(centralWidget);
    textContainer->setFixedHeight(200);
    auto *textLayout = new QVBoxLayout(textContainer);
    auto *textBar = new TextBar(textContainer);
    auto *resultBar = new ResultBar(textContainer);


    // textLayout->setSpacing(5);
    textLayout->addWidget(textBar);
    textLayout->addWidget(resultBar);


    mainLayout->setContentsMargins(30,30,30,30);
    mainLayout->addWidget(textContainer);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


}

MainWindow::~MainWindow() = default;