#ifndef GROUPCONTROL_H
#define GROUPCONTROL_H

#include <QDialog>
#include "groupchange.h"
#include "mainwindow.h"

namespace Ui {
class groupControl;
}

class groupControl : public QDialog
{
    Q_OBJECT

public:
    explicit groupControl(QWidget *parent = 0, MainWindow *_prev = 0);
    getDataFromDb();
    ~groupControl();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::groupControl *ui;
    class MainWindow *prev;
    database db;
    QSqlQueryModel *model;
    QSqlQuery *query;
    class groupchange *changeForm;
};

#endif // GROUPCONTROL_H
