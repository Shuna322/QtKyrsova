#include "studentinformation.h"
#include "ui_studentinformation.h"

studentInformation::studentInformation(QWidget *parent,int _id) :
    QDialog(parent), id(_id),
    ui(new Ui::studentInformation)
{
    ui->setupUi(this);
    st.getdataFromDB(id);

    ui->label_14->setText(st.getname());
    ui->label_15->setText(st.getsname());
    ui->label_16->setText(st.gettname());
    if(st.getsex())
        ui->label_17->setText("Ж");
        else
    ui->label_17->setText("Ч");
    ui->label_19->setText();


}

studentInformation::~studentInformation()
{
    delete ui;
}
