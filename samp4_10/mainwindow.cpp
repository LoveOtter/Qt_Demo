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

    //actlang_cn和actlang_en创建actiongroup 实现互斥选择
    actionGroup=new QActionGroup(this);
    actionGroup->addAction(ui->actLang_CN);
    actionGroup->addAction(ui->actLang_EN);
    actionGroup->setExclusive(true);
    ui->actLang_CN->setCheckable(true);

    //创建工具栏上无法可视化设计的一些组件
    spinFontSize=new QSpinBox(this); //字体大小spinbox
    spinFontSize->setMinimum(0);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->plainTextEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->toolBar->addWidget(spinFontSize);

    spinFontSize1=new QSpinBox(this);
    spinFontSize1->setMinimum(0);
    spinFontSize1->setMaximum(10000);
    spinFontSize1->setValue(ui->plainTextEdit->toPlainText().length());
    spinFontSize1->setMinimumWidth(50);
    ui->toolBar->addWidget(spinFontSize1);
    //ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    comboFontName=new QFontComboBox(this);  //字体名称commfontbox
    comboFontName->setMinimumWidth(150);
    ui->toolBar->addWidget(comboFontName);

    ui->toolBar->addSeparator(); //工具栏上增加分割条
    ui->toolBar->addAction(ui->actClose);

}

void MainWindow::buildSignalSlots()
{
    connect(spinFontSize,&QSpinBox::valueChanged,this,&MainWindow::do_fontSize_changed);
    connect(comboFontName,&QFontComboBox::currentFontChanged,this,&MainWindow::do_fontSelected);

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

    //ui->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly); //工具栏只显示图标
    this->setCentralWidget(ui->plainTextEdit); //textedit填充满工作区
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lableUp()
{
    progressbar1->setValue(ui->plainTextEdit->toPlainText().length());
    spinFontSize1->setValue(ui->plainTextEdit->toPlainText().length());  //更新字体个数
    ui->plainTextEdit->update();
}

void MainWindow::do_fontSize_changed(int fontSize)
{
    //字体大小
    QTextCharFormat fmt=ui->plainTextEdit->currentCharFormat();
    fmt.setFontPointSize(fontSize); //设置字体大小
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
    //progressbar1->setValue(fontSize);


}

void MainWindow::do_fontSelected(const QFont &font)
{
    //选择字体 fontcombox
    labInfo->setText("字体名称: "+font.family()); //状态栏显示
    QTextCharFormat fmt=ui->plainTextEdit->currentCharFormat();
    fmt.setFont(font);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_plainTextEdit_copyAvailable(bool b)
{
    //copyavilable信号 更新3个actions的使能状态
    ui->actEdit_Cut->setEnabled(b);
    ui->actEdit_Copy->setEnabled(b);
    ui->actEdit_Paste->setEnabled(ui->plainTextEdit->canPaste());

}

//selectionChanged 信号，更新3种字体样式的checked状态
void MainWindow::on_plainTextEdit_selectionChanged()
{
    QTextCharFormat fmt=ui->plainTextEdit->currentCharFormat();
    ui->actFont_Bold->setCheckable(fmt.font().bold());
    ui->actFont_Italic->setCheckable(fmt.fontItalic());
    ui->actFont_UnderLine->setCheckable(fmt.fontUnderline());

}


void MainWindow::on_actFont_Bold_triggered(bool checked)
{
    //粗体
    QTextCharFormat fmt=ui->plainTextEdit->currentCharFormat();
    if(checked){
        fmt.setFontWeight(QFont::Bold);
    }else{
        fmt.setFontWeight(QFont::Normal);
    }
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actFont_Italic_triggered(bool checked)
{
    //斜体
    QTextCharFormat fmt=ui->plainTextEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actFont_UnderLine_triggered(bool checked)
{
    //下划线
    QTextCharFormat fmt=ui->plainTextEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actSys_ToggleText_triggered(bool checked)
{
    //是否显示工具栏按钮文字
    if(checked){
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    }else{
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    }

}


void MainWindow::on_actFile_New_triggered()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->document()->setModified(false);
    labFile->setText("新建了一个文件");

}


void MainWindow::on_actFile_Open_triggered()
{
    labFile->setText("打开的文件");

}


void MainWindow::on_actFile_Save_triggered()
{
    ui->plainTextEdit->document()->setModified(false);
    labFile->setText("文件已经保存");

}

