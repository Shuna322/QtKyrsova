#include "studentinformation.h"
#include "ui_studentinformation.h"

studentInformation::studentInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentInformation)
{
    ui->setupUi(this);
}

studentInformation::~studentInformation()
{
    delete ui;
}
