#ifndef ADDUSERFORM_H
#define ADDUSERFORM_H
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class addUserForm;
}

class addUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit addUserForm(QWidget *parent = 0, MainWindow *_prevWindow = 0);
    ~addUserForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addUserForm *ui;
    MainWindow *prev;
};

#endif // ADDUSERFORM_H
