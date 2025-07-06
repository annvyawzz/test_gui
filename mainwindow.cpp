#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_options_currentIndexChanged(ui->options->currentIndex());
    ui->num2->show();

    connect(ui->concatButton, &QPushButton::clicked,
            this, &MainWindow::on_concatButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked,
            this, &MainWindow::on_cancelButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_options_currentIndexChanged(int index)
{
    ui->answer->setText("");
    if(index >= 2) ui->num2->hide();
    else ui->num2->show();
}


void MainWindow::on_solve_clicked() {
    QString str = ui->num1->text();
    if(str.isEmpty()) {
        ui->answer->setText("Error");
        return;
    }
    num.set(str.toInt());

    str = ui->num2->text();
    int y = str.toInt();

    switch(ui->options->currentIndex()) {
    case 0:
        if(str.isEmpty()) ui->answer->setText("Error");
        else ui->answer->setText(QString::number(num.GCD(y)));
        break;
    case 1:
        if(str.isEmpty()) ui->answer->setText("Error");
        else ui->answer->setText(QString::number(num.LCM(y)));
        break;
    case 2:
        ui->answer->setText(num.isPrime() ? "True" : "False");
        break;
    case 3:
        ui->answer->setText(num.isArmstrong() ? "True" : "False");
        break;
    case 4:
        ui->answer->setText(QString::number(num.countDigits()));
        break;
    }
}

void MainWindow::on_num1_clicked() {
    ui->answer->clear();
}

void MainWindow::on_num2_clicked() {
    ui->answer->clear();
}

void MainWindow::on_concatButton_clicked()
{
    QString text1 = ui->num1->text();
    QString text2 = ui->num2->text();
    ui->answer->setText(text1 + text2);
}

void MainWindow::on_cancelButton_clicked()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->answer->clear();

}
