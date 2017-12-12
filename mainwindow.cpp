#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QModelIndex>
#include "studentinformation.h"

MainWindow::MainWindow(QWidget *parent, QString _l, QString _p) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), login(_l), pass(_p)
{
    ui->setupUi(this);
///////////////

    //db.connect();
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.exec("select name, sname, tname, sex, age, bday, phone_number, adress, type_of_acces from users where login='" + login + "' and  pass ='" + pass + "';");
    int age, acces;
    QDate bday;
    bool sex;
    QString name, sname, tname, phone_number, adress;
    while(query.next()){
        name = query.value(0).toString();
        sname = query.value(1).toString();
        tname = query.value(2).toString();
        sex = query.value(3).toBool();
        age = query.value(4).toInt();
        bday = query.value(5).toDate();
        phone_number = query.value(6).toString(); adress = query.value(7).toString();
        acces = query.value(8).toInt();
    }
    user userobj(name, sname, tname, sex, age, bday, phone_number, adress, acces);
    //////////////////
    this->getdata();

}

void MainWindow::getdata()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    QSqlQueryModel *model= new QSqlQueryModel();
    query.prepare("select `id`,`name`,`sname`,`tname`,`kurs`,`departament`,`group` from students");
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QCoreApplication::exit();
}



void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    addStudent = new addStudentForm(0,this);
    addStudent->setFixedSize(addStudent->size());
    addStudent->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->parent();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query = QSqlQuery(db.getdb());
    query.prepare("delete from `students` where `id` = :id");
    int id = ui->comboBox->currentText().toInt();
    query.bindValue(":id",id);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Увага","Ви дійсно хочете видалити данні цього студента ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        query.exec();
    }
    this->getdata();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QModelIndex x = QModelIndex(index.sibling(index.row(),0));
    qDebug() << x.data();
    studentInformation infoForm;
    infoForm.setModal(true);
    infoForm.exec();
}

