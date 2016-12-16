#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editstudentdialog.h"
#include "editcomputerdialog.h"
#include "insertscientist.h"
#include "insertcomputerdialog.h"

/******************************************************************
                      Constructor / Destructor
*******************************************************************/

MainWindow::MainWindow(QWidget *parent, QString user) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    username = user;
    _service.setUser(user);

    ui->tableView_scientists->setColumnWidth(1,90);
    ui->tableView_scientists->setColumnWidth(2,90);
    ui->tableView_scientists->setColumnWidth(3,70);
    ui->tableView_scientists->setColumnWidth(4,60);
    ui->tableView_scientists->setColumnWidth(5,60);
    ui->tableView_scientists->setColumnWidth(6,90);
    ui->tableView_scientists->setColumnWidth(7,180);
    ui->tableView_scientists->setColumnWidth(8,20);

    ui->tableView_computers->setColumnWidth(1,190);
    ui->tableView_computers->setColumnWidth(2,90);
    ui->tableView_computers->setColumnWidth(3,160);
    ui->tableView_computers->setColumnWidth(4,100);
    ui->tableView_computers->setColumnWidth(5,20);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_position_changed);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_duration_changed);


}

MainWindow::~MainWindow()
{
    delete ui;
}

/******************************************************************
                       setUserName
*******************************************************************/

void MainWindow::setUserName(QString user)
{
    username = user;
    _service.setUser(username);
}

/******************************************************************
             on_tableView_scientists_clicked
    Notandi getur edit-að eða eitt þeim vísindamann sem valin er
    í lista
*******************************************************************/

void MainWindow::on_tableView_scientists_clicked()
{
       ui->pushButton_editScientist->setEnabled(true);
       ui->pushButton_deleteScientist->setEnabled(true);
}

/******************************************************************
           on_pushButton_deleteScientist_clicked
    Notandi eyðir vísindamanni með því að ýta á delete takka
*******************************************************************/

void MainWindow::on_pushButton_deleteScientist_clicked()
{
    ui->pushButton_editScientist->setEnabled(false);
    ui->pushButton_deleteScientist->setEnabled(false);

    int row = ui->tableView_scientists->currentRow();
    int ID = ui->tableView_scientists->item(row, 0)->text().toInt();
    _service.deleteScientist(ID);

    displayScientists();
}

/******************************************************************
           on_pushButton_deleteComputer_clicked
    Notandi eyðir tölvu með því að ýta á delete takka
*******************************************************************/

void MainWindow::on_pushButton_deleteComputer_clicked()
{
    ui->pushButton_editComputer->setEnabled(false);
    ui->pushButton_deleteComputer->setEnabled(false);

    int row = ui->tableView_computers->currentRow();
    int ID = ui->tableView_computers->item(row, 0)->text().toInt();
    _service.deleteComputer(ID);

    displayComputers();
}

/******************************************************************
           on_tableView_computers_clicked
    Notandi getur edit-að eða eitt þeim vísindamann sem valin er
    í lista
*******************************************************************/

void MainWindow::on_tableView_computers_clicked()
{
    ui->pushButton_editComputer->setEnabled(true);
    ui->pushButton_deleteComputer->setEnabled(true);
}

/******************************************************************
           on_pushButton_editScientist_clicked
    Notandi getur edit-að vísindamann sem valin er
    með því að ýta á edit takka
*******************************************************************/

void MainWindow::on_pushButton_editScientist_clicked()
{
    ui->pushButton_editScientist->setEnabled(false);
    ui->pushButton_deleteScientist->setEnabled(false);

    int row = ui->tableView_scientists->currentRow();
    int ID = ui->tableView_scientists->item(row, 0)->text().toInt();
    editStudentDialog edit(this, ID, username);
    edit.exec();

    displayScientists();
}

/******************************************************************
           on_pushButton_editComputer_clicked
    Notandi getur edit-að tölvu sem valin er
    með því að ýta á edit takka
*******************************************************************/

void MainWindow::on_pushButton_editComputer_clicked()
{
    ui->pushButton_editComputer->setEnabled(false);
    ui->pushButton_deleteComputer->setEnabled(false);

    int row = ui->tableView_computers->currentRow();
    int ID = ui->tableView_computers->item(row, 0)->text().toInt();

    editComputerDialog edit(this, ID, username);
    edit.exec();

    displayComputers();
}

