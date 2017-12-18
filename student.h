#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class student : public person
{
    bool type_of_education;  //free\paid
    int speciality, departament;
    QDate startEdu;

public:
    student();
    student(QString _name,QString _sname,QString _tname, bool _sex, QDate _bday,QString _phone_number, QString _adress, bool _type_of_education, int _speciality, int _departament, QDate _startEdu);
    void addStudentToDB();
    void replaceStudentInDB(int id);
    void getdataFromDB(int id);
    bool gettype_of_education();
    int getspeciality();
    int getdepartament();
    QDate getstartEdu();
};

#endif // STUDENT_H
