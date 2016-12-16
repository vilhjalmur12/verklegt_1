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

    QRegExp firstName("[A-Za-z][A-Za-z]*([.]?||[])([ ][A-Za-z]+([.]?||[-][A-Za-z]))*");
    QValidator *firstNameValidator = new QRegExpValidator(firstName, this);

    QRegExp lastName("([A-Za-z]+([-][A-Za-z][A-Za-z]*)?)");
    QValidator *lastNameValidator = new QRegExpValidator(lastName, this);

    QRegExp regGender("[fm]||(female||male)||(Female||Male)");
    QValidator *gender = new QRegExpValidator(regGender, this);

    QRegExp regYOB("-?[0-9]*");
    QValidator *YOB = new QRegExpValidator(regYOB, this);

    QRegExp regYOD("-?[0-9]*||(n/a)");
    QValidator *YOD = new QRegExpValidator(regYOD, this);

    ui->lineEdit_first_name->setValidator(firstNameValidator);
    ui->lineEdit_last_name->setValidator(lastNameValidator);
    ui->lineEdit_gender->setValidator(gender);
    ui->lineEdit_YOB->setValidator(YOB);
    ui->lineEdit_YOD->setValidator(YOD);

}

insertScientist::~insertScientist()
{
    delete ui;
}

void insertScientist::on_pushButton_insert_clicked()
{
    Service scientistCheck;
    scientistCheck.setUser(user);

    if(!ui->lineEdit_first_name->hasAcceptableInput())
    {
        QMessageBox::warning(this, "Invalid Name", "ERROR: Invalid format of first name");
        return;
    }
    if(!ui->lineEdit_last_name->hasAcceptableInput())
    {
        QMessageBox::warning(this, "Invalid Name", "ERROR: Invalid format of last name");
        return;
    }
    if(!ui->lineEdit_gender->hasAcceptableInput())
    {
        QMessageBox::warning(this, "Invalid Gender", "ERROR: Invalid format of gender");
        return;
    }

    string firstName = ui->lineEdit_first_name->text().toStdString();
    string lastName = ui->lineEdit_last_name->text().toStdString();
    string gender = ui->lineEdit_gender->text().toStdString();
    int YOB;
    string sYOB = ui->lineEdit_YOB->text().toStdString();
    int YOD;
    string sYOD = ui->lineEdit_YOD->text().toStdString();
    string nationality = ui->lineEdit_nationality->text().toStdString();
    string further = ui->lineEdit_further->text().toStdString();

    if(gender == "")
    {
        QMessageBox::warning(this, "Invalid Gender", "ERROR: Gender can not be empty");
        return;
    }
    if(firstName == "" || lastName == "")
    {
        QMessageBox::warning(this, "Invalid Name", "ERROR: First and Last names can not be empty");
        return;
    }
    if(sYOB == "")
    {
        QMessageBox::warning(this, "Invalid Year", "ERROR: year of birth can not be empty");
        return;
    }

    if(sYOD == "n/a" || sYOD == "")
    {
        YOD = maxDeathYear;
        sYOD = "n/a";
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

    this->done(1);

}

void insertScientist::on_pushButton_back_clicked()
{
    this->done(0);
}
