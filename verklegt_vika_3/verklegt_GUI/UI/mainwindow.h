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

    void on_pushButton_clicked();

    void on_silderVolume_sliderMoved(int position);

    void on_sliderprogress_sliderMoved(int position);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_duration_changed(qint64);

    void on_position_changed(qint64);

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
