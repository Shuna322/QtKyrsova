#include "addstudentform.h"
#include "ui_addstudentform.h"

addStudentForm::addStudentForm(QWidget *parent,class MainWindow *_previousform) :
    QWidget(parent), previousform(_previousform),
    ui(new Ui::addStudentForm)
{
    ui->setupUi(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
    on_comboBox_4_currentIndexChanged(0);   //потрібно загрузити хренатень з БД
    loadDepartamentFromDB();
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
    int group;
    QDate bday, startEdu;
    bool sex, type_of_education;
    name =ui->lineEdit->text();
    sname = ui->lineEdit_2->text();
    tname = ui->lineEdit_3->text();
    sex =(bool) ui->comboBox->currentIndex();
    bday = ui->dateEdit->date();
    group = getGroupID();
    phone_number = ui->lineEdit_7->text();
    adress = ui->lineEdit_8->text();
    type_of_education = (bool)ui->comboBox_2->currentIndex();
    startEdu = ui->dateEdit_2->date();
    student st(name,sname,tname,sex,bday,phone_number,adress,type_of_education,group,startEdu);
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
    query = new QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query->prepare("select distinct `name` from groups where `departament_code` = :index");
    query->bindValue(":index",index+1);
    query->exec();
    model->setQuery(*query);
    ui->comboBox_5->setModel(model);
    ui->comboBox_5->setModelColumn(0);
}

void addStudentForm::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    query = new QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query->prepare("select distinct `code` from groups where `name` = :name");
    query->bindValue(":name",arg1);
    query->exec();
    model->setQuery(*query);
    ui->comboBox_6->setModel(model);
    ui->comboBox_6->setModelColumn(0);
}

int addStudentForm::getGroupID()
{
    int temp;
    query = new QSqlQuery(db.getdb());
    query->prepare("select `id` from groups where code = '"+ui->comboBox_6->currentText()+"';");
    query->exec();
    while(query->next()) temp = query->value(0).toInt();
    return temp;
}

void addStudentForm::loadDepartamentFromDB()
{
    query->prepare("select `name` from `departaments`");
    query->exec();
    model->setQuery(*query);
    ui->comboBox_4->setModel(model);
    ui->comboBox_4->setModelColumn(0);
}
