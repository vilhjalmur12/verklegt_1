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
    void on_checkBox_built_clicked();

    void on_pushButton_addType_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_insert_clicked();

private:
    Ui::insertComputerDialog *ui;
    QString user;

     void initializeDropDown();
};

#endif // INSERTCOMPUTERDIALOG_H
