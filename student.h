#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "database.h"

class student : protected person
{
    bool type_of_education;  //free\paid

public:
    student();
    student(QString _name,QString _sname,QString _tname, bool _sex, int _age, int _bday,int _bmounth,int _byear,QString _phone_number, QString _adress, bool _type_of_education);
    void addStudentToDB();
};

#endif // STUDENT_H
