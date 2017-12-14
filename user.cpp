#include "user.h"
#include <QDebug>
user::user(QString _name, QString _sname, QString _tname, bool _sex, QDate _bday, QString _phone_number, QString _adress, int _type_of_acces)
    : type_of_acces(_type_of_acces)
{
    person(_name, _sname, _tname, _sex, _bday , _phone_number, _adress);
}

user::user()
{
}


user::~user()
{
}

QString user::getdebuginfo()
{
    return name;
}

