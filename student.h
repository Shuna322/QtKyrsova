#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "database.h"

class student : protected person
{
    bool type_of_education;  //free\paid
    QString group;
    QString faculted;
public:
    student();
    student(QString _name,QString _sname,QString _tname, bool _sex, int _age, int _bday,int _bmounth,int _byear,QString _phone_number, QString _adress, bool _type_of_education, QString _group, QString _faculted);
    void addStudentToDB();
};

#endif // STUDENT_H
