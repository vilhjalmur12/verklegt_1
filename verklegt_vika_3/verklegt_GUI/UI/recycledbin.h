#ifndef RECYCLEDBIN_H
#define RECYCLEDBIN_H

#include <QDialog>

namespace Ui {
class recycledbin;
}

class recycledbin : public QDialog
{
    Q_OBJECT

public:
    explicit recycledbin(QWidget *parent = 0);
    ~recycledbin();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_resetList_clicked();

private:
    Ui::recycledbin *ui;
};

#endif // RECYCLEDBIN_H
