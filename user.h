#ifndef USER_H
#define USER_H
#include "person.h"
#include <string.h>

enum accesType{administrator, teacher, visitor};
class user :
    protected person
{
    int type_of_acces;
public:
    user(int _number, QString _name, QString _sname, QString _tname, bool _sex, int _age, int _birth_day, int _birth_mounth, int _birth_year, QString _phone_number, QString _adress, int _type_of_acces);
    user();
    ~user();
    QString getdebuginfo();
};

#endif // USER_H
