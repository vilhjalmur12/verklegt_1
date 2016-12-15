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
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setUserName(QString user)
{
    username = user;
}


void MainWindow::on_pushButton_loadScientist_clicked()
{
    QString searchString = ui->lineEdit_search->text();

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query = _service.showScientistData(username, searchString);

    modal->setQuery(query);

    ui->tableView->setModel(modal);

    _service.closeDatabase();
}


void MainWindow::on_pushButton_loadComputer_clicked()
{

    QString searchString = ui->lineEdit_searchComputer->text();

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query = _service.showComputerData(username, searchString);

    modal->setQuery(query);

    ui->tableView_computers->setModel(modal);

    _service.closeDatabase();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
       rowChosen = ui-> tableView->currentIndex().row();
       name = index.sibling(rowChosen, 0).data().toString();
       lastName = index.sibling(rowChosen, 1).data().toString();
       year = index.sibling(rowChosen, 3).data().toString();

       ui->pushButton_editScientist->setEnabled(true);
       ui->pushButton_deleteScientist->setEnabled(true);
}

void MainWindow::on_pushButton_deleteScientist_clicked()
{
        _service.deleteScientist(username, name, lastName, year);
}


void MainWindow::on_pushButton_deleteComputer_clicked()
{
        _service.deleteComputer(username, name, year);
}


void MainWindow::on_tableView_computers_clicked(const QModelIndex &index)
{
    rowChosen = ui-> tableView_computers->currentIndex().row();
    name = index.sibling(rowChosen, 0).data().toString();
    year = index.sibling(rowChosen, 1).data().toString();

    ui->pushButton_editComputer->setEnabled(true);
    ui->pushButton_deleteComputer->setEnabled(true);
}

void MainWindow::on_pushButton_editScientist_clicked()
{
    int ID = ui->tableView->currentIndex().row()+1;//////////////////////////////////////////////////////////skoða betur
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
