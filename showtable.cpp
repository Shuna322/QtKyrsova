#include "showtable.h"
#include "ui_showtable.h"

showTable::showTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showTable)
{
    ui->setupUi(this);
<<<<<<< HEAD

=======
    db.connect();
    model = new QSqlTableModel (this,db.getdb());
    model->setTable("students");
   // model->setFilter("");
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
>>>>>>> 6df2e3b452843429a89e4e9b68bea3b746dabcd2
}

showTable::~showTable()
{
    delete ui;
}

void showTable::on_pushButton_clicked()
{
    db.connect();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery*query = new QSqlQuery(db.getdb());
    query->prepare("SELECT `id`, `name`, `sname`, `tname`, `group` FROM students");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    //qDebug() <<  query->lastQuery();
}
