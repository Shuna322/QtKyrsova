#include "addstudentform.h"
#include "ui_addstudentform.h"

addStudentForm::addStudentForm(QWidget *parent,class MainWindow *_previousform) :
    QWidget(parent), previousform(_previousform),
    ui(new Ui::addStudentForm)
{
    ui->setupUi(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
    on_comboBox_4_currentIndexChanged(0);
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

void addStudentForm::checkVariables()
{
    if(ui->lineEdit_8->text() != "" && ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_7->text() != "")
        ui->pushButton_2->setEnabled(1);
    else
        ui->pushButton_2->setEnabled(0);
}

void addStudentForm::on_comboBox_4_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
    {
        ui->comboBox_5->setEnabled(1);
        ui->comboBox_5->clear();
        ui->comboBox_5->addItem("Туризм");
        ui->comboBox_5->addItem("Менеджмент і адміністрування");
        ui->comboBox_5->addItem("Комп'ютерна інженерія");
        break;
    }
    case 1:
    {
        ui->comboBox_5->setEnabled(1);
        ui->comboBox_5->clear();
        ui->comboBox_5->addItem("Галузеве машинобудування");
        ui->comboBox_5->addItem("Менеджмент");
        ui->comboBox_5->addItem("Автомобільний транспорт");
        ui->comboBox_5->addItem("Транспортні технології");
        ui->comboBox_5->addItem("Автомобільний транспорт (бакалавр)");
        break;
    }
    case 2:
    {
        ui->comboBox_5->setEnabled(1);
        ui->comboBox_5->clear();
        ui->comboBox_5->addItem("Телекомунікації та радіотехніка");
        ui->comboBox_5->addItem("Комп’ютерні науки та інформаційні технології");
        ui->comboBox_5->addItem("Комп'ютерна інженерія");
        break;
    }
    case 3:
    {
        ui->comboBox_5->setEnabled(1);
        ui->comboBox_5->clear();
        ui->comboBox_5->addItem("Соціальний робітник; Гувернер");
        ui->comboBox_5->addItem("Агент з організації туризму; Екскурсовод");
        break;
    }
    case 4:
    {
        ui->comboBox_5->setEnabled(1);
        ui->comboBox_5->clear();
        ui->comboBox_5->addItem("Computer Systems and Networks (Bachelor)");
        ui->comboBox_5->addItem("Radio Engineering (Bachelor)");
        ui->comboBox_5->addItem("Automobile Transport (Bachelor)");
        ui->comboBox_5->addItem("Travel Service (Junior specialist)");
        ui->comboBox_5->addItem("Organisation of Transportation and Automobile Control (juniour specialist)");
        ui->comboBox_5->addItem("Maintenance and repair of automobiles and engines (Junior Specialist)");
        ui->comboBox_5->addItem("Design, manufacture and maintenance of wireless devices (Junior Specialist)");
        ui->comboBox_5->addItem("Material processing on the machines and automatic lines (Junior Specialist)");
        ui->comboBox_5->addItem("Organization of Production (Junior Specialist)");
        ui->comboBox_5->addItem("Maintenance of computer systems and networks (Junior Specialist)");
        break;
    }
    default:
        break;
    }
}
