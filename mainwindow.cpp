#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent, QString _l, QString _p) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), login(_l), pass(_p)
{
    ui->setupUi(this);

    ///////////////////
    QSqlQuery query =  QSqlQuery(db);
    query.exec("select id, name, sname, tname, sex, age, bday, bmounth, byear, phone_number, adress, type_of_acces from userswhere login='" + login + "' and  pass ='" + pass + "';");
    int id, age, bday, bmounth, byear, acces;
    bool sex;
    QString name, sname, tname, phone_number, adress;
    while(query.next()){
        id = query.value(0).toInt();
        name = query.value(1).toString();
        sname = query.value(2).toString();
        tname = query.value(3).toString();
        sex = query.value(4).toBool();
        age = query.value(5).toInt();
        bday = query.value(6).toInt(); bmounth = query.value(7).toInt(); byear = query.value(8).toInt();
        phone_number = query.value(9).toString(); adress = query.value(10).toString();
        acces = query.value(11).toInt();
    }
    qDebug() << id << name << sname << tname << sex << age << acces;
    user userobj(id, name, sname, tname, sex, age, bday, bmounth, byear, phone_number, adress, acces);
    userobj.getdebuginfo();
    //////////////////
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
    ui->lineEdit->text() = userobj.getdebuginfo();
}

