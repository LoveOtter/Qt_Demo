#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_gettime_clicked();

    void on_debugtime_clicked();

    void on_settime_clicked();

    void on_debugdate_clicked();

    void on_setdate_clicked();

    void on_debugdatetime_clicked();

    void on_setdatetime_clicked();

    void on_calendarWidget_selectionChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
