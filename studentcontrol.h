#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H

#include <QWidget>
#include "mainwindow.h"
#include "studentinformation.h"

namespace Ui {
class studentControl;
}

class studentControl : public QWidget
{
    Q_OBJECT

public:
    explicit studentControl(QWidget *parent = 0, class MainWindow *_prevWind = 0, int _groupid = 0, int _acces = 1);
    void getinfofromBD();
    ~studentControl();

private slots:
    void on_bbutton_clicked();

    void on_dellbutton_clicked();

    void on_edibutton_clicked();

    void openStudentInfo(int x);

    void on_viewbutton_clicked();

    void on_addSTbutton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::studentControl *ui;
    int groupID, studentID;
    class MainWindow *prevWind;
    database db;
    int acces;
    QSqlQueryModel *model;
    class addStudentForm *addStudent;
    class studentInformation *infoForm;

};

#endif // STUDENTCONTROL_H
