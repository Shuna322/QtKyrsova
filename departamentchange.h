#ifndef DEPARTAMENTCHANGE_H
#define DEPARTAMENTCHANGE_H

#include <QDialog>
#include "departamentcontol.h"

namespace Ui {
class departamentChange;
}

class departamentChange : public QDialog
{
    Q_OBJECT

public:
    explicit departamentChange(QWidget *parent = 0, bool _mode = false, int _ID = 0);
    ~departamentChange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::departamentChange *ui;
    bool mode;
    int id;
    database db;
    QSqlQueryModel *model;
};

#endif // DEPARTAMENTCHANGE_H
