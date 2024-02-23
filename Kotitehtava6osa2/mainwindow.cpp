#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number1 = "";
    number2 = "";
    state = 1;
    result = 0;
    operand = 0;

    // Connect signals and slots
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::resetLineEdits);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();

    if(state == 1) {
        number1.append(buttonText);
        ui->num1->setText(number1);
    } else if(state == 2) {
        number2.append(buttonText);
        ui->num2->setText(number2);
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();

    // Store the operation
    if(buttonText == "+") {
        operand = 1;
    } else if(buttonText == "-") {
        operand = 2;
    } else if(buttonText == "*") {
        operand = 3;
    } else if(buttonText == "/") {
        operand = 4;
    }

    state = 2; // Move to the second number input
}

void MainWindow::resetLineEdits()
{
    number1 = "";
    number2 = "";
    state = 1;
    result = 0;
    operand = 0;

    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

void MainWindow::clearAndEnterClickHandler()
{
    float num1 = number1.toFloat();
    float num2 = number2.toFloat();

    // Handle the case where only one number is entered
    if (state == 1) {
        ui->result->setText("Please insert another number");
        return;
    }
    // Handle division by zero
    if (operand == 4 && num2 == 0) {
        ui->result->setText("Division by zero");
        return;
    }

    switch(operand) {
    case 1:
        result = num1 + num2;
        break;
    case 2:
        result = num1 - num2;
        break;
    case 3:
        result = num1 * num2;
        break;
    case 4:
        result = num1 / num2;
        break;
    default:
        break;
    }

    ui->result->setText(QString::number(result));
}
