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
    ui->comboBox_4->setCurrentIndex(st.getdepartament()-1);
    ui->comboBox_5->setCurrentIndex(st.getspeciality()-1);
    ui->comboBox_3->setCurrentIndex(st.getkurs().toInt()-1);
    ui->dateEdit_2->setDate(st.getstartEdu());
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
    QString name, sname, tname, phone_number, adress;
    int departament, speciality;
    QDate bday, startEdu;
    bool sex, type_of_education;
    name =ui->lineEdit->text();
    sname = ui->lineEdit_2->text();
    tname = ui->lineEdit_3->text();
    sex =(bool) ui->comboBox->currentIndex();
    bday = ui->dateEdit->date();
    departament =ui->comboBox_4->currentIndex()+1;
    speciality = ui->comboBox_5->currentIndex()+1;
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    type_of_education = (bool)ui->comboBox_2->currentIndex();
    startEdu = ui->dateEdit_2->date();
    qDebug() << sex << type_of_education;
    student st(name,sname,tname,sex,bday,phone_number,adress,type_of_education,speciality,departament,startEdu);
    st.replaceStudentInDB(studentID);
    this->hide();
    previousform->show();
    previousform->getdata();
}
