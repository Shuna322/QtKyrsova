#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "widget.h"
#include <QMainWindow>
#include <database.h>
#include <user.h>
#include "addstudentform.h"
#include "changestudentinfo.h"
#include "adduserform.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString _l = "ПОМИЛКА", QString _p = "ПОМИЛКА", class Widget *_prev=0);
    void getdata();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void openFormWithStudentInfo(int x);

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void createUserObj();

private:
    Ui::MainWindow *ui;
    QString login, pass;
    database db;
    class addStudentForm *addStudent;
    class changeStudentInfo *changeStudent;
    class Widget *prev;
    class addUserForm *addUser;
    QSqlQueryModel *model;
    user userobj;

};

#endif // MAINWINDOW_H
