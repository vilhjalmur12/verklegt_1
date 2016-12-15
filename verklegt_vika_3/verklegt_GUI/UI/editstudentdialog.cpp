#include "editstudentdialog.h"
#include "ui_editstudentdialog.h"

#include "Domain/service.h"
#include <QMessageBox>
#include "editscientistsrelations.h"
#include <QFileDialog>
#include <QPixmap>

editStudentDialog::editStudentDialog(QWidget *parent, int id, QString userName) :
    QDialog(parent),
    ui(new Ui::editStudentDialog)
{
    ui->setupUi(this);
    ID = id;
    data = new Database;
    data->setUser(userName);
    username = userName;

    Scientist temp = data->getScientist(ID);

    string birth = to_string(temp.getYearOfBirth());
    string death = temp.getYearOfDeathForPrinting();
    string computers;

    vector<string> cpuS = temp.getComputersBuilt();

    for(unsigned int i = 0; i < cpuS.size(); i++)
    {
        computers += cpuS[i];
        if(i != (cpuS.size()-1))
            computers += ", ";
    }

    ui->lineEdit_first_name->setText(QString::fromStdString(temp.getFirstName()));
    ui->lineEdit_last_name->setText(QString::fromStdString(temp.getLastName()));
    ui->lineEdit_gender->setText(QString::fromStdString(temp.getSex()));
    ui->lineEdit_nationality->setText(QString::fromStdString(temp.getNationality()));
    ui->lineEdit_YOB->setText(QString::fromStdString(birth));
    ui->lineEdit_YOD->setText(QString::fromStdString(death));
    ui->lineEdit_further->setText(QString::fromStdString(temp.getFurtherInfo()));
    ui->lineEdit_relations->setText(QString::fromStdString(computers));

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

editStudentDialog::~editStudentDialog()
{
    delete ui;
}

void editStudentDialog::on_pushButton_back_clicked()
{
    this->done(0);
}

void editStudentDialog::on_pushButton_update_clicked()
{
    Service scientistCheck;

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

    Scientist temp(firstName, lastName, gender, YOB, YOD, nationality, further);

    data->editScientist(ID, temp);

}

void editStudentDialog::on_pushButton_edit_relations_clicked()
{
    editScientistsRelations edit(this, ID, username);

    edit.exec();

}

void editStudentDialog::on_pushButton_browseImSci_clicked()
{
    string imagePath = QFileDialog::getOpenFileName(
                this,
                "Search for images",
                "",
                "Image files (*.png *.jpg)"
                ).toStdString();

    if (imagePath.length())
    {
        // user selected some file
    }
    else
    {
        // user did not select some file
    }
}
