#ifndef DEPARTAMENTCONTOL_H
#define DEPARTAMENTCONTOL_H

#include <QWidget>
#include "mainwindow.h"
#include "departamentchange.h"

namespace Ui {
class departamentContol;
}

class departamentContol : public QWidget
{
    Q_OBJECT

public:
    explicit departamentContol(QWidget *parent = 0, class MainWindow *_prev = 0);
    ~departamentContol();
    void getDepartamentList();
    int getid();

private slots:
    void on_bbutton_clicked();

    void on_addbutton_clicked();

    void on_editbutton_clicked();

    void on_dellbutton_clicked();

private:
    Ui::departamentContol *ui;
    class MainWindow *prev;
    database db;
    QSqlQueryModel *model;
    class departamentChange *changeform;
};

#endif // DEPARTAMENTCONTOL_H
