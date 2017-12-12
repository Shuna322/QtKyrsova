#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent, QString _l, QString _p) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), login(_l), pass(_p)
{
    ui->setupUi(this);
///////////////

    db.connect();
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
    qDebug() << name << sname << tname << sex << age << acces;
    user userobj(name, sname, tname, sex, age, bday, phone_number, adress, acces);
    //////////////////
    QSqlQueryModel *model= new QSqlQueryModel();
    query.prepare("select `id`,`name`,`sname`,`tname`,`kurs`,`departament`,`group` from students");
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);

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
    addStudent->show();
}
