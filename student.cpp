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
    query.exec("insert into kyrsova.students values (NULL,'"+name+"','"+sname+"','"+tname+"',"+sex+","+age+","+birth_day+","+birth_mounth+","+birth_year+",'"+phone_number+"','"+adress+"',"+type_of_education+");");
}
