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
    st(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),(bool)ui->comboBox->currentIndex(),ui->spinBox->value(),ui->lineEdit_4->text().toInt(),ui->lineEdit_5->text().toInt(),ui->lineEdit_6->text().toInt(),ui->lineEdit_7->text(),ui->lineEdit_8->text(),(bool)ui->comboBox_2->currentIndex());
    st.addStudentToDB();
}
