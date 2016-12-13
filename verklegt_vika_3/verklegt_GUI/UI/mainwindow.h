#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DATA/database.h"
#include <QSqlQueryModel>

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

private:
    Ui::MainWindow *ui;
    Database data;
    QString username;
    QString rowChosenScientist;

};

#endif // MAINWINDOW_H
