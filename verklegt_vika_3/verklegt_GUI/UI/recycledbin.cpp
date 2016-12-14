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

}

void recycledbin::on_pushButton_clearAll_clicked()
{

}

void recycledbin::on_tableView_deletedItems_clicked(const QModelIndex &index)
{
    if (choiceMade == "computers")
    {
        rowChosen = ui-> tableView_deletedItems->currentIndex().row();
        name = index.sibling(rowChosen, 0).data().toString();
        year = index.sibling(rowChosen, 1).data().toString();
    }
    else if (choiceMade == "scientists")
    {
        rowChosen = ui-> tableView_deletedItems->currentIndex().row();
        name = index.sibling(rowChosen, 0).data().toString();
        lastName = index.sibling(rowChosen, 1).data().toString();
        year = index.sibling(rowChosen, 3).data().toString();
    }

}
