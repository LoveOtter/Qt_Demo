#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,&QAbstractSlider::valueChanged,this,&MainWindow::do_value);
    connect(ui->horizontalScrollBar,&QAbstractSlider::valueChanged,this,&MainWindow::do_value);
    connect(ui->dial,&QAbstractSlider::valueChanged,this,&MainWindow::do_value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_value(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    ui->progressBar->setTextVisible(checked);
}


void MainWindow::on_checkBox_2_clicked(bool checked)
{
    ui->progressBar->setInvertedAppearance(checked);
}


void MainWindow::on_radioButton_clicked()
{
    ui->progressBar->setFormat("%p%");
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->progressBar->setFormat("%v");
}

