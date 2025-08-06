#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->icon->setPixmap(QPixmap(":/imag/66.png").scaled(20,20));
    ui->lineEdit->setClearButtonEnabled(true);
    //创建serve对象
    serve=new QTcpServer(this);


    //检测客户端连接
    connect(serve,&QTcpServer::newConnection,this,[=](){
        sock=serve->nextPendingConnection();
        ui->icon->setPixmap(QPixmap(":/imag.60.png").scaled(20,20));

        connect(sock,&QTcpSocket::readyRead,this,[=](){
            //接收数据
            QString recvmsg=sock->readAll();
            ui->textBrowser->append("客户端 : "+recvmsg);

        });

        //客户端断开连接
        connect(sock,&QTcpSocket::disconnected,this,[=](){
            ui->textBrowser->append("客户端断开连接");
            sock->deleteLater();
            ui->icon->setPixmap(QPixmap(":/imag/66.png").scaled(20,20));

        });

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    qint64 port=ui->lineEdit->text().toInt();

    //设置服务监听
    serve->listen(QHostAddress::Any,port);
    ui->play->setEnabled(false);

}


void MainWindow::on_sendmsg_clicked()
{
    QString send=ui->text->toPlainText();
    sock->write(send.toUtf8());
    ui->textBrowser->append("服务器 : "+send);
    ui->text->clear();

}

