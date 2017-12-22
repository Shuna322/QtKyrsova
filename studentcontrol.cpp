#include "studentcontrol.h"
#include "ui_studentcontrol.h"

studentControl::studentControl(QWidget *parent, MainWindow *_prevWind, int _groupid) :
    QWidget(parent), prevWind(_prevWind), groupID(_groupid),
    ui(new Ui::studentControl)
{
    ui->setupUi(this);
    studentID = 0;
    getinfofromBD();
}

void studentControl::getinfofromBD()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query.prepare("select `students`.`id`, `students`.`name`, `students`.`sname`, `students`.`tname` from students where `students`.`group` = :groupID");
    query.bindValue(":groupID", groupID);
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,30);
}

studentControl::~studentControl()
{
    delete ui;
}

void studentControl::on_bbutton_clicked()
{
    this->hide();
    prevWind->show();
}

void studentControl::on_dellbutton_clicked()
{
    QSqlQuery query = QSqlQuery(db.getdb());
    query.prepare("delete from `students` where `id` = :id");
    query.bindValue(":id",studentID);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Увага","Ви дійсно хочете видалити данні цього студента ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        query.exec();
    }
    this->getinfofromBD();
}

void studentControl::on_edibutton_clicked()
{
    addStudent = new addStudentForm(0,0,this,true,studentID);
    addStudent->setFixedSize(addStudent->size());
    this->hide();
    addStudent->show();
}

void studentControl::openStudentInfo(int x)
{
    infoForm = new studentInformation(0, x);
    infoForm->setFixedSize(infoForm->size());
    infoForm->show();
}

void studentControl::on_viewbutton_clicked()
{
    openStudentInfo(studentID);
}

void studentControl::on_addSTbutton_clicked()
{
    this->hide();
    addStudent = new addStudentForm(0,0,this,true,studentID);
    addStudent->setFixedSize(addStudent->size());
    addStudent->show();
    getinfofromBD();
}

void studentControl::on_tableView_clicked(const QModelIndex &index)
{
        QModelIndex x = QModelIndex(index.sibling(index.row(),0));
        studentID = x.data().toInt();
        ui->dellbutton->setEnabled(1); ui->edibutton->setEnabled(1); ui->viewbutton->setEnabled(1);
}

void studentControl::on_tableView_doubleClicked(const QModelIndex &index)
{
    QModelIndex x = QModelIndex(index.sibling(index.row(),0));
    openStudentInfo(x.data().toInt());
}
