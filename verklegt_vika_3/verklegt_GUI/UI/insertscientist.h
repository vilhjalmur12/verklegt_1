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
    void on_pushButton_insert_clicked();

private:
    Ui::insertScientist *ui;
    QString user;
};

#endif // INSERTSCIENTIST_H
