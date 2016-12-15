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

    if (username == "")
    {
        errorWidget.nonUserInput();
        errorWidget.show();
    }
    else
    {
        callUser(username, password);

        ui->label_login->clear();

        if (runProgram == false)
        {
            ui->label_login->setText(invalid);
        }
        else
        {
            main.setUserName(username);
            main.show();
            main.displayScientists();
            main.displayComputers();
            this->close();
        }
    }
}

void LoginWindow::callUser (QString username, QString password)
{


    string sUser = username.toUtf8().constData();

    bool foundUser = _service.getUser(username, password);

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


void LoginWindow::on_pushButton_createUser_clicked()
{
    create.show();
}
