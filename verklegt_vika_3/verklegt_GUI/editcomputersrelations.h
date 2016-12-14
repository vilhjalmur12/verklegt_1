#ifndef EDITCOMPUTERSRELATIONS_H
#define EDITCOMPUTERSRELATIONS_H

#include <QDialog>

namespace Ui {
class editComputersRelations;
}

class editComputersRelations : public QDialog
{
    Q_OBJECT

public:
    explicit editComputersRelations(QWidget *parent = 0, int id = 0, QString userName = "");
    ~editComputersRelations();

private slots:
    void on_pushButton_done_clicked();

private:
    Ui::editComputersRelations *ui;
    int ID;
    QString user;

    void populateList();
};

#endif // EDITCOMPUTERSRELATIONS_H
