#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "database.h"
#include <QMessageBox>
class student : public person
{
    bool type_of_education;  //free\paid
    QString group, departament;
    int kurs;

public:
    student();
    student(QString _name,QString _sname,QString _tname, bool _sex, QDate _bday,QString _phone_number, QString _adress, bool _type_of_education, QString _group, QString _departament, int _kurs);
    void addStudentToDB();
    void replaceStudentInDB(int id);
    void getdataFromDB(int id);
    bool gettype_of_education();
    QString getgroup();
    QString getdepartament();
    QString getkurs();
};

#endif // STUDENT_H
