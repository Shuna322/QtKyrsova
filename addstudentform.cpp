#include "addstudentform.h"
#include "ui_addstudentform.h"

addStudentForm::addStudentForm(QWidget *parent,class MainWindow *_previousform) :
    QWidget(parent), previousform(_previousform),
    ui(new Ui::addStudentForm)
{
    ui->setupUi(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
}

addStudentForm::~addStudentForm()
{
    delete ui;
}

void addStudentForm::on_pushButton_clicked()
{
    this->hide();
    previousform->show();
}

void addStudentForm::on_pushButton_2_clicked()
{
    QString name, sname, tname, phone_number, adress, departament, group;
    int kurs;
    QDate bday;
    bool sex, type_of_education;
    name =ui->lineEdit->text();
    sname = ui->lineEdit_2->text();
    tname = ui->lineEdit_3->text();
    sex =(bool) ui->comboBox->currentIndex();
    bday = ui->dateEdit->date();
    departament =ui->lineEdit_4->text();
    group = ui->lineEdit_5->text();
    kurs = ui->comboBox_3->currentIndex()+1;
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    type_of_education = (bool)ui->comboBox_2->currentIndex();
    qDebug() << sex << type_of_education;
    student st(name,sname,tname,sex,bday,phone_number,adress,type_of_education,group,departament,kurs);
    st.addStudentToDB();
    this->hide();
    previousform->show();
    previousform->getdata();
}

void addStudentForm::on_lineEdit_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::on_lineEdit_2_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::on_lineEdit_3_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::on_lineEdit_7_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::on_lineEdit_8_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::on_lineEdit_4_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::on_lineEdit_5_textChanged(const QString &arg1)
{
    checkVariables();
}

void addStudentForm::checkVariables()
{
    if(ui->lineEdit_8->text() != "" && ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_5->text() != "" && ui->lineEdit_7->text() != "" && ui->lineEdit_4->text() != "")
        ui->pushButton_2->setEnabled(1);
    else
        ui->pushButton_2->setEnabled(0);
}
