#include "showtable.h"
#include "ui_showtable.h"

showTable::showTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showTable)
{
    ui->setupUi(this);
    db.connect();
    model = new QSqlTableModel (this,db.getdb());
    model->setTable("students");
   // model->setFilter("");
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

showTable::~showTable()
{
    delete ui;
}
