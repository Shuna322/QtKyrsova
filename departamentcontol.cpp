#include "departamentcontol.h"
#include "ui_departamentcontol.h"

departamentContol::departamentContol(QWidget *parent, class MainWindow *_prev) :
    QWidget(parent),prev(_prev),
    ui(new Ui::departamentContol)
{
    ui->setupUi(this);
    getDepartamentList();
}

departamentContol::~departamentContol()
{
    delete ui;
}

void departamentContol::getDepartamentList()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query.prepare("select `departaments`.`name` from `departaments`;");
    query.exec();
    model->setQuery(query);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
}

int departamentContol::getid()
{
    int id;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("select `departaments`.`id` from `departaments` where `departaments`.`name` = :name;");
    query.bindValue(":name",ui->comboBox->currentText());
    query.exec();
    while(query.next())
    {
        id = query.value(0).toInt();
    }
    return id;
}

void departamentContol::on_bbutton_clicked()
{
    this->hide();
    prev->setdepartament();
    prev->show();
}

void departamentContol::on_addbutton_clicked()
{
    changeform = new departamentChange ();
    changeform->setFixedSize(changeform->size());
    changeform->exec();
    getDepartamentList();
}

void departamentContol::on_editbutton_clicked()
{
    changeform = new departamentChange (0,true,getid());
    changeform->setFixedSize(changeform->size());
    changeform->exec();
    getDepartamentList();
}

void departamentContol::on_dellbutton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Увага","Группи і студенти данного відділення також будуть видалені !\nВи дійсно хочете видалити данне відділення ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        int dep_id;
        QSqlQuery query = QSqlQuery(db.getdb());
        query.prepare("select `id` from `departaments` where `departaments`.`name` = :dep_name;");
        query.bindValue(":dep_name",ui->comboBox->currentText());
        query.exec();
        while(query.next())
        {
           dep_id = query.value(0).toInt();
        }
        query.prepare("delete from `students` where `group` in(select `id` from `groups` where `department_code` = :dep_id;");
        query.bindValue(":dep_id",dep_id);
        query.exec();
        query.prepare("delete from `groups` where `groups`.`departament_code` = :dep_id");
        query.bindValue(":dep_id",dep_id);
        query.exec();
        query.prepare("delete from `departaments` where `departaments`.`id` = :dep_id");
        query.bindValue(":dep_id",dep_id);
        query.exec();
        getDepartamentList();
    }
}
