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
    user(QString _name, QString _sname, QString _tname, bool _sex, QDate _bday, QString _phone_number, QString _adress, int _type_of_acces);
    user();
    ~user();
    QString getdebuginfo();
};

#endif // USER_H
