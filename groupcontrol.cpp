#include "groupcontrol.h"
#include "ui_groupcontrol.h"

groupControl::groupControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::groupControl)
{
    ui->setupUi(this);
}

groupControl::~groupControl()
{
    delete ui;
}
