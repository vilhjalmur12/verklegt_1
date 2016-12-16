#include "insertcomputerdialog.h"
#include "ui_insertcomputerdialog.h"

#include <QMessageBox>
#include <QInputDialog>
#include "editcomputersrelations.h"
#include <QFileDialog>
#include <QPixmap>
#include "Domain/service.h"

insertComputerDialog::insertComputerDialog(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::insertComputerDialog)
{
    ui->setupUi(this);

    user = username;

    QRegExp name("[A-Za-z0-9.- ]*");
    QValidator *nameValidator = new QRegExpValidator(name, this);

    QRegExp cpuYear("-?[0-9]*");
    QValidator *yearValidator = new QRegExpValidator(cpuYear, this);

    ui->lineEdit_name->setValidator(nameValidator);
    ui->lineEdit_year->setValidator(yearValidator);

}

insertComputerDialog::~insertComputerDialog()
{
    delete ui;
}

void insertComputerDialog::on_checkBox_built_clicked()
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

void insertComputerDialog::on_pushButton_browseImCpu_clicked()
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

void insertComputerDialog::on_pushButton_addType_clicked()
{
    Service _data;
    _data.setUser(user);

    bool ok;
    QString text = QInputDialog::getText(this, tr("New Type"),
                                         tr("Insert New Type:"), QLineEdit::Normal,
                                         "", &ok);
    if(ok)
    {
        string newType = text.toStdString();
        _data.addType(newType);
    }

}

void insertComputerDialog::on_pushButton_back_clicked()
{
    this->done(0);
}

void insertComputerDialog::initializeDropDown()
{
    Service _data;
    _data.setUser(user);

    ui->dropdown_types->clear();

    vector<CpuType> types = _data.getTypes();

    for(unsigned int i = 0; i < types.size(); i++)
    {
        ui->dropdown_types->addItem(QString::fromStdString(types[i].getType()));
    }
}
