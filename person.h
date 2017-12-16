#ifndef PERSON_H
#define PERSON_H
#include <QDate>
#include <QString>
#include "database.h"
#include <QMessageBox>
class person
{
protected:
    QString name, sname, tname, phone_number, adress;
    bool sex;
    QDate bday;
public:
    person(QString _name, QString _sname, QString _tname, bool _sex, QDate _bday, QString _phone_number, QString _adress);
    person();
    ~person();
    QString getname();
    QString getsname();
    QString gettname();
    QString getphone_number();
    QString getadress();
    bool getsex();
    QDate getbday();


};



#endif // PERSON_H
