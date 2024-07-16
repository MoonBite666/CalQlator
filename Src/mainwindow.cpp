

#include "mainwindow.h"
#include "textbar.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    resize(500, 800);
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    auto *textBar = new TextBar(this);
    layout->addWidget(textBar);

    layout->setContentsMargins(50,50,50,50);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


}

MainWindow::~MainWindow() = default;