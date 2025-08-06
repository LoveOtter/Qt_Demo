#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ip->setClearButtonEnabled(true);
    ui->port->setClearButtonEnabled(true);

    //创建套接字对象
    sock=new QTcpSocket(this);
    //检测服务器是否回复数据
    connect(sock,&QTcpSocket::readyRead,this,[=](){
        QByteArray recvmsg=sock->readAll();
        ui->textBrowser->append("服务器 ："+recvmsg);
    });

    //检测服务器是否连接成功
    connect(sock,&QTcpSocket::connected,this,[=](){
        ui->textBrowser->append("服务器连接成功");

    });

    connect(sock,&QTcpSocket::disconnected,this,[=](){
        ui->textBrowser->append("服务器已经断开连接。。。");
        ui->newser->setEnabled(true);
        ui->disserve->setEnabled(false);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newser_clicked()
{
    QString ip=ui->ip->text();
    qint64 port=ui->port->text().toInt();

    sock->connectToHost(QHostAddress(ip),port);

    ui->newser->setEnabled(false);
    ui->disserve->setEnabled(true);

}


void MainWindow::on_disserve_clicked()
{
    sock->close();
    ui->newser->setEnabled(true);
    ui->disserve->setEnabled(false);

}


void MainWindow::on_newcode_clicked()
{
    QString sendmsg=ui->textEdit->toPlainText();
    sock->write(sendmsg.toUtf8());
    ui->textBrowser->append("客户端 ："+sendmsg);
    ui->textEdit->clear();
}

