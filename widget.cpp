#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("kyrsova");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open())
        qDebug() << db.lastError().text();
    else qDebug() << "До бази даних підключився!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_exitbutton_clicked()
{
    QCoreApplication::exit();
}

void Widget::on_checkBox_toggled(bool checked)
{
    if (!checked) ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    else ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
}

void Widget::on_loginbutton_clicked()
{
    QSqlQuery query =  QSqlQuery(db);
    query.exec("select * from users where login='" + ui->lineEdit->text() + "' and  pass ='" + ui->lineEdit_2->text() + "';");
    int i = 0;
    while(query.next()) i++;
    if (i == 1){ qDebug() << "Логін і Пароль правильний !";
    this->hide();
        form2 = new MainWindow(this);
        form2->show();
    }
    else qDebug() << "Логін і Пароль не правильний !";
}
