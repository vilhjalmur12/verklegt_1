#include "errorwindow.h"
#include "ui_errorwindow.h"

errorwindow::errorwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::errorwindow)
{
    ui->setupUi(this);
}

errorwindow::~errorwindow()
{
    delete ui;
}

void errorwindow::on_pushButton_cancel_clicked()
{
    this->close();
}

void errorwindow::dataErrorFound ()
{
    QString error = "Error: connection with database fail";
    ui->label_errorLabel->setText(error);
}

void errorwindow::nonMatchPassword ()
{
    QString error = "Passwords do not match";
    ui->label_errorLabel->setText(error);
}

void errorwindow::userExists()
{
    QString error = "Username already exists, pick another one";
    ui->label_errorLabel->setText(error);
}

void errorwindow::nonUserInput()
{
    QString error = "Please insert username";
    ui->label_errorLabel->setText(error);
}

bool errorwindow::confirmDeleteAll(bool OK)
{
    QString error = "Are you sure you want to clear your recycle bin?";
    ui->label_errorLabel->setText(error);
    this->show();
}

void errorwindow::on_pushButton_ok_clicked()
{
   this->close();
}
