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
