#include "adduserform.h"
#include "ui_adduserform.h"

addUserForm::addUserForm(QWidget *parent, MainWindow *_prevWindow, class Widget *_loginform) :
    QWidget(parent), prev(_prevWindow), loginform(_loginform),
    ui(new Ui::addUserForm)
{
    ui->setupUi(this);
    if (prev == 0){
        ui->comboBox_3->setEnabled(0);
    }
    ui->dateEdit->setMaximumDate(QDate::currentDate());
}

addUserForm::~addUserForm()
{
    delete ui;
}

void addUserForm::on_pushButton_clicked()
{
    this->hide();
    if (loginform == 0)
    {
        prev->show();
        prev->getdata();
    }
    else if(prev == 0)
            loginform->show();

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
    type_of_acces = ui->comboBox_3->currentIndex()+1;
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    user us(name,sname,tname,sex,bday,phone_number,adress,type_of_acces,login,pass);
    us.addUserToDatabase();
    this->hide();
    if (loginform == 0)
    {
        prev->show();
        prev->getdata();
    }
    else if(prev == 0)
            loginform->show();

}

void addUserForm::on_lineEdit_4_textChanged(const QString &arg1)
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    bool i = 0;
    query.prepare("select * from users where login='" + arg1 + "';");
    if (arg1 == "")
        ui->label_11->setText("");
    else
    {
        query.exec();
        while(query.next()) i=true;
    }
    if (i == 1) ui->label_11->setText("<p align=right><font color=red>Логін уже зайнятий</font></p>");
    else ui->label_11->setText("<p align=right><font color=green>Логін свобідний</font></p>");
    checkVariables();
}

void addUserForm::on_lineEdit_8_textChanged(const QString &arg1)
{
    checkVariables();
}

void addUserForm::on_lineEdit_5_textChanged(const QString &arg1)
{
    checkVariables();
}

void addUserForm::on_lineEdit_textChanged(const QString &arg1)
{
    checkVariables();
}

void addUserForm::on_lineEdit_2_textChanged(const QString &arg1)
{
    checkVariables();
}

void addUserForm::on_lineEdit_3_textChanged(const QString &arg1)
{
    checkVariables();
}

void addUserForm::checkVariables()
{
    if(ui->label_11->text() == "<p align=right><font color=green>Логін свобідний</font></p>" && ui->lineEdit_8->text() != "" && ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_5->text() != "" && ui->lineEdit_7->text() != "" && ui->lineEdit_4->text() != "")
        ui->pushButton_2->setEnabled(1);
    else
        ui->pushButton_2->setEnabled(0);
}
