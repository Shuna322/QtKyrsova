#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string.h>
#include <QMainWindow>
#include "sqlheders.h"
#include "user.h"

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

private:
    Ui::MainWindow *ui;
    QString login, pass;
    QSqlDatabase db;
    user userobj;
};

#endif // MAINWINDOW_H
