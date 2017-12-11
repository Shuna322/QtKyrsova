#ifndef SHOWTABLE_H
#define SHOWTABLE_H

#include <QWidget>

namespace Ui {
class showTable;
}

class showTable : public QWidget
{
    Q_OBJECT

public:
    explicit showTable(QWidget *parent = 0);
    ~showTable();

private:
    Ui::showTable *ui;
};

#endif // SHOWTABLE_H