/******************************************************************
           on_pushButton_recycleBinComputers_clicked
         Opnar glugga fyrir recycle bin fyrir tölvu
*******************************************************************/

void MainWindow::on_pushButton_recycleBinComputers_clicked()
{
    QString choice = "computers";
    recycleBin.callRecycleBin(username, choice);
}

/******************************************************************
           on_pushButton_recycleBinComputers_clicked
         Opnar glugga fyrir recycle bin fyrir tölvu
*******************************************************************/

void MainWindow::on_pushButton_recycledScientists_clicked()
{
    QString choice = "scientists";
    recycleBin.callRecycleBin(username, choice);
}

/******************************************************************
          on_pushButton_insertScientist_clicked
         Opnar glugga fyrir insert fyrir vísindamann
*******************************************************************/

void MainWindow::on_pushButton_insertScientist_clicked()
{
    insertScientist insert(this, username);

    insert.exec();

    displayScientists();
}

/******************************************************************
                       displayScientists
        Sækir upplýsingar um vísindamann og byrtir í töflu
*******************************************************************/

void MainWindow::displayScientists()
{
    ui->tableView_scientists->setSortingEnabled(false);
    string query = ui->lineEdit_search->text().toStdString();

    if(query == "")
    {
        scientists.clear();
        scientists = _service.getScientists();
    }
    else
    {
        _service.searchInDatabase(scientists, computers, query);
    }

    ui->tableView_scientists->clearContents();
    ui->tableView_scientists->setRowCount(scientists.size());
    ui->tableView_scientists->setColumnHidden(0, true);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        QString id =          QString::fromStdString(to_string(scientists[i].getID()));
        QString lastName =    QString::fromStdString(scientists[i].getLastName());
        QString firstName =   QString::fromStdString(scientists[i].getFirstName());
        QString gender =      QString::fromStdString(scientists[i].getSex());
        QString YOB =         QString::fromStdString(to_string(scientists[i].getYearOfBirth()));
        QString YOD =         QString::fromStdString(scientists[i].getYearOfDeathForPrinting());
        QString nationality = QString::fromStdString(scientists[i].getNationality());
        QString built =       QString::fromStdString(scientists[i].getComputersBuilt());
        QString further =     QString::fromStdString(scientists[i].getFurtherInfo());

        ui->tableView_scientists->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableView_scientists->setItem(i, 1, new QTableWidgetItem(lastName));
        ui->tableView_scientists->setItem(i, 2, new QTableWidgetItem(firstName));
        ui->tableView_scientists->setItem(i, 3, new QTableWidgetItem(gender));
        ui->tableView_scientists->setItem(i, 4, new QTableWidgetItem(YOB));
        ui->tableView_scientists->setItem(i, 5, new QTableWidgetItem(YOD));
        ui->tableView_scientists->setItem(i, 6, new QTableWidgetItem(nationality));
        ui->tableView_scientists->setItem(i, 7, new QTableWidgetItem(built));
        ui->tableView_scientists->setItem(i, 8, new QTableWidgetItem(further));
    }
    ui->pushButton_editScientist->setEnabled(false);
    ui->pushButton_deleteScientist->setEnabled(false);

    ui->pushButton_editScientist->setStyleSheet(QString::fromUtf8("QPushButton:disabled"
    "{color: gray}"
    ));
    ui->pushButton_deleteScientist->setStyleSheet(QString::fromUtf8("QPushButton:disabled"
    "{color: gray}"
    ));

    ui->tableView_scientists->setSortingEnabled(true);
}

/******************************************************************
                       displayComputers
        Sækir upplýsingar um tölvur og byrtir í töflu
*******************************************************************/

