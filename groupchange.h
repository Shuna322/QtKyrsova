#ifndef GROUPCHANGE_H
#define GROUPCHANGE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class groupchange;
}

class groupchange : public QDialog
{
    Q_OBJECT

public:
    explicit groupchange(QWidget *parent = 0, bool _mode = false, int _id = 0);
    void getDepartament();
    void getSpetList();
    ~groupchange();

private slots:
    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::groupchange *ui;
    bool mode;
    int id;
    database db;
    QSqlQueryModel *model;
    QSqlQuery *query;
};

#endif // GROUPCHANGE_H
