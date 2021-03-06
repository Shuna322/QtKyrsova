#include "groupcontrol.h"
#include "ui_groupcontrol.h"

groupControl::groupControl(QWidget *parent, MainWindow *_prev) :
    QDialog(parent), prev(_prev),
    ui(new Ui::groupControl)
{
    ui->setupUi(this);
    getDataFromDb();
}

groupControl::getDataFromDb()
{
    query = new QSqlQuery(db.getdb());
    query->prepare("select `name` from `departaments`");
    query->exec();
    model= new QSqlQueryModel();
    model->setQuery(*query);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
}

groupControl::~groupControl()
{
    delete ui;
}

void groupControl::on_comboBox_currentIndexChanged(int index)
{
    query = new QSqlQuery(db.getdb());
    int id;
    query->prepare("select `departaments`.`id` from `departaments` where `departaments`.`name` = :name;");
    query->bindValue(":name",ui->comboBox->currentText());
    query->exec();
    while(query->next())
    {
        id = query->value(0).toInt();
    }
    //////
    model= new QSqlQueryModel();
    query->prepare("select distinct `name` from groups where `departament_code` = :index");
    query->bindValue(":index",id);
    query->exec();
    model->setQuery(*query);
    ui->comboBox_2->setModel(model);
    ui->comboBox_2->setModelColumn(0);
}

void groupControl::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    query = new QSqlQuery(db.getdb());
    model= new QSqlQueryModel();
    query->prepare("select distinct `code` from groups where `name` = :name");
    query->bindValue(":name",arg1);
    query->exec();
    model->setQuery(*query);
    ui->comboBox_3->setModel(model);
    ui->comboBox_3->setModelColumn(0);
}

void groupControl::on_pushButton_4_clicked()
{
    this->hide();
    prev->show();
}

void groupControl::on_pushButton_clicked()
{
    changeForm = new groupchange(0,this);
    changeForm->exec();
}

void groupControl::on_pushButton_2_clicked()
{
    query = new QSqlQuery(db.getdb());
    int groupID;
    query->prepare("select `groups`.`id` from `groups` where `groups`.`code` = :name;");
    query->bindValue(":name",ui->comboBox_3->currentText());
    query->exec();
    while(query->next())
    {
        groupID = query->value(0).toInt();
    }
    changeForm = new groupchange(0,this,true,groupID);
    changeForm->exec();
}

void groupControl::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Увага","Студенти данної групи також будуть видалені !\nВи дійсно хочете видалити данну групу ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        int groupID;
        QSqlQuery query = QSqlQuery(db.getdb());
        query.prepare("select `id` from `groups` where `groups`.`code` = :code;");
        query.bindValue(":code",ui->comboBox_3->currentText());
        query.exec();
        while(query.next())
        {
           groupID = query.value(0).toInt();
        }
        query.prepare("delete from `students` where `students`.`group` = :id;");
        query.bindValue(":id",groupID);
        query.exec();
        query.prepare("delete from `groups` where `groups`.`code` = '"+ui->comboBox_3->currentText()+"'");
        query.exec();
    }
    qDebug() << query->lastError();
    getDataFromDb();
}
