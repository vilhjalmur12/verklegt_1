#ifndef INSERTCOMPUTERDIALOG_H
#define INSERTCOMPUTERDIALOG_H

#include <QDialog>

namespace Ui {
class insertComputerDialog;
}

class insertComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit insertComputerDialog(QWidget *parent = 0, QString username = "");
    ~insertComputerDialog();

private slots:
    void on_checkBox_built_clicked();       //Check box hvort tölva hafi verið byggð eða ekki

    void on_pushButton_addType_clicked();   //Tekur við nýrri týpu af tölvu frá notanda

    void on_pushButton_back_clicked();      //Lokar insert glugga fyrir tölvu

    void on_pushButton_insert_clicked();    //Tekur við upplýsingum um nýja tölvu frá notandan

private:
    Ui::insertComputerDialog *ui;
    QString user;

     void initializeDropDown();
};

#endif // INSERTCOMPUTERDIALOG_H
