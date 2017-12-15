#include "person.h"

person::person(QString _name, QString _sname, QString _tname, bool _sex,  QDate _bday, QString _phone_number, QString _adress)
    : name(_name), sname(_sname), tname(_tname), sex(_sex), bday(_bday) , phone_number(_phone_number), adress(_adress)
{
}

person::person()
{
}


person::~person()
{
}

QString person::getname()
{
    return name;
}

QString person::getsname()
{
    return sname;
}

QString person::gettname()
{
    return tname;
}

QString person::getphone_number()
{
    return phone_number;
}

QString person::getadress()
{
    return adress;
}

bool person::getsex()
{
    return sex;
}


QDate person::getbday()
{
    return bday;
}
