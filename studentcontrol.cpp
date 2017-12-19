#include "studentcontrol.h"
#include "ui_studentcontrol.h"

studentControl::studentControl(QWidget *parent, MainWindow *_prevWind, int _groupid) :
    QWidget(parent), prevWind(_prevWind), groupID(_groupid),
    ui(new Ui::studentControl)
{
    ui->setupUi(this);
    getinfofromBD();
}

void studentControl::getinfofromBD()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query.prepare("select students.id, students.name, students.sname, students.tname from students where group = :groupID");
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
