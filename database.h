#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <Qsql>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

class database
{
    QSqlDatabase db;
public:

    database();
    void connect();
    void connclose();
    QSqlDatabase getdb();
    bool loginVerification(QString _l, QString _p);
   //void addstudent(QString _name,QString _sname,QString _tname, bool _sex, int _age, int _bday,int _bmounth,int _byear,QString _phone_number, QString _adress, bool _type_of_education);
};

#endif // DATABASE_H
