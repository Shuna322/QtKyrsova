#ifndef WIDGET_H
#define WIDGET_H

#include "mainwindow.h"
#include "database.h"
#include <QCryptographicHash>
#include <QMessageBox>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void clearLines();
    ~Widget();

private slots:
    void on_exitbutton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_loginbutton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    database db;
    class MainWindow *form2;
};

#endif // WIDGET_H
