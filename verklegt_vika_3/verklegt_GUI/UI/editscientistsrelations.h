#ifndef EDITSCIENTISTSRELATIONS_H
#define EDITSCIENTISTSRELATIONS_H

#include <QDialog>

namespace Ui {
class editScientistsRelations;
}

class editScientistsRelations : public QDialog
{
    Q_OBJECT

public:
    explicit editScientistsRelations(QWidget *parent = 0, int id = 0, QString username = "");
    ~editScientistsRelations();

private slots:
    void on_pushButton_done_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_add_clicked();

    void on_tableWidget_computers_clicked(const QModelIndex &index);

private:
    Ui::editScientistsRelations *ui;
    int ID;
    QString user;
    std::vector<int> IDs;
    std::vector<int> relatedIDs;

    void populateList();

};

#endif // EDITSCIENTISTSRELATIONS_H
