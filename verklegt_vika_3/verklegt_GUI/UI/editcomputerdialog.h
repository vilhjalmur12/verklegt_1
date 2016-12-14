#ifndef EDITCOMPUTERDIALOG_H
#define EDITCOMPUTERDIALOG_H

#include "DATA/database.h"
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

private:
    Ui::editComputerDialog *ui;
    Database *data;
    int ID;
};

#endif // EDITCOMPUTERDIALOG_H
