#ifndef USER_H
#define USER_H
#include "person.h"

class user :
    public person
{
    QString login, pass;
    int type_of_acces;
public:
    user(QString _name, QString _sname, QString _tname, bool _sex, QDate _bday, QString _phone_number, QString _adress, int _type_of_acces, QString _login, QString _pass);
    user();
    ~user();
    void addUserToDatabase();
};

#endif // USER_H
