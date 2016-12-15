#include "createuserwindow.h"
#include "ui_createuserwindow.h"

createUserWindow::createUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createUserWindow)
{
    ui->setupUi(this);
}

createUserWindow::~createUserWindow()
{
    delete ui;
}

void createUserWindow::on_pushButton_clicked()
{
    username = ui->lineEdit_userName->text();
    password = ui->lineEdit_password->text();
    confirmPassword = ui->lineEdit_cPassword->text();
    firstName = ui->lineEdit_firstName->text();
    lastName = ui->lineEdit_lastName->text();

    if (comparePassword())
    {
        if(!_service.createUser(username, password, firstName, lastName))
        {
            errorWidget.show();
            if(username == "")
            {
                errorWidget.nonUserInput();
            }
            else
            {
               errorWidget.userExists();
            }
        }
        else
        {
            this->close();
        }
    }
    else
    {
        errorWidget.nonMatchPassword();
    }

}

bool createUserWindow::comparePassword()
{
    if (password == confirmPassword)
    {
        return true;
    }

    return false;
}
