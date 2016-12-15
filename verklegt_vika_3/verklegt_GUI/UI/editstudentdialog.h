#ifndef EDITSTUDENTDIALOG_H
#define EDITSTUDENTDIALOG_H

#include "DATA/database.h"
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
    void on_pushButton_back_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_edit_relations_clicked();

private:
    Ui::editStudentDialog *ui;
    int ID;
    Database *data;
    QString username;
};

#endif // EDITSTUDENTDIALOG_H
