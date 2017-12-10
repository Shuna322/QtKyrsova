#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>
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

class database
{
    QSqlDatabase db;
public:

    database();
    void connect();
    QSqlDatabase getdb();
};

#endif // DATABASE_H
