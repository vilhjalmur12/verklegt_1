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
        data.createUser(username, password, firstName, lastName);
        this->close();
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


/*
if (action == "c")
{
    string confirmPass = "password";

    cout << "Choose Username: ";
    cin >> tmpUser;
    QString tmpQUser(tmpUser.c_str());
    user = tmpQUser;

    while (password != confirmPass)
    {
        cout << "Choose Password: ";
        cin >> password;
        cout << "Confirm Password: ";
        cin >> confirmPass;

        if (password != confirmPass)
        {
            cout << "You didn't confirm the right password" << endl;
        }
    }
    QString qPassword(password.c_str());

    string firstName, lastName;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;

    QString qFirstName(firstName.c_str());
    QString qLastName(lastName.c_str());

    data.createUser(user, qPassword, qFirstName, qLastName);
    runProgram = true;

}
*/
