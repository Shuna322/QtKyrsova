#ifndef ADDUSERFORM_H
#define ADDUSERFORM_H
#include "mainwindow.h"
#include "widget.h"
#include <QWidget>
#include <QDate>

namespace Ui {
class addUserForm;
}

class addUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit addUserForm(QWidget *parent = 0, class MainWindow *_prevWindow = 0, class Widget *_loginform = 0);
    ~addUserForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::addUserForm *ui;
    class MainWindow *prev;
    class Widget *loginform;
    database db;
    void checkVariables();
};

#endif // ADDUSERFORM_H
