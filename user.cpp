#include "user.h"
#include <QDebug>
user::user(QString _name, QString _sname, QString _tname, bool _sex, QDate _bday, QString _phone_number, QString _adress, int _type_of_acces, QString _login, QString _pass)
    : type_of_acces(_type_of_acces), login(_login), pass(_pass), person(_name, _sname, _tname, _sex, _bday , _phone_number, _adress)
{

}

user::user()
{
}


user::~user()
{
}

void user::addUserToDatabase()
{
    database db;
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.prepare("insert into `users` (`id`, `login`, `pass`, `name`, `sname`, `tname`, `sex`, `bday`, `phone_number`, `adress`, `type_of_acces`)"
               "values (NULL,:login,:pass,:name,:sname,:tname,:sex,:birth_day,:phone_number,:adress,:type_of_acces)");
    query.bindValue(":login",login);
    query.bindValue(":pass",pass);
    query.bindValue(":name",name);
    query.bindValue(":sname",sname);
    query.bindValue(":tname",tname);
    query.bindValue(":sex",sex);
    query.bindValue(":birth_day",bday);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":adress",adress);
    query.bindValue(":type_of_acces",type_of_acces);

    if(!query.exec())
    qDebug () << query.lastError();
    else QMessageBox::information(0,"Повідомлення","Данні успішно додані !",QMessageBox::Ok);
}

int user::getacces()
{
    return type_of_acces;
}

QString user::getlogin()
{
    return login;
}

QString user::getpass()
{
    return pass;
}

