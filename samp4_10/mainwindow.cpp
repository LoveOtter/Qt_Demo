#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::buildUI()
{
    //创建状态栏上的组件
    labFile=new QLabel(this); //用于显示当前文件名的标签
    labFile->setMinimumWidth(150);
    labFile->setText("文件名：");
    ui->statusbar->addWidget(labFile); //添加到状态栏

    progressbar1=new QProgressBar(this); //状态栏上的进度条
    progressbar1->setMaximumWidth(200);
    progressbar1->setMinimum(0);
    progressbar1->setMaximum(100);
    //progressbar1->setValue(ui->plainTextEdit->font().pointSize());
    progressbar1->setValue(ui->plainTextEdit->toPlainText().length());
    ui->statusbar->addWidget(progressbar1);  //添加到状态栏

    labInfo=new QLabel(this);  //用于显示字体名称的标签
    labInfo->setText("字体名称： ");
    ui->statusbar->addPermanentWidget(labInfo); //添加状态栏



}

void MainWindow::buildSignalSlots()
{

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buildUI();  //动态创建界面组件
    buildSignalSlots();   // 为2个动态创建的组件手动关联信号与槽

    qtim=new QTimer(this);

    connect(qtim,&QTimer::timeout,this,&MainWindow::lableUp);
    qtim->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lableUp()
{
    progressbar1->setValue(ui->plainTextEdit->toPlainText().length());
}

void MainWindow::on_plainTextEdit_copyAvailable(bool b)
{

}


void MainWindow::on_plainTextEdit_selectionChanged()
{

}


void MainWindow::on_actFont_Bold_triggered(bool checked)
{

}


void MainWindow::on_actFont_Italic_triggered(bool checked)
{

}


void MainWindow::on_actFont_UnderLine_triggered(bool checked)
{

}


void MainWindow::on_actSys_ToggleText_triggered(bool checked)
{

}


void MainWindow::on_actFile_New_triggered()
{

}


void MainWindow::on_actFile_Open_triggered()
{

}


void MainWindow::on_actFile_Save_triggered()
{

}

