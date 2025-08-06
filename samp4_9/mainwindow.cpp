#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>

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

void MainWindow::on_btnlnitems_clicked()
{
    //初始化列表  按钮
    ui->comboBox->clear();
    for (int i = 0; i < 4; ++i) {
        ui->comboBox->addItem(QString("Itme %1").arg(i));
    }

    QStringList str;
    str<<"北京"<<"上海"<<"天津"<<"苏州"<<"杭州"<<"桂林";
    ui->comboBox->addItems(str);

}


void MainWindow::on_btnclear_clicked()
{
    //清空列表  按钮
    ui->comboBox->clear();

}


void MainWindow::on_checkBoxeditbale_clicked(bool checked)
{
    //可编辑 checkbox
    ui->comboBox->setEditable(checked);
}


void MainWindow::on_btnclearntext_clicked()
{
    //清空文本框
    ui->plainTextEdit->clear();

}


void MainWindow::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    //创建并显示标准弹出式菜单
    QMenu* menu=ui->plainTextEdit->createStandardContextMenu();//创建标准右键菜单

    menu->exec(pos);  //在鼠标光标位置显示右键快捷菜单


}


void MainWindow::on_btnlni2_clicked()
{
    QMap<QString,int> m;
    m.insert("北京",10);
    m.insert("上海",13);
    m.insert("天津",2);
    m.insert("大连",23);
    m.insert("杭州",24);
    m.insert("贵州",55);

    ui->comboBox_2->clear();
    foreach (const QString& str, m.keys()) {
        ui->comboBox_2->addItem(str,m.value(str));
    }
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    Q_UNUSED(index);

    QString s=ui->comboBox_2->currentText();      //标题
    QString s2=ui->comboBox_2->currentData().toString();   //用户数据
    ui->plainTextEdit->appendPlainText(s+": 区号 = "+s2);
}

