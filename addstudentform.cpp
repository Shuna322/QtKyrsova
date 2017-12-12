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
    QString name, sname, tname, phone_number, adress, departament, group;
    int age, kurs;
    QDate bday;
    bool sex, type_of_education;
    name =ui->lineEdit->text();
    sname = ui->lineEdit_2->text();
    tname = ui->lineEdit_3->text();
    sex =(bool) ui->comboBox->currentIndex();
    age = ui->spinBox->value();
    bday = ui->dateEdit->date();
    departament =ui->lineEdit_4->text();
    group = ui->lineEdit_5->text();
    kurs = ui->comboBox_3->currentIndex();
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    type_of_education = (bool)ui->comboBox_2->currentIndex();
    qDebug() << sex << type_of_education;
    student st(name,sname,tname,sex,age,bday,phone_number,adress,type_of_education,group,departament,kurs);
    st.addStudentToDB();
}

/*void addStudentForm::on_pushButton_3_clicked()
{
    database db;
    db.connect();
    QSqlQuery query;
    query.prepare("insert into a (`a`)"
                  "values (:date)");
    query.bindValue(":date",ui->dateEdit->date());
    query.exec();
   // qDebug() << query.lastError() << query.lastQuery();
}
*/
