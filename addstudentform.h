#ifndef ADDSTUDENTFORM_H
#define ADDSTUDENTFORM_H

#include <QWidget>
#include <student.h>
#include "database.h"
#include "mainwindow.h"
#include "studentcontrol.h"

namespace Ui {
class addStudentForm;
}

class addStudentForm : public QWidget
{
    Q_OBJECT

public:
    explicit addStudentForm(QWidget *parent = 0,class MainWindow *_previousform=0, class studentControl *_prevStCon = 0, bool _changeInfoForm = 0, int _studentID = 0);
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

    void on_comboBox_4_currentIndexChanged(int index);

    int getGroupID();

    void loadDepartamentFromDB();

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void loadStudentDataFromBD();

private:
    Ui::addStudentForm *ui;
    class MainWindow *previousform;
    class studentControl *prevStCon;
    QSqlQuery *query;
    QSqlQueryModel *model;
    database db;
    bool changeInfoForm;
    int studentID;
    student st;
};

#endif // ADDSTUDENTFORM_H
