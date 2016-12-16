#include "recycledbin.h"
#include <QSqlQueryModel>
#include "ui_recycledbin.h"

recycledbin::recycledbin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recycledbin)
{
    ui->setupUi(this);

    ui->tableView_deletedItems->setColumnWidth(1,90);
    ui->tableView_deletedItems->setColumnWidth(2,90);
    ui->tableView_deletedItems->setColumnWidth(3,70);
    ui->tableView_deletedItems->setColumnWidth(4,60);
    ui->tableView_deletedItems->setColumnWidth(5,60);
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
    choiceMade = choice;

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
    if (choiceMade == "computers")
    {
        recycledComputers();
    }
    else if (choiceMade == "scientists")
    {
        recycledScientists();
    }
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

void recycledbin::on_pushButton_deleteItem_clicked()
{
    if (choiceMade == "computers")
    {
        _service.deleteRecycledComputer(ID);
    }
    else if (choiceMade == "scientists")
    {
        _service.deleteRecycledScientist(ID);
    }
}

void recycledbin::on_pushButton_clearAll_clicked()
{
    if (choiceMade == "computers")
    {
        _service.deleteAllComputersFromDatabase();
    }
    else if (choiceMade == "scientists")
    {
        _service.deleteRecycledScientist(ID);
    }
}

void recycledbin::on_tableView_deletedItems_clicked(const QModelIndex &index)
{
    row = ui->tableView_deletedItems->currentIndex().row();
    ID = index.sibling(row, 0).data().toInt();
}

void recycledbin::on_pushButton_restoreItem_clicked()
{
    if (choiceMade == "computers")
    {
        _service.restoreComputer(ID);
    }
    else if (choiceMade == "scientists")
    {
        _service.restoreScientist(ID);
    }
}

void recycledbin::on_pushButton_restoreAll_clicked()
{
    if (choiceMade == "computers")
    {
        _service.restoreAllComputerFromDatabase();
    }
    else if (choiceMade == "scientists")
    {
        _service.restoreAllScientistFromDatabase();
    }
}
