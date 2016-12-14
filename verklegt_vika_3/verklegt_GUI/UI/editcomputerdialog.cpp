#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

#include "Domain/service.h"
#include <QMessageBox>

editComputerDialog::editComputerDialog(QWidget *parent, int id, QString userName) :
    QDialog(parent),
    ui(new Ui::editComputerDialog)
{
    ui->setupUi(this);
    data = new Database;
    data->setUser(userName);
    ID = id;

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

    ui->lineEdit_name->setText(QString::fromStdString(computer.getName()));
    ui->lineEdit_year->setText(QString::fromStdString(year));
    ui->lineEdit_type->setText(QString::fromStdString(computer.getCpuType()));
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

void editComputerDialog::on_editComputerDialog_accepted()
{

}