void MainWindow::displayComputers()
{
    ui->tableView_computers->setSortingEnabled(false);
    string query = ui->lineEdit_searchComputer->text().toStdString();

    if(query == "")
    {
        computers.clear();
        computers = _service.getComputers();
    }
    else
    {
        _service.searchInDatabase(scientists, computers, query);
    }

    ui->tableView_computers->clearContents();
    ui->tableView_computers->setRowCount(computers.size());
    ui->tableView_computers->setColumnHidden(0, true);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        QString id =          QString::fromStdString(to_string(computers[i].getID()));
        QString lastName =    QString::fromStdString(computers[i].getName());
        QString YOB =         QString::fromStdString(computers[i].getYearForPrinting());
        QString type =        QString::fromStdString(computers[i].getCpuType());
        QString built =       QString::fromStdString(computers[i].getBuiltForPrinting());
        QString builders =    QString::fromStdString(computers[i].getBuilders());

        ui->tableView_computers->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableView_computers->setItem(i, 1, new QTableWidgetItem(lastName));
        ui->tableView_computers->setItem(i, 2, new QTableWidgetItem(YOB));
        ui->tableView_computers->setItem(i, 3, new QTableWidgetItem(type));
        ui->tableView_computers->setItem(i, 4, new QTableWidgetItem(built));
        ui->tableView_computers->setItem(i, 5, new QTableWidgetItem(builders));
    }
    ui->pushButton_editComputer->setEnabled(false);
    ui->pushButton_deleteComputer->setEnabled(false);

    ui->pushButton_editComputer->setStyleSheet(QString::fromUtf8("QPushButton:disabled"
    "{color: gray}"
    ));
    ui->pushButton_deleteComputer->setStyleSheet(QString::fromUtf8("QPushButton:disabled"
    "{color: gray}"
    ));

    ui->tableView_computers->setSortingEnabled(true);
}

/******************************************************************
                 on_lineEdit_search_textChanged
        Filterar tölfu út frá leitarstreng frá notanda
*******************************************************************/

void MainWindow::on_lineEdit_search_textChanged()
{
    displayScientists();
}

/******************************************************************
                 on_lineEdit_searchComputer_textChanged
        Filterar tölfu út frá leitarstreng frá notanda
*******************************************************************/

void MainWindow::on_lineEdit_searchComputer_textChanged()
{
    displayComputers();
}

void MainWindow::on_pushButton_clicked()
{
    insertComputerDialog insert(this, username);

    insert.exec();
    displayComputers();
}

/******************************************************************
                 on_silderVolume_sliderMoved
        Slider sem sýnir og stillir hljóð á lagi
*******************************************************************/

void MainWindow::on_silderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

/******************************************************************
                 on_sliderProgress_sliderMoved
        Slider sem sýnir og stillir progress á lagi
*******************************************************************/

void MainWindow::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

/******************************************************************
                 on_startButton_clicked
        Load-ar lagi og hefur spilun
*******************************************************************/

void MainWindow::on_startButton_clicked()
{
    QString loc =  qApp->applicationDirPath();
    qDebug() << loc;
    player->setMedia(QUrl::fromLocalFile(loc + "/media/LetItSnow.mp3"));
    player->play();
    qDebug() << player->errorString();
}

/******************************************************************
                 on_stopButton_clicked
             Stoppar lagi í spilun
*******************************************************************/

void MainWindow::on_stopButton_clicked()
{
    player->stop();
}


/******************************************************************
                 on_duration_changed
       Hversu mikið er búið af laginu
       @parametet(qint64 position) - hversu mikið er búið af laginu
*******************************************************************/

void MainWindow::on_duration_changed(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}


/******************************************************************
                 on_position_changed
             Stillir staðsetningu á lagi
       @parametet(qint64 position) - hversu mikið er búið af laginu
*******************************************************************/

void MainWindow::on_position_changed(qint64 position)
{
    ui->sliderProgress->setValue(position);
}


/******************************************************************
                 on_tableView_computers_doubleClicked
             Notandi getur doulbe klikkað á tölvu til að edita
       @parametet(const QModelIndex &index) - index á tölvu
*******************************************************************/

void MainWindow::on_tableView_computers_doubleClicked()

{
    ui->pushButton_editComputer->setEnabled(false);
    ui->pushButton_deleteComputer->setEnabled(false);

    int row = ui->tableView_computers->currentRow();
    int ID = ui->tableView_computers->item(row, 0)->text().toInt();

    editComputerDialog edit(this, ID, username);
    edit.exec();

    displayComputers();
}


/******************************************************************
                 on_tableView_scientists_doubleClicked
             Notandi getur doulbe klikkað á vísindamann til að edita
       @parametet(const QModelIndex &index) -index á vísindamanni
*******************************************************************/

void MainWindow::on_tableView_scientists_doubleClicked()

{
    ui->pushButton_editScientist->setEnabled(false);
    ui->pushButton_deleteScientist->setEnabled(false);

    int row = ui->tableView_scientists->currentRow();
    int ID = ui->tableView_scientists->item(row, 0)->text().toInt();
    editStudentDialog edit(this, ID, username);
    edit.exec();

    displayScientists();
}


