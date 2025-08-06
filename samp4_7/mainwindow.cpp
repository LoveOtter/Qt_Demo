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

void MainWindow::on_gettime_clicked()
{
    QDateTime date=QDateTime::currentDateTime();   //初始化为系统当前时间
    ui->timeEdit->setTime(date.time());
    ui->edittime->setText(date.toString("hh:mm:ss"));

    ui->dateEdit->setDate(date.date());
    ui->editdate->setText(date.toString("yyyy-MM-dd"));

    ui->dateTimeEdit->setDateTime(date);
    ui->editdatetime->setText(date.toString("yyyy-MM-dd hh:mm:ss"));

}


void MainWindow::on_debugtime_clicked()
{
    QTime tm1=QTime::currentTime();  //定义变量  初始化设置时间
    QString str=tm1.toString("hh:mm:ss");
    qDebug()<<"orginial time= "<<str.toLocal8Bit().data();

    QTime tm2=tm1.addSecs(120);  //延后150秒
    str=tm2.toString("hh:mm:ss");
    qDebug()<<"150s later, time= "<<str.toLocal8Bit().data();


    tm2=QTime::currentTime();
    str=tm2.toString("hh:mm:ss zzz");
    qDebug()<<"current time ="<<str.toLocal8Bit().data();
    qDebug()<<"hour ="<<tm2.hour();
    qDebug()<<"minute ="<<tm2.minute();
    qDebug()<<"second ="<<tm2.second();
    qDebug()<<"msecond ="<<tm2.msec();

}


void MainWindow::on_settime_clicked()
{
    //设置时间按钮
    QString str=ui->edittime->text();
    str=str.trimmed();  //去除两端的空格
    if(!str.isEmpty()){
        QTime tm=QTime::fromString(str,"hh:mm:ss");  //从字符串转换成时间格式
        ui->timeEdit->setTime(tm);
    }
}


void MainWindow::on_debugdate_clicked()
{
    QDate tm1=QDate::currentDate();
    QString str=tm1.toString("yyyy-MM-dd");
    qDebug()<<"date = "<<str.toLocal8Bit().data();

    QDate tm2=tm1;
    str=tm2.toString("yyyy-MM-dd");
    qDebug()<<"tm2 = "<<str.toLocal8Bit().data();
    qDebug()<<"days between tm2 "<<tm2.daysTo(tm1);  //计算tm2于tm1相隔的天数

    qDebug()<<"current date ="<<str.toLocal8Bit().data();
    qDebug()<<"year"<<tm2.year();
    qDebug()<<"month = "<<tm2.month();
    qDebug()<<"day = "<<tm2.day();
    qDebug()<<"week = "<<tm2.dayOfWeek();  //显示星期

}


void MainWindow::on_setdate_clicked()
{
    QString str=ui->editdate->text();
    str=str.trimmed();
    if(!str.isEmpty()){
        QDate qd=QDate::fromString(str,"yyyy-MM-dd");
        ui->dateEdit->setDate(qd);
    }

}


void MainWindow::on_debugdatetime_clicked()
{

}


void MainWindow::on_setdatetime_clicked()
{
    QString str=ui->editdatetime->text();
    str=str.trimmed();
    if(!str.isEmpty()){
        QDateTime qdt=QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(qdt);
    }
}


void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate dt=ui->calendarWidget->selectedDate();
    QString str=dt.toString("yyyy年M月d日");
    ui->editCalendar->setText(str);
}

