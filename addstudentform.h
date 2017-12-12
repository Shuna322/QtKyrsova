#ifndef ADDSTUDENTFORM_H
#define ADDSTUDENTFORM_H

#include <QWidget>
#include <QMainWindow>
#include <student.h>
#include "database.h"

namespace Ui {
class addStudentForm;
}

class addStudentForm : public QWidget
{
    Q_OBJECT

public:
    explicit addStudentForm(QWidget *parent = 0,QMainWindow *_previousform=0);
    ~addStudentForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addStudentForm *ui;
    QMainWindow *previousform;
};

#endif // ADDSTUDENTFORM_H
