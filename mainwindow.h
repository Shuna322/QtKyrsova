#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "widget.h"
#include <QMainWindow>
#include <database.h>
#include <user.h>
#include "addstudentform.h"
#include "studentcontrol.h"
#include "adduserform.h"
#include "departamentcontol.h"
#include <QMessageBox>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString _l = "ПОМИЛКА", QString _p = "ПОМИЛКА", class Widget *_prev=0);
    void getdata();
    void setdepartament();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void openGroupInfo(int x);

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void createUserObj();

    void on_comboBox_currentIndexChanged(int index);

    void on_action_Qt_triggered();

    void on_action_7_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_action_4_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString login, pass;
    database db;
    class addStudentForm *addStudent;
    class Widget *prev;
    class addUserForm *addUser;
    QSqlQueryModel *model;
    class studentControl *infoForm;
    class departamentContol *depForm;
    user userobj;
    int curentID;
};

#endif // MAINWINDOW_H
