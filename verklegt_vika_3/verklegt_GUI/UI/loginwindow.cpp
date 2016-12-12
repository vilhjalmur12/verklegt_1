#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_activateUser_clicked()
{
    username = ui->lineInput_username->text();
    password = ui->lineInput_password->text();

    callUser(username, password);

    ui->label_login->clear();

    if (runProgram == false)
    {
        ui->label_login->setText(invalid + " " + username + " " + password);
    }
    else
    {
        ui->label_login->setText(valid);
    }

}

void LoginWindow::callUser (QString username, QString password)
{
    string sUser = username.toUtf8().constData();

    bool foundUser = data.getUser(username, password);


            if (foundUser == true)
            {
                runProgram = true;
            }
            else
            {
                safeCount++;
                if (safeCount >= 3)
                {
                    bool brute = true;
                    //ErrorLog _errorLog(sUser, invalid, brute);
                  //  _errorLog.pushError();
                }
                else
                {
                  //  ErrorLog _errorLog(sUser, invalid);
                 //   _errorLog.pushError();
                }
            }



  //  Service newScientistService(user);
  //  scientistService = newScientistService;
  //  run();
}
/*
void LoginWindow::createUser ()
{
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
}
*/

void LoginWindow::on_pushButton_createUser_clicked()
{

}
