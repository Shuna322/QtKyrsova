#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QModelIndex>
#include <QUrl>
#include <QDesktopServices>
#include "studentinformation.h"


MainWindow::MainWindow(QWidget *parent, QString _l, QString _p, class Widget *_prev) :
    QMainWindow(parent), prev(_prev),
    ui(new Ui::MainWindow), login(_l), pass(_p)
{
    ui->setupUi(this);
    createUserObj();
    setdepartament();
    this->getdata();
    int a = userobj.getacces();
    /*switch (a) {
    case 1:{
        ui->pushButton_2->setEnabled(0); ui->action->setEnabled(0);
        ui->pushButton_3->setEnabled(0); ui->action_2->setEnabled(0);
        ui->pushButton_5->setEnabled(0);
        ui->pushButton_6->setEnabled(0);
        ui->pushButton_7->setEnabled(0); ui->action_3->setEnabled(0);
        ui->comboBox->setEnabled(0);
        break;
    }
    case 2: {
        ui->pushButton_5->setEnabled(0);
        ui->pushButton_7->setEnabled(0);
        break;
    }
    case 3 : {
        break;
    }
    default:
        QCoreApplication::exit();
    }*/
}

void MainWindow::getdata()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query.prepare("select `groups`.`id`, `departaments`.`name`, `groups`.`name`, `groups`.`code` from `groups`, `departaments` where `groups`.`departament_code` = :ID and `departaments`.`name` = :name;");
    query.bindValue(":ID",ui->comboBox->currentIndex()+1);
    query.bindValue(":name",ui->comboBox->currentText());
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,30);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Увага","Ви дійсно хочете вийти з програми ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
        QCoreApplication::exit();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    addStudent = new addStudentForm(0,this,0,false,0);
    addStudent->setFixedSize(addStudent->size());
    addStudent->show();
    getdata();
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Увага","Ви дійсно хочете змінити користувача ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        this->hide();
        prev->show();
        prev->clearLines();
    }
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (userobj.getacces() >= 2)
    {
        QModelIndex x = QModelIndex(index.sibling(index.row(),0));
        openFormWithStudentInfo(x.data().toInt());
    }
}

void MainWindow::on_action_triggered()
{
}

void MainWindow::on_action_2_triggered()
{
}

void MainWindow::on_action_3_triggered()
{
}

void MainWindow::openFormWithStudentInfo(int x)
{
    infoForm = new studentControl(0, this, x);
    infoForm->setFixedSize(infoForm->size());
    this->hide();
    infoForm->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    QDesktopServices::openUrl(QUrl("https://i.imgur.com/xGZuM7V.png", QUrl::TolerantMode));
    QMessageBox::information(0,"Не скучайте","На досузі можете порозгадувати",QMessageBox::Ok);
}

void MainWindow::on_pushButton_5_clicked()
{
    addUser = new addUserForm(0,this);
    this->hide();
    addUser->setFixedSize(addUser->size());
    addUser->show();
}

void MainWindow::createUserObj()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.exec("select name, sname, tname, sex, bday, phone_number, adress, type_of_acces from users where login='" + login + "' and  pass ='" + pass + "';");
    int acces;
    QDate bday;
    bool sex;
    QString name, sname, tname, phone_number, adress;
    while(query.next()){
        name = query.value(0).toString();
        sname = query.value(1).toString();
        tname = query.value(2).toString();
        sex = query.value(3).toBool();
        bday = query.value(4).toDate();
        phone_number = query.value(5).toString(); adress = query.value(6).toString();
        acces = query.value(7).toInt();
    }
    userobj = user(name, sname, tname, sex, bday, phone_number, adress, acces, login, pass);

}

void MainWindow::setdepartament()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query.prepare("select `departaments`.`name` from `departaments`;");
    query.exec();
    model->setQuery(query);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    getdata();
}

void MainWindow::on_action_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_action_7_triggered()
{
    QMessageBox::information(this,"Про автора:","Made by Alex \"ShunA\" Pokydko");
}

void MainWindow::on_action_5_triggered()
{
    QMessageBox::information(this,"Про програму:","Версія 0.8.9а \nЕтапи розробки можна переглянути на \nhttps://github.com/Shuna322/aloha-shaka-laka/");

}
