#include "showtable.h"
#include "ui_showtable.h"

showTable::showTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showTable)
{
    ui->setupUi(this);
}

showTable::~showTable()
{
    delete ui;
}
