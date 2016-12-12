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
