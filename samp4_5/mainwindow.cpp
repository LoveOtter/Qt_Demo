#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_left_clicked()
{
    ui->lineinput->setAlignment(Qt::AlignLeft);
}


void MainWindow::on_btn_center_clicked()
{
    ui->lineinput->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_btn_right_clicked()
{
    ui->lineinput->setAlignment(Qt::AlignRight);
}




void MainWindow::on_readonly_clicked(bool checked)
{
    ui->lineinput->setReadOnly(checked);
}


void MainWindow::on_enable_clicked(bool checked)
{
    ui->lineinput->setEnabled(checked);
}


void MainWindow::on_clearbutton_clicked(bool checked)
{
    ui->lineinput->setClearButtonEnabled(checked);
}


void MainWindow::on_black_clicked()
{
    QPalette plet=ui->lineinput->palette();
    plet.setColor(QPalette::Text,Qt::black);
    ui->lineinput->setPalette(plet);

}


void MainWindow::on_red_clicked()
{
    QPalette plet=ui->lineinput->palette();
    plet.setColor(QPalette::Text,Qt::red);
    ui->lineinput->setPalette(plet);
}


void MainWindow::on_blue_clicked()
{
    QPalette plet=ui->lineinput->palette();
    plet.setColor(QPalette::Text,Qt::blue);
    ui->lineinput->setPalette(plet);
}

void MainWindow::on_btn_bold_clicked(bool checked)
{
    QFont font=ui->lineinput->font();
    font.setItalic(true);
    ui->lineinput->setFont(font);
}


void MainWindow::on_btn_italic_clicked(bool checked)
{
    QFont font=ui->lineinput->font();
    font.setItalic(checked);
    ui->lineinput->setFont(font);
}


void MainWindow::on_btn_underline_clicked(bool checked)
{
    QFont font=ui->lineinput->font();
    font.setUnderline(checked);
    ui->lineinput->setFont(font);
}

