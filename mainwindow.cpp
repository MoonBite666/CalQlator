#include "mainwindow.h"
#include "calculate.h"
#include "./Form/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    for(int i = 0; i < 16; i++) {
        auto *button = this->findChild<QPushButton*>(QString("button_%1").arg(i));
        if(button) {
            connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
        }
    }
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::changeResult);
}

void MainWindow::onButtonClicked() {
    auto *button = qobject_cast<QPushButton*>(sender());
    if(button->text() == u"=") return;
    ui->lineEdit->insert(button->text());
}
void MainWindow::changeResult(const QString &text) const {
    ui->label->setText(solve(text));
}


MainWindow::~MainWindow()
{
    delete ui;
}
