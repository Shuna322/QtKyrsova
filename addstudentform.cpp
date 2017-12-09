#include "addstudentform.h"
#include "ui_addstudentform.h"

addStudentForm::addStudentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStudentForm)
{
    ui->setupUi(this);
}

addStudentForm::~addStudentForm()
{
    delete ui;
}
