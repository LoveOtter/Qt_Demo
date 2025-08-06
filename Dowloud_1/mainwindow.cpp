#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QMessageBox>
#include<QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/imag/5.gif"));
    ui->editUrl->setClearButtonEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_finished()
{
    QFileInfo fileinfo(downloadfile->fileName());

    downloadfile->close();
    delete downloadfile;

    reply->deleteLater();

    if(ui->checkBox->isCheckable()){
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileinfo.absoluteFilePath()));
    }
    ui->btnDown->setEnabled(true);
}

void MainWindow::do_readyRead()
{
    downloadfile->write(reply->readAll());
}

void MainWindow::do_downloadProgress(qint64 bytes, qint64 total)
{
    //设置下载进度
    ui->progressBar->setMaximum(total);
    ui->progressBar->setValue(bytes);
}

void MainWindow::on_btnDown_clicked()
{
    //点击下载按钮
    QString urlSpec=ui->editUrl->text().trimmed();


    if(urlSpec.isEmpty()){
        QMessageBox::information(this,"错误","请添加下载路径");
        return;
    }

    QUrl newUrl=QUrl::fromUserInput(urlSpec);
    if(!newUrl.isValid()){
        QString info="无效url"+urlSpec+"\n错误信息："+newUrl.errorString();
        QMessageBox::information(this,"错误",info);
        return;
    }

    QString tempDir=ui->editPath->text().trimmed();
    if(tempDir.isEmpty()){
        QMessageBox::information(this,"错误","指定保存路径为空");
        return;
    }

    QString fullFileName=tempDir+newUrl.fileName();

    if(QFile::exists(fullFileName)){
        QFile::remove(fullFileName);
    }

    downloadfile=new QFile(fullFileName);
    if(!downloadfile->open(QIODevice::WriteOnly)){
        QMessageBox::information(this,"错误","临时文件无法打开");
        return;
    }

    ui->btnDown->setEnabled(false);

    //发送请求
    reply=networkManager.get(QNetworkRequest(newUrl));
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::do_readyRead);
    connect(reply,&QNetworkReply::downloadProgress,this,&MainWindow::do_downloadProgress);

    connect(reply,&QNetworkReply::finished,this,&MainWindow::do_finished);
}


void MainWindow::on_btnDefaultPath_clicked()
{
    //设置默认路径
    QString curpath=QDir::currentPath();
    QDir dir(curpath);
    QString sub="test";

    if(!dir.mkdir(sub)){
        QMessageBox::information(this,"错误","文件夹已经存在");
        return;
    }
    ui->editPath->setText(curpath+"/"+sub+"/");



}


void MainWindow::on_editUrl_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}

