#ifndef PERSON_H
#define PERSON_H
#include <QDate>
#include <QString>
using namespace std;
class person
{
protected:
    QString name, sname, tname, phone_number, adress;
    bool sex;
    int age;
    QDate bday;
public:
    person(QString _name, QString _sname, QString _tname, bool _sex, int _age, QDate _bday, QString _phone_number, QString _adress);
    person();
    ~person();
    QString getname();
    QString getsname();
    QString gettname();
    QString getphone_number();
    QString getadress();
    bool getsex();
    int getage();
    QDate getbday();


};



#endif // PERSON_H
