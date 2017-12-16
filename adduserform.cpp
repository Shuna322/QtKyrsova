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

void addUserForm::on_pushButton_2_clicked()
{
    QString name, sname, tname, phone_number, adress, login, pass;
    int type_of_acces;
    QDate bday;
    bool sex;
    login = ui->lineEdit_4->text();
    pass = QString("%1").arg(QString(QCryptographicHash::hash(ui->lineEdit_5->text().toUtf8(),QCryptographicHash::Md5).toHex()));
    name = ui->lineEdit->text();
    sname = ui->lineEdit_2->text();
    tname = ui->lineEdit_3->text();
    sex =(bool) ui->comboBox->currentIndex();
    bday = ui->dateEdit->date();
    type_of_acces = ui->comboBox_3->currentText().toInt();
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    user us(name,sname,tname,sex,bday,phone_number,adress,type_of_acces,login,pass);
    us.addUserToDatabase();
    this->hide();
    prev->show();
    prev->getdata();
}
