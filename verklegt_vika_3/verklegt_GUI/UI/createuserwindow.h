#ifndef CREATEUSERWINDOW_H
#define CREATEUSERWINDOW_H

#include <QWidget>
#include "errorwindow.h"
#include "Domain/service.h"

namespace Ui {
class createUserWindow;
}

class createUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit createUserWindow(QWidget *parent = 0);
    ~createUserWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createUserWindow *ui;
    errorwindow errorWidget;
    Service _service;

    QString username;
    QString password;
    QString confirmPassword;
    QString firstName;
    QString lastName;

    bool comparePassword();

};

#endif // CREATEUSERWINDOW_H
