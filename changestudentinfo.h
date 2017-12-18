#ifndef CHANGESTUDENTINFO_H
#define CHANGESTUDENTINFO_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class changeStudentInfo;
}

class changeStudentInfo : public QWidget
{
    Q_OBJECT

public:
    explicit changeStudentInfo(QWidget *parent = 0, class MainWindow *_previousform=0, int id = 0);
    ~changeStudentInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    int  getGroupID();

private:
    Ui::changeStudentInfo *ui;
    class MainWindow *previousform;
    student st;
    int studentID;
    QSqlQuery *query;
    database db;

};

#endif // CHANGESTUDENTINFO_H
