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
    void on_tableView_scientists_clicked();

    void on_pushButton_deleteScientist_clicked();

    void on_pushButton_deleteComputer_clicked();

    void on_tableView_computers_clicked();

    void on_pushButton_editScientist_clicked();

    void on_pushButton_editComputer_clicked();

    void on_pushButton_recycleBinComputers_clicked();

    void on_pushButton_insertScientist_clicked();

    void on_lineEdit_search_textChanged();

    void on_lineEdit_searchComputer_textChanged();

    void on_pushButton_clicked();

    void on_silderVolume_sliderMoved(int position);

    void on_sliderProgress_sliderMoved(int position);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_duration_changed(qint64 position);

    void on_position_changed(qint64 position);

    void on_tableView_computers_doubleClicked();

    void on_tableView_scientists_doubleClicked();

    void on_pushButton_recycledScientists_clicked();

private:
    Ui::MainWindow *ui;
    Database data;
    QString username;
    Service _service;
    recycledbin recycleBin;
    vector<Scientist> scientists;
    vector<Computer> computers;
    QMediaPlayer* player;



};

#endif // MAINWINDOW_H
