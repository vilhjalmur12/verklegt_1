#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

#include <QMessageBox>
#include <QInputDialog>
#include "editcomputersrelations.h"
#include <QFileDialog>
#include <QPixmap>

/******************************************************************
                      Constructor / Destructor
*******************************************************************/

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

editComputerDialog::~editComputerDialog()
{
    delete ui;
    delete data;
}

/******************************************************************
                      initializeDropDown
       Fyllir upp í fellivalmynd fyrir týpur af tölvu.
*******************************************************************/

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

/******************************************************************
                   on_pushButton_back_clicked
                     Lokar edit valmynd.
*******************************************************************/

void editComputerDialog::on_pushButton_back_clicked()
{
    this->done(0);
}

/******************************************************************
                  on_pushButton_update_clicked
   Uppfærir upplýsingar um tölvu þegar ýtt er á update takkann.
*******************************************************************/

void editComputerDialog::on_pushButton_update_clicked()
{

    string name = ui->lineEdit_name->text().toStdString();
    string sYear = ui->lineEdit_year->text().toStdString();
    string type = ui->dropdown_types->currentText().toStdString();
    bool built = ui->checkBox_built->isChecked();

    int year;

    if(sYear=="" && ui->checkBox_built->isChecked())
    {
        QMessageBox::warning(this, "Invalid Year", "ERROR: Missing build year for built computer");
        return;
    }
    if(name=="")
    {
        QMessageBox::warning(this, "Invalid Name", "ERROR: Name cannot be empty");
        return;
    }

    if(sYear == "n/a" || sYear =="")
    {
        year = maxDeathYear;
        sYear = "n/a";
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

    this->done(1);
}

/******************************************************************
                  on_pushButton_addType_clicked
                 Bættir við nýrri týpu á tölvu.
*******************************************************************/

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

/******************************************************************
              on_pushButton_edit_relations_clicked
      Tengir vísindamann við tölvuna sem verið er að edit-a.
*******************************************************************/

void editComputerDialog::on_pushButton_edit_relations_clicked()
{
    editComputersRelations editR(this, ID, username);

    editR.exec();

    initializeInfo();
}

/******************************************************************
                        initializeInfo
   Byrtir þær upplýsingar sem eru nú þegar til staðar um tölvuna
   sem verið er að edit-a
*******************************************************************/

void editComputerDialog::initializeInfo()
{
    computer = data->getComputer(ID);

    string year = computer.getYearForPrinting();
    string scientists = computer.getBuilders();

    initializeDropDown();

    ui->lineEdit_name->setText(QString::fromStdString(computer.getName()));
    ui->lineEdit_year->setText(QString::fromStdString(year));
    ui->checkBox_built->setChecked(computer.getBuilt());
    ui->lineEdit_builders->setText(QString::fromStdString(scientists));

    ui->lineEdit_year->setEnabled((ui->checkBox_built->isChecked()));

    QRegExp name("[A-Za-z0-9.- ]*");
    QValidator *nameValidator = new QRegExpValidator(name, this);

    QRegExp cpuYear("-?[0-9]*");
    QValidator *yearValidator = new QRegExpValidator(cpuYear, this);

    ui->lineEdit_name->setValidator(nameValidator);
    ui->lineEdit_year->setValidator(yearValidator);



}

/******************************************************************
                on_pushButton_browseImCpu_clicked
                 Finnur slóð að mynd af tölvu
*******************************************************************/

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

/******************************************************************
                on_checkBox_built_clicked
             Athugar hvort tölva hafði verið byggð eða ekki.
*******************************************************************/

void editComputerDialog::on_checkBox_built_clicked()
{
    if(ui->checkBox_built->isChecked())
    {
        ui->lineEdit_year->setEnabled(true);
    }
    else
    {
        ui->lineEdit_year->clear();
        ui->lineEdit_year->setEnabled(false);
    }
}
