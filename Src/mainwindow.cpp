

#include "mainwindow.h"
#include "textbar.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    resize(520, 800);
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);


    auto *textBar = new TextBar(this);
    textBar->setFixedHeight(200);


    mainLayout->setContentsMargins(30,30,30,30);
    mainLayout->addWidget(textBar);

    auto* spacerItem = new QSpacerItem
        (20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addSpacerItem(spacerItem);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


}

MainWindow::~MainWindow() = default;