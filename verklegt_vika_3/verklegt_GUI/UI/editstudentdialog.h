#ifndef EDITSTUDENTDIALOG_H
#define EDITSTUDENTDIALOG_H

#include "Domain/service.h"
#include <QDialog>

namespace Ui {
class editStudentDialog;
}

class editStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editStudentDialog(QWidget *parent = 0, int id = 0, QString userName = "");
    ~editStudentDialog();

private slots:
    void on_pushButton_back_clicked();              //Lokar glugga

    void on_pushButton_update_clicked();            //Uppfærir upplýsingar um vísindamann

    void on_pushButton_edit_relations_clicked();    //Kallar á edit relations gluggan fyrir vísindamann

    void on_pushButton_browseImSci_clicked();       //Notandi velur slóð á mynd sem tengist vísindamanni

private:
    Ui::editStudentDialog *ui;
    int ID;
    Service *data;
    QString username;
};

#endif // EDITSTUDENTDIALOG_H
