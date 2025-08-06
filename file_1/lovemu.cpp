#include "lovemu.h"
#include "ui_lovemu.h"

Lovemu::Lovemu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lovemu)
{
    ui->setupUi(this);
}

Lovemu::~Lovemu()
{
    delete ui;
}
