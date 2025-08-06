#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer=new QTimer(this);  //创建定时器
    //m_timer->stop();
    m_timer->setTimerType(Qt::CoarseTimer);   //定时器精度等级
    ui->coarsetimer->setChecked(true);
    connect(m_timer,&QTimer::timeout,this,&MainWindow::do_timer_timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_timer_timeout()
{
    //与定时器的timeout信号关联的槽函数
    QApplication::beep();   //使用系统的蜂灵器
    QTime curtime=QTime::currentTime(); //获取当前时间
    ui->lcdhour->display(curtime.hour());
    ui->lcdmin->display(curtime.minute());
    ui->lcdsec->display(curtime.second());

    if(m_timer->isSingleShot()){
        //如果是单次定时 显示流逝的时间
        int tmmsec=m_counter.elapsed();  //毫秒数
        QString str=QString("%2-流逝的时间：%1毫秒").arg(tmmsec).arg("静态创建");
        ui->labeltime->setText(str);

        ui->start->setEnabled(true);
        ui->oneshot->setEnabled(true);
        ui->stop->setEnabled(false);
    }
}

void MainWindow::do_timer_shot()
{
    //与动态创建的单词定时器的timeout  信号关联的槽函数
    QApplication::beep();
    int tmmsec=m_counter.elapsed();  //流逝的时间
    QString str=QString("%2-流逝的时间：%1毫秒").arg(tmmsec).arg("动态创建");
    ui->labeltime->setText(str);
    ui->oneshot->setEnabled(true);
}



void MainWindow::on_start_clicked()
{
    //点击开始按钮
    m_timer->setInterval(ui->spinBox->value()); //设置定时器周期

    //单词定时或连续定时
    if(ui->radiocontinue->isChecked()){
        m_timer->setSingleShot(false);
    }else {
        m_timer->setSingleShot(true);
    }

    //定时器精度
    if(ui->precise->isChecked()){
        m_timer->setTimerType(Qt::PreciseTimer);
    }else if(ui->coarse->isChecked()){
        m_timer->setTimerType(Qt::CoarseTimer);
    }else{
        m_timer->setTimerType(Qt::VeryCoarseTimer);
    }

    m_timer->start();  //启动定时器
    m_counter.start();  //启动计时器
    ui->start->setEnabled(false);
    ui->stop->setEnabled(true);
    ui->oneshot->setEnabled(false);
}


void MainWindow::on_stop_clicked()
{
    //停止按钮
    m_timer->stop();  //定时器停止

    int tmMsec=m_counter.elapsed();   //流逝的时间： 毫秒
    int ms=tmMsec%1000;  // 余数毫秒
    int sec=tmMsec/1000;    //整秒

    QString str=QString("流逝的时间:%1秒，%2毫秒").arg(sec).arg(ms,3,10,QChar('0'));
    ui->labeltime->setText(str);

    ui->start->setEnabled(true);
    ui->oneshot->setEnabled(true);
    ui->stop->setEnabled(false);
}


void MainWindow::on_oneshot_clicked()
{
    //动态创建单词定时器
    int intv=ui->spinBox->value();
    QTimer::singleShot(intv,Qt::PreciseTimer,this,&MainWindow::do_timer_shot);
    m_counter.start();   //启动计时器
    ui->oneshot->setEnabled(false);

}

