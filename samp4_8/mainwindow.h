#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //自定义函数 与定时器的timeout信号关联
    void do_timer_timeout();

    //与单次定时器关联的槽函数
    void do_timer_shot();

    void on_start_clicked();

    void on_stop_clicked();

    void on_oneshot_clicked();

private:
    QTimer *m_timer;  //定时器

    QElapsedTimer  m_counter;  //计时器

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
