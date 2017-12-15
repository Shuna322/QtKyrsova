#include "adduserform.h"
#include "ui_adduserform.h"

addUserForm::addUserForm(QWidget *parent, MainWindow *_prevWindow) :
    QWidget(parent), prev(_prevWindow),
    ui(new Ui::addUserForm)
{
    ui->setupUi(this);
}

addUserForm::~addUserForm()
{
    delete ui;
}

void addUserForm::on_pushButton_clicked()
{
    this->hide();
    prev->show();
}
