        #include "studentinformation.h"
    #include "ui_studentinformation.h"

    studentInformation::studentInformation(QWidget *parent,int _id) :
        QDialog(parent), id(_id),
        ui(new Ui::studentInformation)
    {
        ui->setupUi(this);
        st.getdataFromDB(id);
        QVariant day = st.getbday().day();
        QVariant month = st.getbday().month();
        QVariant year = st.getbday().year();
        QVariant sday = st.getstartEdu().day();
        QVariant smonth = st.getstartEdu().month();
        QVariant syear = st.getstartEdu().year();
        ui->label_14->setText(st.getname());
        ui->label_15->setText(st.getsname());
        ui->label_16->setText(st.gettname());
        if(st.getsex())
            ui->label_17->setText("Ж");
        else
            ui->label_17->setText("Ч");
       // countAge(st.getbday()).toString();
        ui->label_18->setText(countAge(st.getbday()));
        ui->label_19->setText(((((day.toString()+"/")+month.toString())+"/")+year.toString()));
        ui->label_20->setText(st.getphone_number());
        ui->label_21->setText(st.getadress());
        if(st.gettype_of_education())
            ui->label_22->setText("Державна");
        else ui->label_22->setText("Платна");
        ui->label_23->setText(st.getdepartament());
        ui->label_24->setText(st.getgroup());
        ui->label_25->setText(st.getkurs());
    }

    QString studentInformation::countAge(QDate _bday)
    {
        QDate currentDate= QDate::currentDate();
        int Age = currentDate.year() -  _bday.year();
        if ((_bday.month() > currentDate.month() || (_bday.month()==currentDate.month() && _bday.day()>currentDate.day())))
         Age++;
        QString age = (QString::number(Age));
        return age;
    }

    studentInformation::~studentInformation()
    {
        delete ui;
    }
