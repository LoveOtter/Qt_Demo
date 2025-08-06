#include "siago.h"
#include "ui_siago.h"

siago::siago(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::siago)
{
    ui->setupUi(this);
}

siago::~siago()
{
    delete ui;
}
