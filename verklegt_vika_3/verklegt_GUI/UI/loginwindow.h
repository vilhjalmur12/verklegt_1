#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "Domain/service.h"
#include "Domain/errorlog.h"
#include <string>
#include "UI/createuserwindow.h"
#include "mainwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_activateUser_clicked();          //Tekur við loggin upplýsingum frá notanada og keyrir forritið

    void on_pushButton_createUser_clicked();            //Kallar á nýjan glugga til að búa til nýjan notanda þegarýtt er á "New user"

private:
    Ui::LoginWindow *ui;
    int safeCount = 0;
    Database data;
    bool runProgram = false;
    errorwindow errorWidget;
     ErrorLog _errorLog;
     QString username;
     QString password;
     createUserWindow create;
    MainWindow main;
    Service _service;

    QString invalid = "Invalid user or password";

    void callUser (QString username, QString password); //Sendir áfram notandanaf og lykilorð til að athuga hvort notandisé til í gagnagrunni
    //void createUser ();

};

#endif // LOGINWINDOW_H
