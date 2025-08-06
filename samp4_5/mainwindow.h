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
    void on_btn_left_clicked();

    void on_btn_center_clicked();

    void on_btn_right_clicked();


    void on_readonly_clicked(bool checked);

    void on_enable_clicked(bool checked);

    void on_clearbutton_clicked(bool checked);

    void on_black_clicked();

    void on_red_clicked();

    void on_blue_clicked();

    void on_btn_bold_clicked(bool checked);

    void on_btn_italic_clicked(bool checked);

    void on_btn_underline_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
