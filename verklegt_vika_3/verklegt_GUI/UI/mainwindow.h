#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMediaPlayer>
#include <QDebug>
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
    explicit MainWindow(QWidget *parent = 0, QString user = "");
    virtual ~MainWindow();
    void setUserName(QString user);
    void displayComputers();
    void displayScientists();

private slots:
    void on_tableView_scientists_clicked(const QModelIndex &index);

    void on_pushButton_deleteScientist_clicked();

    void on_pushButton_deleteComputer_clicked();

    void on_tableView_computers_clicked(const QModelIndex &index);

    void on_pushButton_editScientist_clicked();

    void on_pushButton_editComputer_clicked();

    void on_pushButton_recycleBinComputers_clicked();

    void on_pushButton_insertScientist_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_lineEdit_searchComputer_textChanged(const QString &arg1);

    void on_sildeProgress_sliderMoved(int position); //progerss slide

    void on_slideVolume_sliderMoved(int position);   //volume slide

    void on_pushButton_clicked();                   //start/stop

    void on_pushButton_2_clicked();                 //start/stop

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);


private:
    Ui::MainWindow *ui;
    Database data;
    QString username;
    Service _service;
    recycledbin recycleBin;
    vector<Scientist> scientists;
    vector<Computer> computers;



};

#endif // MAINWINDOW_H
