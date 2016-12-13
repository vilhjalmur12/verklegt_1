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

private:
    Ui::editStudentDialog *ui;
};

#endif // EDITSTUDENTDIALOG_H
