#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uipropert();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uipropert()
{
    ui->numb_2->setDecimals(2);  //显示2位小数
    ui->numb_3->setDecimals(2);

    ui->spinBox_2->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    ui->spinBox_2->setDisplayIntegerBase(10);
    ui->spinBox->setRange(0,65535);
    ui->spinBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    ui->spinBox->setRange(0,65535);
    ui->spinBox->setDisplayIntegerBase(2);

    ui->spinBox_3->setRange(0,65535);
    ui->spinBox_3->setDisplayIntegerBase(16);


}



void MainWindow::on_btnS_clicked()
{
    int num=ui->number->text().toInt();  //读取数量
    float num_2=ui->numb_2->text().toFloat();  //读取单价
    float zo=num*num_2;
    ui->numb_3->setValue(zo);

}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug(ui->spinBox->cleanText().toLocal8Bit().data());
    ui->spinBox_2->setValue(arg1);
    ui->spinBox_3->setValue(arg1);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    qDebug(ui->spinBox_2->cleanText().toLocal8Bit().data());
    ui->spinBox->setValue(arg1);
    ui->spinBox_3->setValue(arg1);
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    qDebug(ui->spinBox_3->cleanText().toLocal8Bit().data());
    ui->spinBox->setValue(arg1);
    ui->spinBox_2->setValue(arg1);
}

