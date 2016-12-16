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
    void on_pushButton_done_clicked();      //Lokar edit relations glugga

    void on_pushButton_delete_clicked();    //Eyðir venslum við vísindamann

    void on_pushButton_add_clicked();       //Bætir við venslum vísindamann

    void on_tableWidget_computers_clicked(const QModelIndex &index);

private:
    Ui::editScientistsRelations *ui;
    int ID;
    QString user;
    std::vector<int> IDs;
    std::vector<int> relatedIDs;

    void populateList();                    //Fyllir lista af tölvum sem eru tengdir vil tiltekin vísindamann

};

#endif // EDITSCIENTISTSRELATIONS_H
