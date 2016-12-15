#include "editscientistsrelations.h"
#include "ui_editscientistsrelations.h"

#include "Domain/service.h"

editScientistsRelations::editScientistsRelations(QWidget *parent, int id, QString username) :
    QDialog(parent),
    ui(new Ui::editScientistsRelations)
{
    ui->setupUi(this);
    ID = id;
    user = username;

    Service data;
    data.setUser(user);

    populateList();
}

editScientistsRelations::~editScientistsRelations()
{
    delete ui;
}

void editScientistsRelations::on_pushButton_done_clicked()
{
    this->done(0);
}

void editScientistsRelations::populateList()
{
    Service _data;
    _data.setUser(user);

    relatedIDs.clear();
    IDs.clear();

    vector<Computer> relatedComputers = _data.getComputersRelatedTo(ID);
    vector<Computer> allComputers = _data.getComputers();

    ui->tableWidget_computers->clearContents();
    ui->dropDown_computers->clear();

    ui->tableWidget_computers->setRowCount(relatedComputers.size());


    for(unsigned int i = 0; i < relatedComputers.size(); i++)
    {
        relatedIDs.push_back(relatedComputers[i].getID());

        string name = relatedComputers[i].getName();
        QString qname = QString::fromStdString(name);

        ui->tableWidget_computers->setItem(i, 0, new QTableWidgetItem(qname));
    }

    for(unsigned int i = 0; i < allComputers.size(); i++)
    {
        IDs.push_back(allComputers[i].getID());

        string name = allComputers[i].getName();

        ui->dropDown_computers->addItem(QString::fromStdString(name));
    }
    ui->pushButton_delete->setEnabled(false);
}

void editScientistsRelations::on_pushButton_delete_clicked()
{
    Service _data;
    _data.setUser(user);

    int index = ui->tableWidget_computers->currentItem()->row();
    int cID = relatedIDs[index];

    _data.removeRelations(cID, ID);

    populateList();
}

void editScientistsRelations::on_pushButton_add_clicked()
{
    Service _data;
    _data.setUser(user);

    int index = ui->dropDown_computers->currentIndex();
    int cID = IDs[index];

    _data.addRelations(cID, ID);

    populateList();
}

void editScientistsRelations::on_tableWidget_computers_clicked(const QModelIndex &index)
{
    ui->pushButton_delete->setEnabled(true);
}
