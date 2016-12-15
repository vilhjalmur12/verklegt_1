#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editstudentdialog.h"
#include "editcomputerdialog.h"
#include "insertscientist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_editComputer->setEnabled(false);
    ui->pushButton_editScientist->setEnabled(false);
    ui->pushButton_deleteScientist->setEnabled(false);
    ui->pushButton_deleteComputer->setEnabled(false);

    displayScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUserName(QString user)
{
    username = user;
    _service.setUser(username);
    qDebug() << "username: " << username;
}

void MainWindow::on_tableView_scientists_clicked(const QModelIndex &index)
{
       ui->pushButton_editScientist->setEnabled(true);
       ui->pushButton_deleteScientist->setEnabled(true);
}

void MainWindow::on_pushButton_deleteScientist_clicked()
{
        //_service.deleteScientist(username, name, lastName, year);
}

void MainWindow::on_pushButton_deleteComputer_clicked()
{
        //_service.deleteComputer(username, name, year);
}

void MainWindow::on_tableView_computers_clicked(const QModelIndex &index)
{
    ui->pushButton_editComputer->setEnabled(true);
    ui->pushButton_deleteComputer->setEnabled(true);
}

void MainWindow::on_pushButton_editScientist_clicked()
{
    int ID = ui->tableView_scientists->currentIndex().row()+1;//////////////////////////////////////////////////////////skoða betur
    editStudentDialog edit(this, ID, username);
    edit.exec();
}

void MainWindow::on_pushButton_editComputer_clicked()
{
    int ID = ui->tableView_computers->currentIndex().row()+1;//////////////////////////////////////////////////////////skoða betur
    editComputerDialog edit(this, ID, username);
    edit.exec();
}

void MainWindow::on_pushButton_recycleBinComputers_clicked()
{
    QString choice = "computers";
    recycleBin.callRecycleBin(username, choice);
}

void MainWindow::on_pushButton_insertScientist_clicked()
{
    insertScientist insert(this, username);

    insert.exec();
}

void MainWindow::displayScientists()
{
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

    qDebug() << "size: " << scientists.size();

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
        QString further =     QString::fromStdString(scientists[i].getFurtherInfo());

        ui->tableView_scientists->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableView_scientists->setItem(i, 1, new QTableWidgetItem(lastName));
        ui->tableView_scientists->setItem(i, 2, new QTableWidgetItem(firstName));
        ui->tableView_scientists->setItem(i, 3, new QTableWidgetItem(gender));
        ui->tableView_scientists->setItem(i, 4, new QTableWidgetItem(YOB));
        ui->tableView_scientists->setItem(i, 5, new QTableWidgetItem(YOD));
        ui->tableView_scientists->setItem(i, 6, new QTableWidgetItem(nationality));
        ui->tableView_scientists->setItem(i, 7, new QTableWidgetItem(further));
    }
}
