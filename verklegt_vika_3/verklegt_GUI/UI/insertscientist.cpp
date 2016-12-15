#include "insertscientist.h"
#include "ui_insertscientist.h"

#include "Domain/service.h"
#include <QMessageBox>


insertScientist::insertScientist(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::insertScientist)
{
    ui->setupUi(this);
    user = username;
}

insertScientist::~insertScientist()
{
    delete ui;
}

void insertScientist::on_pushButton_insert_clicked()
{
    Service scientistCheck;
    scientistCheck.setUser(user);

    string firstName = ui->lineEdit_first_name->text().toStdString();
    string lastName = ui->lineEdit_last_name->text().toStdString();
    string gender = ui->lineEdit_gender->text().toStdString();
    int YOB;
    string sYOB = ui->lineEdit_YOB->text().toStdString();
    int YOD;
    string sYOD = ui->lineEdit_YOD->text().toStdString();
    string nationality = ui->lineEdit_nationality->text().toStdString();
    string further = ui->lineEdit_further->text().toStdString();

    scientistCheck.fixString(further);

    if(sYOD == "n/a")
    {
        YOD = maxDeathYear;
    }
    else if(!scientistCheck.validDeathYear(sYOD))
    {
        QMessageBox::warning(this, "Invalid Year", "ERROR: Invalid character in year of death");
        return;
    }
    else
    {
        YOD = stoi(sYOD);
    }

    if(!scientistCheck.validDeathYear(sYOB))
    {
        QMessageBox::warning(this, "Invalid Year", "ERROR: Invalid character in year of birth");
        return;
    }
    else
    {
        YOB = stoi(sYOB);
    }

    if(!scientistCheck.validName(firstName))
    {
        QMessageBox::warning(this, "Invalid Name", QString::fromStdString(scientistCheck.getErrorString()));
        return;
    }
    if(!scientistCheck.validName(lastName))
    {
       QMessageBox::warning(this, "Invalid Name", QString::fromStdString(scientistCheck.getErrorString()));
       return;
    }
    if(!scientistCheck.validSex(gender))
    {
        QMessageBox::warning(this, "Invalid Gender", QString::fromStdString(scientistCheck.getErrorString()));
        return;
    }
    if(!scientistCheck.validYears(YOB, YOD))
    {
        QMessageBox::warning(this, "Invalid Year", QString::fromStdString(scientistCheck.getErrorString()));
        return;
    }
    if(!scientistCheck.validNationality(nationality))
    {
        QMessageBox::warning(this, "Invalid Nationality", QString::fromStdString(scientistCheck.getErrorString()));
        return;
    }

    if(!scientistCheck.appendScientist(firstName, lastName, gender, YOB, YOD, nationality, further))
    {
        QMessageBox::warning(this, "Invalid Scientist", QString::fromStdString(scientistCheck.getErrorString()));
        return;
    }
}
