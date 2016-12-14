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

    void on_pushButton_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::editComputersRelations *ui;
    int ID;
    QString user;
    std::vector<int> IDs;
    std::vector<int> relatedIDs;

    void populateList();
};

#endif // EDITCOMPUTERSRELATIONS_H
