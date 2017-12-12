#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H

#include <QDialog>

namespace Ui {
class studentInformation;
}

class studentInformation : public QDialog
{
    Q_OBJECT

public:
    explicit studentInformation(QWidget *parent = 0);
    ~studentInformation();

private:
    Ui::studentInformation *ui;
};

#endif // STUDENTINFORMATION_H
