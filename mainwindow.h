#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <database.h>
#include <user.h>
#include "addstudentform.h"
#include "showtable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString _l = "ПОМИЛКА", QString _p = "ПОМИЛКА");
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString login, pass;
    database db;
    addStudentForm *addStudent;
    showTable *sTableForm;
};

#endif // MAINWINDOW_H
