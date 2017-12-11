#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

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
    //QByteArray hash = QCryptographicHash::​hash(ui->lineEdit_2->text().toLocal8Bit(), QCryptographicHash::Md5);
    qDebug() << hashStr;
    db.connect();
    if (db.loginVerification(ui->lineEdit->text(),hashStr)){
    this->hide();
        form2 = new MainWindow(this,ui->lineEdit->text(),hashStr);
        form2->show();
    }
    else QMessageBox(QMessageBox::Icon::Warning,"Увага, помилка !","Логін і Пароль не правильний !",QMessageBox::Ok);
}
