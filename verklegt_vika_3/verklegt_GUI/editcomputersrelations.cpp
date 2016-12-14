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

    vector<Scientist> relatedScientists = _data.getScientistsRelatedTo(ID);

    qDebug() << relatedScientists.size();

    ui->tableWidget_scientists->clearContents();

    ui->tableWidget_scientists->setRowCount(relatedScientists.size());


    for(unsigned int i = 0; i < relatedScientists.size(); i++)
    {
        QString lastName = QString::fromStdString(relatedScientists[i].getLastName());
        QString firstName = QString::fromStdString(relatedScientists[i].getFirstName());

        ui->tableWidget_scientists->setItem(i, 0, new QTableWidgetItem(lastName));
        ui->tableWidget_scientists->setItem(i, 1, new QTableWidgetItem(firstName));
    }
}

void editComputersRelations::on_pushButton_done_clicked()
{
    this->done(0);
}
