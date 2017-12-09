#include "database.h"

database::database()
{

}

void database::connect()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("kyrsova");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open())
        qDebug() << db.lastError().text();
    else qDebug() << "До бази даних підключився!";
}

QSqlDatabase database::getdb()
{
    return db;
}
