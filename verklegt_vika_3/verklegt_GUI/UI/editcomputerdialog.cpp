#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

#include "Domain/service.h"
#include <QMessageBox>

editComputerDialog::editComputerDialog(QWidget *parent, int id, QString userName) :
    QDialog(parent),
    ui(new Ui::editComputerDialog)
{   
    ui->setupUi(this);
    data = new Service;
    data->setUser(userName);
    ID = id;

    vector<CpuType> types = data->getTypes();

    Computer computer = data->getComputer(ID);

    string year = computer.getYearForPrinting();
    string scientists;

    vector<string> builders = computer.getBuilders();

    for(unsigned int i = 0; i < builders.size(); i++)
    {
        scientists += builders[i];
        if(i != (builders.size()-1))
            scientists += ", ";
    }

    ui->dropdown_types->addItem(QString::fromStdString(computer.getCpuType()));
    for(unsigned int i = 0; i < types.size(); i++)
    {
        if(types[i].getType() != computer.getCpuType())
            ui->dropdown_types->addItem(QString::fromStdString(types[i].getType()));
    }

    ui->lineEdit_name->setText(QString::fromStdString(computer.getName()));
    ui->lineEdit_year->setText(QString::fromStdString(year));
    ui->lineEdit_built->setText(QString::fromStdString(computer.getBuiltForPrinting()));
    ui->lineEdit_builders->setText(QString::fromStdString(scientists));
}

editComputerDialog::~editComputerDialog()
{
    delete ui;
    delete data;
}

void editComputerDialog::on_pushButton_back_clicked()
{
    this->done(0);
}

void editComputerDialog::on_pushButton_update_clicked()
{
    Service service;
    string name = ui->lineEdit_name->text().toStdString();
    string sYear = ui->lineEdit_year->text().toStdString();
    string type = ui->dropdown_types->currentText().toStdString();
    string sBuilt = ui->lineEdit_built->text().toStdString();

    int year;
    sBuilt = service.fixString(sBuilt);
    qDebug() << QString::fromStdString(sBuilt);
    bool built;

    if(!service.validCpuName(name))
    {
        QMessageBox::warning(this, "Invalid Name", QString::fromStdString(service.getErrorString()));
        return;
    }
    if(sYear == "n/a")
    {
        year = maxDeathYear;
    }
    else if(!service.validDeathYear(sYear))
    {
        // INVALID CHAR IN YEAR
        QMessageBox::warning(this, "Invalid Year", "ERROR: Invalid character in year");
        return;
    }
    else if(!service.validBuildYear(stoi(sYear)))
    {
        //INVALID YEAR
        QMessageBox::warning(this, "Invalid Year", QString::fromStdString(service.getErrorString()));
        return;
    }
    else
    {
        year = stoi(sYear);
    }
    if(sBuilt != "Built" && sBuilt != "Not Built")
    {
        // INVALID BUILT
        QMessageBox::warning(this, "Invalid Build", "Build must be \"built\" or \"not built\"");
        return;
    }
    if(sBuilt == "Built")
    {
        built = true;
    }
    else
    {
        built = false;
    }

    Computer cpu(name, type, built, year);

    data->editComputer(ID, cpu); /////////////////////////////////////////////////////////////////////////////////////////////Breyta í service fall
}

void editComputerDialog::on_pushButton_addType_clicked()
{

}
