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
    void on_pushButton_clicked();   //Tekur við upplýsingum fyrir nýjan notanada.


private:
    Ui::createUserWindow *ui;
    errorwindow errorWidget;
    Service _service;

    QString username;
    QString password;
    QString confirmPassword;
    QString firstName;
    QString lastName;

    bool comparePassword();         //Ber saman lykilorðið og staðfestinguna á því frá notanada

};

#endif // CREATEUSERWINDOW_H
