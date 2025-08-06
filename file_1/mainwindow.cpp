#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    love=new Lovemu(ui->widget);
    sgo=new siago(ui->widget);

    love->hide();
    sgo->hide();



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_4_clicked()
{

    //ui->widget->layout()->addWidget(love);
    sgo->hide();
    love->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    love->hide();
    sgo->show();
}

