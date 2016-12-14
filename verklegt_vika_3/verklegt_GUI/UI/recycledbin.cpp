#include "recycledbin.h"
#include <QSqlQueryModel>
#include "ui_recycledbin.h"

recycledbin::recycledbin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recycledbin)
{
    ui->setupUi(this);
}

recycledbin::~recycledbin()
{
    delete ui;
}

void recycledbin::on_buttonBox_accepted()
{
    this->close();
}

void recycledbin::on_buttonBox_rejected()
{
    this->close();
}

void recycledbin::callRecycleBin (QString username, QString choice)
{
    user = username;

    this->show();
    if (choice == "computers")
    {
        recycledComputers();
    }
    else if (choice == "scientists")
    {
        recycledScientists();
    }
}

void recycledbin::on_pushButton_resetList_clicked()
{

}

void recycledbin::recycledComputers()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query = _service.getRecycledComputers(user);

    modal->setQuery(query);

    ui->tableView_deletedItems->setModel(modal);

    _service.closeDatabase();
}

void recycledbin::recycledScientists()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query = _service.getRecycledScientists(user);

    modal->setQuery(query);

    ui->tableView_deletedItems->setModel(modal);

    _service.closeDatabase();
}

