#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class studentControl;
}

class studentControl : public QWidget
{
    Q_OBJECT

public:
    explicit studentControl(QWidget *parent = 0, MainWindow *_prevWind = 0, int _groupid = 0);
    void getinfofromBD();
    ~studentControl();

private slots:
    void on_bbutton_clicked();

private:
    Ui::studentControl *ui;
    int groupID, studentID;
    MainWindow *prevWind;
    database db;
    QSqlQueryModel *model;
};

#endif // STUDENTCONTROL_H
