#include "editstudentdialog.h"
#include "ui_editstudentdialog.h"

editStudentDialog::editStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editStudentDialog)
{
    ui->setupUi(this);
}

editStudentDialog::~editStudentDialog()
{
    delete ui;
}
