#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

#include <QMessageBox>
#include <QInputDialog>
#include "editcomputersrelations.h"
#include <QFileDialog>
#include <QPixmap>

editComputerDialog::editComputerDialog(QWidget *parent, int id, QString userName) :
    QDialog(parent),
    ui(new Ui::editComputerDialog)
{   
    ui->setupUi(this);
    data = new Service;
    username = userName;
    data->setUser(userName);
    ID = id;

    computer = data->getComputer(ID);

    initializeInfo();
}

void editComputerDialog::initializeDropDown()
{
    ui->dropdown_types->clear();

    vector<CpuType> types = data->getTypes();

    ui->dropdown_types->addItem(QString::fromStdString(computer.getCpuType()));
    for(unsigned int i = 0; i < types.size(); i++)
    {
        if(types[i].getType() != computer.getCpuType())
            ui->dropdown_types->addItem(QString::fromStdString(types[i].getType()));
    }
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
    string name = ui->lineEdit_name->text().toStdString();
    string sYear = ui->lineEdit_year->text().toStdString();
    string type = ui->dropdown_types->currentText().toStdString();
    bool built = ui->checkBox_built->isChecked();

    int year;

    if(!data->validCpuName(name))
    {
        QMessageBox::warning(this, "Invalid Name", QString::fromStdString(data->getErrorString()));
        return;
    }
    if(sYear == "n/a")
    {
        year = maxDeathYear;
    }
    else if(!data->validDeathYear(sYear))
    {
        // INVALID CHAR IN YEAR
        QMessageBox::warning(this, "Invalid Year", "ERROR: Invalid character in year");
        return;
    }
    else if(!data->validBuildYear(stoi(sYear)))
    {
        //INVALID YEAR
        QMessageBox::warning(this, "Invalid Year", QString::fromStdString(data->getErrorString()));
        return;
    }
    else
    {
        year = stoi(sYear);
    }

    Computer cpu(name, type, built, year);

    data->editComputer(ID, cpu);

    initializeInfo();
}

void editComputerDialog::on_pushButton_addType_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("New Type"),
                                         tr("Insert New Type:"), QLineEdit::Normal,
                                         "", &ok);
    if(ok)
    {
        string newType = text.toStdString();
        data->addType(newType);
    }

    initializeInfo();
}

void editComputerDialog::on_pushButton_edit_relations_clicked()
{
    editComputersRelations editR(this, ID, username);

    editR.exec();

    initializeInfo();
}

void editComputerDialog::initializeInfo()
{
    computer = data->getComputer(ID);

    string year = computer.getYearForPrinting();
    string scientists;

    vector<string> builders = computer.getBuilders();

    for(unsigned int i = 0; i < builders.size(); i++)
    {
        scientists += builders[i];
        if(i != (builders.size()-1))
            scientists += ", ";
    }

    initializeDropDown();

    ui->lineEdit_name->setText(QString::fromStdString(computer.getName()));
    ui->lineEdit_year->setText(QString::fromStdString(year));
    ui->checkBox_built->setChecked(computer.getBuilt());
    ui->lineEdit_builders->setText(QString::fromStdString(scientists));

}

void editComputerDialog::on_pushButton_browseImCpu_clicked()
{
    string imageCpuPath = QFileDialog::getOpenFileName(
                this,
                "Search for images",
                "",
                "Image files (*.png *.jpg)"
                ).toStdString();

    if (imageCpuPath.length())
    {
        QPixmap pixmap(QString::fromStdString(imageCpuPath));
        ui->label_imCpu->setPixmap(pixmap);
    }
    else
    {
        // user did not select some file
    }
}
