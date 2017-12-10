#include "user.h"
#include <QDebug>
user::user(QString _name, QString _sname, QString _tname, bool _sex, int _age, int _birth_day, int _birth_mounth, int _birth_year, QString _phone_number, QString _adress, int _type_of_acces)
    : type_of_acces(_type_of_acces)
{
    person(_name, _sname, _tname, _sex, _age, _birth_day, _birth_mounth, _birth_year, _phone_number, _adress);
}

user::user()
{
}


user::~user()
{
}

QString user::getdebuginfo()
{
    qDebug() << name << sname << tname << sex << age << type_of_acces << phone_number;
    return name;
}

