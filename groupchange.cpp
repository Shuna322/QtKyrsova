#include "groupchange.h"
#include "ui_groupchange.h"

groupchange::groupchange(QWidget *parent, bool _mode, int _id) :
    QDialog(parent), mode(_mode), id(_id),
    ui(new Ui::groupchange)
{
    ui->setupUi(this);
    getDepartament();
    if (mode)
    {
        this->setWindowTitle("Редагування групу");
        QSqlQuery query =  QSqlQuery(db.getdb());
        QString depName, spesName, groupName;
        query.prepare("select `departaments`.`name`, `groups`.`name`, `groups`.`code` from `departaments`, `groups` where `departaments`.`id` = `groups`.`departament_code` and `groups`.`id` = :id ;");
        query.bindValue(":id",id);
        query.exec();
        while(query.next())
        {
            depName = query.value(0).toString();
            spesName = query.value(1).toString();
            groupName = query.value(2).toString();
        }
        ui->comboBox->setCurrentText(depName);
        ui->radioButton->setChecked(1);
        ui->comboBox_2->setCurrentText(spesName);
        ui->lineEdit_2->setText(groupName);
        ui->pushButton->setText("Зберегти зміни");
    }
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

void groupchange::on_pushButton_clicked()
{
    QSqlQuery query =  QSqlQuery(db.getdb());

    int _id;
    query.prepare("select `departaments`.`id` from `departaments` where `departaments`.`name` = :name;");
    query.bindValue(":name",ui->comboBox->currentText());
    query.exec();
    while(query.next())
    {
        _id = query.value(0).toInt();
    }

    if (!mode)
        query.prepare("insert into groups (`id`,`name`,`code`,`departament_code`)"
                      "values (NULL,:name,:code,:dep_code)");
    else
    {
        query.prepare("update groups set name = :name, code = :code, departament_code = :dep_code where id = :id");
        query.bindValue(":id",id);
    }
    query.bindValue(":name",ui->lineEdit->text());
    if(ui->radioButton->isChecked())
    query.bindValue(":code",ui->comboBox_2->currentText());
    else if (ui->radioButton_2->isChecked())
        query.bindValue(":code",ui->lineEdit_2->text());
    query.bindValue(":dep_code",_id);
    query.exec();
    qDebug() << query.lastError();
    this->hide();
}
