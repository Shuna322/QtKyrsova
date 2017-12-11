#include "student.h"

student::student()
{

}

student::student(QString _name, QString _sname, QString _tname, bool _sex, int _age, int _bday, int _bmounth, int _byear, QString _phone_number, QString _adress, bool _type_of_education):
    type_of_education(_type_of_education)
{
    person( _name, _sname, _tname, _sex, _age, _bday, _bmounth, _byear, _phone_number, _adress);
}

void student::addStudentToDB()
{
    database db;
    db.connect();
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("insert into students (id, name, sname, tname, sex, age, bday, bmounth, byear, phone_number, adress, type_of_education)"
               "values (NULL,:name,:sname,:tname,:sex,:age,:birth_day,:birth_mounth,:birth_year,:phone_number,:adress,:type_of_education)");
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":age",age);
    query.bindValue(":birth_day",birth_day);
    query.bindValue(":birth_mounth",birth_mounth);
    query.bindValue(":birth_year",birth_year);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_education",type_of_education);
    qDebug() << name << sname << tname << sex << age << birth_day << birth_mounth << birth_year << phone_number << adress << type_of_education;


    //  "values (NULL,'"+name+"','"+sname+"','"+tname+"',"+sex+","+age+","+birth_day+","+birth_mounth+","+birth_year+",'"+phone_number+"','"+adress+"',"+type_of_education+");");

    if(!query.exec())
        qDebug() << query.lastError();
}
