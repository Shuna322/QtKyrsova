#include "departamentchange.h"
#include "ui_departamentchange.h"

departamentChange::departamentChange(QWidget *parent, bool _mode, int _id) :
    QDialog(parent), mode(_mode), id(_id),
    ui(new Ui::departamentChange)
{
    ui->setupUi(this);
    if(mode)
    {
        this->setWindowTitle("Редагування вітділення");
        QSqlQuery query =  QSqlQuery(db.getdb());
        QString name;
        query.prepare("select `departaments`.`name` from `departaments` where `departaments`.`id` = :id;");
        query.bindValue(":id",id);
        query.exec();
        while(query.next())
        {
            name = query.value(0).toString();
        }
        ui->lineEdit->setText(name);
    }
}

departamentChange::~departamentChange()
{
    delete ui;
}

void departamentChange::on_pushButton_clicked()
{
    QSqlQuery query =  QSqlQuery(db.getdb());
    if (!mode)
        query.prepare("insert into departaments (`id`,`name`)"
                      "values (NULL,:name)");
    else
    {
        query.prepare("update departaments set name = :name where id = :id");
        query.bindValue(":id",id);
    }
    query.bindValue(":name",ui->lineEdit->text());
    query.exec();
    qDebug() << query.lastError();
    this->hide();
}
