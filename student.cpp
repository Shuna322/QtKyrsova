#include "student.h"

student::student()
{

}

student::student(QString _name, QString _sname, QString _tname, bool _sex, int _age, QDate _bday, QString _phone_number, QString _adress, bool _type_of_education, QString _group, QString _departament, int _kurs):
    type_of_education(_type_of_education), group(_group), departament(_departament), kurs(_kurs), person( _name, _sname, _tname, _sex, _age, _bday, _phone_number, _adress)
{
}

void student::addStudentToDB()
{
    database db;
   // db.connect();
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("insert into students (`id`, `name`, `sname`, `tname`, `sex`, `group`, `departament`, `age`, `bday`, `phone_number`, `adress`, `type_of_education`, `kurs`)"
               "values (NULL,:name,:sname,:tname,:sex,:group,:departament,:age,:birth_day,:phone_number,:adress,:type_of_education,:kurs)");
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
    query.bindValue(":age",age);
    query.bindValue(":group",group);
    query.bindValue(":departament",departament);
    query.bindValue(":birth_day",bday);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_education",type_of_education);
    query.bindValue(":kurs",kurs);

   // qDebug() << name << sname << tname << sex << age << birth_day << birth_mounth << birth_year << phone_number << adress << type_of_education;


    //  "values (NULL,'"+name+"','"+sname+"','"+tname+"',"+sex+","+age+","+birth_day+","+birth_mounth+","+birth_year+",'"+phone_number+"','"+adress+"',"+type_of_education+");");

    if(!query.exec())
        qDebug() << query.lastError();
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
       age = query.value(7).toInt();
       bday = query.value(8).toDate();
       phone_number = query.value(9).toString(); adress = query.value(10).toString();
       type_of_education = query.value(11).toInt();
       kurs = query.value(12).toInt();
   }
   qDebug() << name << sname << type_of_education << kurs << query.lastQuery();
}
