#include "recycledbin.h"
#include "ui_recycledbin.h"

recycledbin::recycledbin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recycledbin)
{
    ui->setupUi(this);
}

recycledbin::~recycledbin()
{
    delete ui;
}

void recycledbin::on_buttonBox_accepted()
{
    this->close();
}

void recycledbin::on_buttonBox_rejected()
{
    this->close();
}



void recycledbin::on_pushButton_resetList_clicked()
{

}
