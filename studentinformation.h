#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H

#include <QDialog>
#include "student.h"

namespace Ui {
class studentInformation;
}

class studentInformation : public QDialog
{
    Q_OBJECT

public:
    explicit studentInformation(QWidget *parent = 0, int id=0);
    QString countAge(QDate _bday);
    ~studentInformation();

private:
    Ui::studentInformation *ui;
    int id;
    student st;
};

#endif // STUDENTINFORMATION_H
