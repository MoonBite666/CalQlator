

#include "mainwindow.h"
#include "textbar.h"
#include "numpad.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    resize(520, 600);
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    auto *textBar = new TextBar(this);
    // textBar->setFixedHeight(100);

    auto *numpad = new Numpad(this);
    // numpad->setFixedHeight(300);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(30,30,30,10);
    mainLayout->addWidget(textBar);

    auto* spacerItem = new QSpacerItem
        (20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addSpacerItem(spacerItem);

    mainLayout->addWidget(numpad);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


}

MainWindow::~MainWindow() = default;