#ifndef INSERTSCIENTIST_H
#define INSERTSCIENTIST_H

#include <QDialog>

namespace Ui {
class insertScientist;
}

class insertScientist : public QDialog
{
    Q_OBJECT

public:
    explicit insertScientist(QWidget *parent = 0, QString username = "");
    ~insertScientist();

private slots:
    void on_pushButton_insert_clicked();    //Tekur við upplýsingum um nýjan vísindamann frá notanda

    void on_pushButton_back_clicked();      //Lokar insert glugga

private:
    Ui::insertScientist *ui;
    QString user;
};

#endif // INSERTSCIENTIST_H
