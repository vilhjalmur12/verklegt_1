#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "Domain/service.h"
#include "recycledbin.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void setUserName(QString user);

private slots:
    void on_pushButton_loadScientist_clicked();

    void on_pushButton_loadComputer_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_deleteScientist_clicked();

    void on_pushButton_deleteComputer_clicked();

    void on_tableView_computers_clicked(const QModelIndex &index);

    void on_pushButton_editScientist_clicked();

    void on_pushButton_editComputer_clicked();

    void on_pushButton_recycleBinComputers_clicked();

private:
    Ui::MainWindow *ui;
    Database data;
    QString username;
    Service _service;
    recycledbin recycleBin;

    int rowChosen;
    QString year;
    QString name;
    QString lastName;


};

#endif // MAINWINDOW_H
