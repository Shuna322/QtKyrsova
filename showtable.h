#ifndef SHOWTABLE_H
#define SHOWTABLE_H

#include <QWidget>
#include "database.h"
namespace Ui {
class showTable;
}

class showTable : public QWidget
{
    Q_OBJECT

public:
    explicit showTable(QWidget *parent = 0);
    ~showTable();

private:
    Ui::showTable *ui;
    database db;
    QSqlTableModel *model;
};

#endif // SHOWTABLE_H
