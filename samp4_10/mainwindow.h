#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QLabel>
#include<QProgressBar>
#include<QSpinBox>
#include<QFontComboBox>
#include<QActionGroup>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTimer *qtim;
    QLabel *labFile;  //状态栏使用
    QLabel *labInfo;  //状态栏使用
    QProgressBar *progressbar1;  //状态栏上的进度条

    QSpinBox *spinFontSize;  //字体大小
    QSpinBox *spinFontSize1;  //字体个数
    QFontComboBox *comboFontName;  //字体名称

    QActionGroup *actionGroup;  //action分组 用于中文和英文的互斥选择

    void buildUI(); //程序设计ui初始化
    void buildSignalSlots();  //手工关联信号和槽


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void lableUp();

    void do_fontSize_changed(int fontSize);

    void do_fontSelected(const QFont& font);

    void on_plainTextEdit_copyAvailable(bool b);

    void on_plainTextEdit_selectionChanged();

    void on_actFont_Bold_triggered(bool checked);

    void on_actFont_Italic_triggered(bool checked);

    void on_actFont_UnderLine_triggered(bool checked);

    void on_actSys_ToggleText_triggered(bool checked);

    void on_actFile_New_triggered();

    void on_actFile_Open_triggered();

    void on_actFile_Save_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
