#include "person.h"

person::person(QString _name, QString _sname, QString _tname, bool _sex, int _age, int _birth_day, int _birth_mounth, int _birth_year, QString _phone_number, QString _adress)
    : name(_name), sname(_sname), tname(_tname), sex(_sex), age(_age), birth_day(_birth_day), birth_mounth(_birth_mounth), birth_year(_birth_year), phone_number(_phone_number), adress(_adress)
{
}

person::person()
{
}


person::~person()
{
}
