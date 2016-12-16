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
    void displayComputers();                                            //Sækir upplýsingar um tölvu og byrtir í töflu
    void displayScientists();                                           //Sækir upplýsingar um vísindamann og byrtir í töflu

private slots:
    void on_tableView_scientists_clicked();                             //Notandi getur edit-að eða eitt þeim vísindamann sem valin er í lista

    void on_pushButton_deleteScientist_clicked();                       //Notandi eyðir vísindamanni með því að ýta á delete takka

    void on_pushButton_deleteComputer_clicked();                        //Notandi eyðir tölvu með því að ýta á delete takka

    void on_tableView_computers_clicked();                              //Notandi getur edit-að eða eitt þeim vísindamann sem valin er í lista

    void on_pushButton_editScientist_clicked();                         //Notandi getur edit-að vísindamann sem valin er með því að ýta á edit takka

    void on_pushButton_editComputer_clicked();                          //Notandi getur edit-að tölvu sem valin er með því að ýta á edit takka

    void on_pushButton_recycleBinComputers_clicked();                   //Opnar glugga fyrir recycle bin fyrir tölvu

    void on_pushButton_insertScientist_clicked();                       //Opnar glugga fyrir insert fyrir vísindaman

    void on_lineEdit_search_textChanged();                              //Filterar tölfu út frá leitarstreng frá notanda

    void on_lineEdit_searchComputer_textChanged();                      //Filterar tölfu út frá leitarstreng frá notanda

    void on_pushButton_clicked();

    void on_silderVolume_sliderMoved(int position);                     //Slider sem sýnir og stillir hljóð á lagi

    void on_sliderProgress_sliderMoved(int position);                   //Slider sem sýnir og stillir progress á lagi

    void on_startButton_clicked();                                      //Load-ar lagi og hefur spilun

    void on_stopButton_clicked();                                       //Stoppar lagi í spilun

    void on_duration_changed(qint64 position);                          //Stillir af duration fyrir lag

    void on_position_changed(qint64 position);                          //Stillir af staðsetningu á lagi

    void on_tableView_computers_doubleClicked();                        //Notandi getur doulbe klikkað á tölvu til að edita

    void on_tableView_scientists_doubleClicked();                       //Notandi getur doulbe klikkað á vísindamann til að edita

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
