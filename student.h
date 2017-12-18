#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class student : public person
{
    bool type_of_education;  //free\paid
    int group;
    QDate startEdu;
    QSqlQuery *query;
    database db;
public:
    student();
    student(QString _name,QString _sname,QString _tname, bool _sex, QDate _bday,QString _phone_number, QString _adress, bool _type_of_education, int _group, QDate _startEdu);
    void addStudentToDB();
    void replaceStudentInDB(int id);
    void getdataFromDB(int id);
    bool gettype_of_education();
    QDate getstartEdu();
    QString getGroupName();
    QString getDepartamentName();
    QString getGroupCode();
};

#endif // STUDENT_H
