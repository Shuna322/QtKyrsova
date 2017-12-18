#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    db.connect();
}

void Widget::clearLines()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
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
    QString hashStr = QString("%1").arg(QString(QCryptographicHash::hash(ui->lineEdit_2->text().toUtf8(),QCryptographicHash::Md5).toHex()));
    qDebug() << hashStr;
    if (db.loginVerification(ui->lineEdit->text(),hashStr)){
    this->hide();
        form2 = new MainWindow(0,ui->lineEdit->text(),hashStr,this);
        form2->setFixedSize(form2->size());
        form2->show();
    }
    else {
        QMessageBox::warning(this,"Увага, помилка !","Комбінаця Логін і Пароль не правильна !",QMessageBox::Ok);
        ui->lineEdit_2->setText("");
    }
}

void Widget::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "")
        ui->loginbutton->setEnabled(1);
    else
        ui->loginbutton->setEnabled(0);
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "")
        ui->loginbutton->setEnabled(1);
    else
        ui->loginbutton->setEnabled(0);
}

void Widget::on_pushButton_clicked()
{
    addUser = new addUserForm(0,0,this);
    this->hide();
    addUser->setFixedSize(addUser->size());
    addUser->show();
}
