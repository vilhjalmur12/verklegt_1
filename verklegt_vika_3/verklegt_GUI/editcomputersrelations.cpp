#include "editcomputersrelations.h"
#include "ui_editcomputersrelations.h"

#include "Domain/service.h"

editComputersRelations::editComputersRelations(QWidget *parent, int id, QString username) :
    QDialog(parent),
    ui(new Ui::editComputersRelations)
{
    ui->setupUi(this);
    ID = id;
    user = username;

    Service data;
    data.setUser(user);

    populateList();

}

editComputersRelations::~editComputersRelations()
{
    delete ui;
}

void editComputersRelations::populateList()
{
    Service _data;
    _data.setUser(user);

    relatedIDs.clear();
    IDs.clear();

    vector<Scientist> relatedScientists = _data.getScientistsRelatedTo(ID);
    vector<Scientist> allScientists = _data.getScientists();

    ui->tableWidget_scientists->clearContents();
    ui->dropDown_scientists->clear();

    ui->tableWidget_scientists->setRowCount(relatedScientists.size());


    for(unsigned int i = 0; i < relatedScientists.size(); i++)
    {
        relatedIDs.push_back(relatedScientists[i].getID());

        string name = relatedScientists[i].getLastName() + ", " + relatedScientists[i].getFirstName();
        QString qname = QString::fromStdString(name);

        ui->tableWidget_scientists->setItem(i, 0, new QTableWidgetItem(qname));
    }

    for(unsigned int i = 0; i < allScientists.size(); i++)
    {
        IDs.push_back(allScientists[i].getID());

        string name = allScientists[i].getLastName() + ", " + allScientists[i].getFirstName();

        ui->dropDown_scientists->addItem(QString::fromStdString(name));
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton->setStyleSheet(QString::fromUtf8("QPushButton:disabled"
    "{color: gray}"
    ));
}

void editComputersRelations::on_pushButton_done_clicked()
{
    this->done(0);
}

void editComputersRelations::on_pushButton_clicked()
{
    Service _data;
    _data.setUser(user);

    int index = ui->tableWidget_scientists->currentItem()->row();
    int sID = relatedIDs[index];

    _data.removeRelations(ID, sID);

    populateList();
}

void editComputersRelations::on_pushButton_add_clicked()
{
    Service _data;
    _data.setUser(user);

    int index = ui->dropDown_scientists->currentIndex();
    int sID = IDs[index];

    _data.addRelations(ID, sID);

    populateList();
}

void editComputersRelations::on_tableWidget_scientists_clicked()
{
    ui->pushButton->setEnabled(true);
}
