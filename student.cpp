#include "student.h"

student::student()
{

}

student::student(QString _name, QString _sname, QString _tname, bool _sex,  QDate _bday, QString _phone_number, QString _adress, bool _type_of_education, QString _group, QString _departament, int _kurs):
    type_of_education(_type_of_education), group(_group), departament(_departament), kurs(_kurs), person( _name, _sname, _tname, _sex, _bday, _phone_number, _adress)
{
}

void student::addStudentToDB()
{
    database db;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("insert into students (`id`, `name`, `sname`, `tname`, `sex`, `group`, `departament`,  `bday`, `phone_number`, `adress`, `type_of_education`, `kurs`)"
               "values (NULL,:name,:sname,:tname,:sex,:group,:departament,:birth_day,:phone_number,:adress,:type_of_education,:kurs)");
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
    query.bindValue(":birth_day",bday);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_education",type_of_education);
    query.bindValue(":kurs",kurs);

    if(!query.exec())
        qDebug() << query.lastError() << query.lastQuery();
    else QMessageBox::information(0,"Повідомлення","Данні успішно додані !",QMessageBox::Ok);
}

void student::replaceStudentInDB(int id)
{
    database db;
   // db.connect();
    qDebug () << id;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("replace into students (`id`, `name`, `sname`, `tname`, `sex`, `group`, `departament`,  `bday`, `phone_number`, `adress`, `type_of_education`, `kurs`)"
               "values (:id,:name,:sname,:tname,:sex,:group,:departament,:birth_day,:phone_number,:adress,:type_of_education,:kurs)");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
    query.bindValue(":birth_day",bday);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_education",type_of_education);
    query.bindValue(":kurs",kurs);
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
       group = query.value(5).toString();
       departament = query.value(6).toString();
       bday = query.value(7).toDate();
       phone_number = query.value(8).toString(); adress = query.value(9).toString();
       type_of_education = query.value(10).toInt();
       kurs = query.value(11).toInt();
   }
   qDebug() << name << sname << type_of_education << kurs << query.lastQuery();
}

bool student::gettype_of_education()
{
    return type_of_education;
}

QString student::getgroup()
{
    return group;
}

QString student::getdepartament()
{
    return departament;
}

QString student::getkurs()
{
    return (QString::number(kurs));
}
