#ifndef GROUPCONTROL_H
#define GROUPCONTROL_H

#include <QDialog>

namespace Ui {
class groupControl;
}

class groupControl : public QDialog
{
    Q_OBJECT

public:
    explicit groupControl(QWidget *parent = 0);
    ~groupControl();

private:
    Ui::groupControl *ui;
};

#endif // GROUPCONTROL_H
