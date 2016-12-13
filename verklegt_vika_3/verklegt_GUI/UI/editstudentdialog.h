#ifndef EDITSTUDENTDIALOG_H
#define EDITSTUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class editStudentDialog;
}

class editStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editStudentDialog(QWidget *parent = 0);
    ~editStudentDialog();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::editStudentDialog *ui;
    int ID;
};

#endif // EDITSTUDENTDIALOG_H
