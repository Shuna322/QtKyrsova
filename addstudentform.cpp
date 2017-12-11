#include "addstudentform.h"
#include "ui_addstudentform.h"

addStudentForm::addStudentForm(QWidget *parent,QMainWindow *_previousform) :
    QWidget(parent), previousform(_previousform),
    ui(new Ui::addStudentForm)
{
    ui->setupUi(this);
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
    QString name, sname, tname, phone_number, adress, group, faculted;
    int age, bday, bmounth, byear;
    bool sex, type_of_education;
    name =ui->lineEdit->text();
    sname = ui->lineEdit_2->text();
    tname = ui->lineEdit_3->text();
    sex =(bool) ui->comboBox->currentIndex();
    age = ui->spinBox->value();
    bday = ui->lineEdit_4->text().toInt();
    bmounth = ui->lineEdit_5->text().toInt();
    byear = ui->lineEdit_6->text().toInt();
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    type_of_education = (bool)ui->comboBox_2->currentIndex();
    group = ui->lineEdit_9->text();
    faculted = ui->lineEdit_10->text();
    //qDebug() << sex << type_of_education;
    student st(name,sname,tname,sex,age,bday, bmounth, byear,phone_number,adress,type_of_education, group, faculted);
    st.addStudentToDB();
}
