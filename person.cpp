#include "person.h"

person::person(QString _name, QString _sname, QString _tname, bool _sex, int _age, QDate _bday, QString _phone_number, QString _adress)
    : name(_name), sname(_sname), tname(_tname), sex(_sex), age(_age), bday(_bday) , phone_number(_phone_number), adress(_adress)
{
}

person::person()
{
}


person::~person()
{
}
