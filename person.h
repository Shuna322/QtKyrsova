#ifndef PERSON_H
#define PERSON_H

#include <QString>
using namespace std;
enum sex { male, female };
class person
{
protected:
    QString name, sname, tname, phone_number, adress;
    bool sex;
    int age;
    int birth_day, birth_mounth, birth_year;
public:
    person(QString _name, QString _sname, QString _tname, bool _sex, int _age, int _birth_day, int _birth_mounth, int _birth_year, QString _phone_number, QString _adress);
    person();
    ~person();
};



#endif // PERSON_H
