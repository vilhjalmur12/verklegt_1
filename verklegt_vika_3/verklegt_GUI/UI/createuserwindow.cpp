#include "createuserwindow.h"
#include "ui_createuserwindow.h"

/******************************************************************
                      Constructor / Destructor
*******************************************************************/

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

/******************************************************************
                      on_pushButton_clicked
 Tekur við upplýsingum fyrir nýjan notanada. Notandanaf, lykilorð,
 staðfestingu á lykilorði, nafn og eftirnaf.
*******************************************************************/

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

/******************************************************************
                      comparePassword
     Ber saman lykilorðið og staðfestinguna á því frá notanada.
*******************************************************************/

bool createUserWindow::comparePassword()
{
    if (password == confirmPassword)
    {
        return true;
    }

    return false;
}
