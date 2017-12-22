#include "groupchange.h"
#include "ui_groupchange.h"

groupchange::groupchange(QWidget *parent, bool _mode, int _id) :
    QDialog(parent), mode(_mode), id(_id),
    ui(new Ui::groupchange)
{
    ui->setupUi(this);
    getDepartament();
}

void groupchange::getDepartament()
{
    query = new QSqlQuery(db.getdb());
    query->prepare("select `name` from `departaments`");
    query->exec();
    model= new QSqlQueryModel();
    model->setQuery(*query);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(0);
}

void groupchange::getSpetList()
{
    int _id;
    query->prepare("select `departaments`.`id` from `departaments` where `departaments`.`name` = :name;");
    query->bindValue(":name",ui->comboBox->currentText());
    query->exec();
    while(query->next())
    {
        _id = query->value(0).toInt();
    }
    model= new QSqlQueryModel();
    query->prepare("select distinct `groups`.`name` from `groups`, `departaments` where `groups`.`departament_code` = :ID and `departaments`.`name` = :name;");
    query->bindValue(":ID",_id);
    query->bindValue(":name",ui->comboBox->currentText());
    query->exec();
    model->setQuery(*query);
    ui->comboBox_2->setModel(model);
}

groupchange::~groupchange()
{
    delete ui;
}

void groupchange::on_radioButton_toggled(bool checked)
{
    if (checked)
    {
        ui->comboBox_2->setEnabled(1);
        getSpetList();
    }
    else
    {
        ui->comboBox_2->clear();
        ui->comboBox_2->setEnabled(0);
    }
}

void groupchange::on_radioButton_2_toggled(bool checked)
{
    if (checked)
        ui->lineEdit->setEnabled(1);
    else
        ui->lineEdit->setEnabled(0);
}

void groupchange::on_comboBox_currentIndexChanged(const QString &arg1)
{
    getSpetList();
}
