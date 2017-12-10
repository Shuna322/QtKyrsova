#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
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
    QByteArray s = ui->lineEdit_2->text().toLocal8Bit();
    QByteArray hash = QCryptographicHash::​hash(ui->lineEdit_2->text().toLocal8Bit(), QCryptographicHash::Md5);
    qDebug() << hash;
    db.connect();
    QSqlQuery query =  QSqlQuery(db.getdb());
    query.exec("select * from users where login='" + ui->lineEdit->text() + "' and  pass ='" + ui->lineEdit_2->text() + "';");
    int i = 0;
    while(query.next()) i++;
    if (i == 1){ qDebug() << "Логін і Пароль правильний !";
    this->hide();
        form2 = new MainWindow(this,ui->lineEdit->text(),ui->lineEdit_2->text());
        form2->show();
    }
    else qDebug() << "Логін і Пароль не правильний !";
}
