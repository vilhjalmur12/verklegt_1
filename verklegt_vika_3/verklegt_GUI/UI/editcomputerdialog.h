
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
    void on_pushButton_back_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_addType_clicked();

    void initializeDropDown();

    void on_pushButton_edit_relations_clicked();

private:
    Ui::editComputerDialog *ui;
    Service *data;
    Computer computer;
    QString username;
    int ID;
};

#endif // EDITCOMPUTERDIALOG_H

