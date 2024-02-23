#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Yhdistä napit slotteihin
    connect(ui->count, &QPushButton::clicked, this, &MainWindow::count);
    connect(ui->reset, &QPushButton::clicked, this, &MainWindow::reset);

    // Alusta LineEdit-kentän arvo
    ui->kasvu->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count()
{
    // Hae nykyinen arvo LineEdit-kentästä, lisää 1 ja päivitä se
    int currentValue = ui->kasvu->text().toInt();
    ui->kasvu->setText(QString::number(currentValue + 1));
}

void MainWindow::reset()
{
    // Nollaa LineEdit-kentän arvo
    ui->kasvu->setText("0");
}
