#include "changestudentinfo.h"
#include "ui_changestudentinfo.h"

changeStudentInfo::changeStudentInfo(QWidget *parent, class MainWindow *_previousform, int id) :
    QWidget(parent), previousform(_previousform), studentID(id),
    ui(new Ui::changeStudentInfo)
{
    ui->setupUi(this);
    st.getdataFromDB(studentID);
    ui->lineEdit->setText(st.getname());
    ui->lineEdit_2->setText(st.getsname());
    ui->lineEdit_3->setText(st.gettname());
    ui->comboBox->setCurrentIndex(st.getsex());
    ui->dateEdit->setDate(st.getbday());
    ui->lineEdit_7->setText(st.getphone_number());
    ui->lineEdit_8->setText(st.getadress());
    ui->comboBox_2->setCurrentIndex(st.gettype_of_education());
    ui->lineEdit_4->setText(st.getdepartament());
    ui->lineEdit_5->setText(st.getgroup());
    ui->comboBox_3->setCurrentIndex(st.getkurs().toInt()-1);
}

changeStudentInfo::~changeStudentInfo()
{
    delete ui;
}

void changeStudentInfo::on_pushButton_clicked()
{
    this->hide();
    previousform->show();
}

void changeStudentInfo::on_pushButton_2_clicked()
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
    student st(name,sname,tname,sex,bday,phone_number,adress,type_of_education,group,departament,kurs);
    st.replaceStudentInDB(studentID);
    this->hide();
    previousform->show();
    previousform->getdata();
}
