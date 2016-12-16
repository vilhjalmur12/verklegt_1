#ifndef EDITCOMPUTERDIALOG_H
#define EDITCOMPUTERDIALOG_H

#include "Domain/service.h"

#include <QDialog>

namespace Ui {
class editComputerDialog;
}

class editComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editComputerDialog(QWidget *parent = 0, int id = 0, QString userName = "");
    ~editComputerDialog();

private slots:
    void on_pushButton_back_clicked();          //Lokar edit valmynd.

    void on_pushButton_update_clicked();        //Uppfærir upplýsingar um tölvu þegar ýtt er á update takkann.

    void on_pushButton_addType_clicked();       //Bættir við nýrri týpu á tölvu.

    void on_pushButton_edit_relations_clicked();//Tengir vísindamann við tölvuna sem verið er að edit-a.

    void on_pushButton_browseImCpu_clicked();   //Finnur slóð að mynd af tölvu

    void on_checkBox_built_clicked();           //Athugar hvort tölva hafði verið byggð eða ekki.

private:
    Ui::editComputerDialog *ui;
    Service *data;
    Computer computer;
    QString username;

    void initializeDropDown();                  //Fyllir upp í fellivalmynd fyrir týpur af tölvu
    void initializeInfo();                      //Byrtir þær upplýsingar sem eru nú þegar til staðar um tölvuna sem verið er að edit-a

    int ID;
};

#endif // EDITCOMPUTERDIALOG_H
