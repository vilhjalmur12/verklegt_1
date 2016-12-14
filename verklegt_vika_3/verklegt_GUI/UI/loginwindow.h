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
    void on_pushButton_activateUser_clicked();

    void on_pushButton_createUser_clicked();

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


    // Test output
    QString invalid = "Invalid user or password";
    QString valid = "Password Valid, welcome!";

    void callUser (QString username, QString password);
    void createUser ();

};

#endif // LOGINWINDOW_H
