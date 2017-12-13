#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "database.h"
#include <QMessageBox>
class student : protected person
{
    bool type_of_education;  //free\paid
    QString group, departament;
    int kurs;

public:
    student();
    student(QString _name,QString _sname,QString _tname, bool _sex, int _age, QDate _bday,QString _phone_number, QString _adress, bool _type_of_education, QString _group, QString _departament, int _kurs);
    void addStudentToDB();
};

#endif // STUDENT_H
