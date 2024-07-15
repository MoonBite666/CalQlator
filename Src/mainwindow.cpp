

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("CalQlator");
    setFixedSize(500, 800);
}

MainWindow::~MainWindow() = default;