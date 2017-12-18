#include "student.h"

student::student()
{

}

student::student(QString _name, QString _sname, QString _tname, bool _sex,  QDate _bday, QString _phone_number, QString _adress, bool _type_of_education, int _group, QDate _startEdu):
    type_of_education(_type_of_education), group(_group) , startEdu(_startEdu), person( _name, _sname, _tname, _sex, _bday, _phone_number, _adress)
{
        query = new QSqlQuery(db.getdb());
}

void student::addStudentToDB()
{
    database db;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("insert into students (`id`, `name`, `sname`, `tname`, `sex`, `group`, `bday`, `phone_number`, `adress`, `type_of_education`, `startEdu`)"
               "values (NULL,:name,:sname,:tname,:sex,:group,:birth_day,:phone_number,:adress,:type_of_education,:startEdu)");
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":group",group);
    query.bindValue(":birth_day",bday);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_education",type_of_education);
    query.bindValue(":startEdu",startEdu);

    if(!query.exec())
        qDebug() << query.lastError() << query.lastQuery();
    else QMessageBox::information(0,"Повідомлення","Данні успішно додані !",QMessageBox::Ok);
}

void student::replaceStudentInDB(int id)
{
    database db;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("replace into students (`id`, `name`, `sname`, `tname`, `sex`, `group`, `bday`, `phone_number`, `adress`, `type_of_education`, `startEdu`)"
               "values (:id,:name,:sname,:tname,:sex,:group,:birth_day,:phone_number,:adress,:type_of_education,:startEdu)");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":group",group);
    query.bindValue(":birth_day",bday);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_education",type_of_education);
    query.bindValue(":startEdu",startEdu);

    if(!query.exec())
        qDebug() << query.lastError() << "\n" << query.lastQuery();
    else {
        QMessageBox::information(0,"Повідомлення","Данні успішно оновлені !",QMessageBox::Ok);
        qDebug() << query.lastError() << "\n" << query.lastQuery();
    }
}

void student::getdataFromDB(int id)
{
   database db;
   QSqlQuery query =  QSqlQuery(db.getdb());
   query.prepare("select * from students where id = :id;");
   query.bindValue(":id",id);
   query.exec();
   while(query.next()){
       name = query.value(1).toString();
       sname = query.value(2).toString();
       tname = query.value(3).toString();
       sex = query.value(4).toBool();
       group = query.value(5).toInt();
       bday = query.value(6).toDate();
       phone_number = query.value(7).toString(); adress = query.value(8).toString();
       type_of_education = query.value(9).toInt();
       startEdu = query.value(10).toDate();
   }
}

bool student::gettype_of_education()
{
    return type_of_education;
}


QDate student::getstartEdu()
{
    return startEdu;
}

QString student::getGroupName()
{
    QString temp;
    query->prepare("select `name` from groups where `id` = :id");
    query->bindValue(":id",group);
    query->exec();
    while(query->next()) temp=query->value(0).toString();
    return temp;
}

QString student::getDepartamentName()
{
    QString temp;
    query->prepare("select departaments.name from departaments,groups where groups.id = :id and departaments.id = groups.departament_code");
    query->bindValue(":id",group);
    query->exec();
    while(query->next()) temp=query->value(0).toString();
    return temp;
}

QString student::getGroupCode()
{
    QString temp;

    query->prepare("select `code` from groups where `id` = :id");
    query->bindValue(":id",group);
    query->exec();
    while(query->next()) temp=query->value(0).toString();
    return temp;
}

