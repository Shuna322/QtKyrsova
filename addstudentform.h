#ifndef ADDSTUDENTFORM_H
#define ADDSTUDENTFORM_H

#include <QWidget>

namespace Ui {
class addStudentForm;
}

class addStudentForm : public QWidget
{
    Q_OBJECT

public:
    explicit addStudentForm(QWidget *parent = 0);
    ~addStudentForm();

private:
    Ui::addStudentForm *ui;
};

#endif // ADDSTUDENTFORM_H
