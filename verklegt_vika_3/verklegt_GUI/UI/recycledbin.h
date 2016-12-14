#ifndef RECYCLEDBIN_H
#define RECYCLEDBIN_H

#include <QDialog>
#include "Domain/service.h"

namespace Ui {
class recycledbin;
}

class recycledbin : public QDialog
{
    Q_OBJECT

public:
    explicit recycledbin(QWidget *parent = 0);
    ~recycledbin();
    void callRecycleBin (QString username, QString choice);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_resetList_clicked();

    void recycledComputers();
    void recycledScientists();

private:
    Ui::recycledbin *ui;
    Service _service;
    QString user;
};

#endif // RECYCLEDBIN_H
