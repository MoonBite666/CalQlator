

#include "mainwindow.h"
#include "textbar.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    setFixedSize(500, 800);
    setCentralWidget(new TextBar(this));
}

MainWindow::~MainWindow() = default;