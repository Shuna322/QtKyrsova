#ifndef SHOWTABLE_H
#define SHOWTABLE_H

#include <QWidget>
#include "database.h"
<<<<<<< HEAD

=======
>>>>>>> 6df2e3b452843429a89e4e9b68bea3b746dabcd2
namespace Ui {
class showTable;
}

class showTable : public QWidget
{
    Q_OBJECT

public:
    explicit showTable(QWidget *parent = 0);
    ~showTable();

private slots:
    void on_pushButton_clicked();

private:
    Ui::showTable *ui;
    database db;
<<<<<<< HEAD
=======
    QSqlTableModel *model;
>>>>>>> 6df2e3b452843429a89e4e9b68bea3b746dabcd2
};

#endif // SHOWTABLE_H
