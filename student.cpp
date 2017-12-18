#include "student.h"

student::student()
{

}

student::student(QString _name, QString _sname, QString _tname, bool _sex,  QDate _bday, QString _phone_number, QString _adress, bool _type_of_education, int _speciality, int _departament, QDate _startEdu):
    type_of_education(_type_of_education), speciality(_speciality), departament(_departament), startEdu(_startEdu), person( _name, _sname, _tname, _sex, _bday, _phone_number, _adress)
{
}

void student::addStudentToDB()
{
    database db;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("insert into students (`id`, `name`, `sname`, `tname`, `sex`, `speciality`, `departament`,  `bday`, `phone_number`, `adress`, `type_of_education`, `startEdu`)"
               "values (NULL,:name,:sname,:tname,:sex,:speciality,:departament,:birth_day,:phone_number,:adress,:type_of_education,:startEdu)");
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":speciality",speciality);
    query.bindValue(":departament",departament);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
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
    query.prepare("replace into students (`id`, `name`, `sname`, `tname`, `sex`, `speciality`, `departament`,  `bday`, `phone_number`, `adress`, `type_of_education`, `startEdu`)"
               "values (:id,:name,:sname,:tname,:sex,:speciality,:departament,:birth_day,:phone_number,:adress,:type_of_education,:startEdu)");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":speciality",speciality);
    query.bindValue(":departament",departament);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
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
       speciality = query.value(5).toInt();
       departament = query.value(6).toInt();
       bday = query.value(7).toDate();
       phone_number = query.value(8).toString(); adress = query.value(9).toString();
       type_of_education = query.value(10).toInt();
       startEdu = query.value(11).toDate();
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

QString student::getspeciality()
{
    return speciality;
}

QString student::getdepartament()
{
    return departament;
}

