#ifndef ADDSTUDENTFORM_H
#define ADDSTUDENTFORM_H

#include <QWidget>
#include <student.h>
#include "database.h"
#include "mainwindow.h"

namespace Ui {
class addStudentForm;
}

class addStudentForm : public QWidget
{
    Q_OBJECT

public:
    explicit addStudentForm(QWidget *parent = 0,class MainWindow *_previousform=0);
    ~addStudentForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void checkVariables();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

private:
    Ui::addStudentForm *ui;
    class MainWindow *previousform;
};

#endif // ADDSTUDENTFORM_H
