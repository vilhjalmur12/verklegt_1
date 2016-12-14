#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "editstudentdialog.h"
#include "editcomputerdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

void MainWindow::on_pushButton_editScientist_clicked()
{
    int ID = ui->tableView_computers->currentIndex().row()+1;//////////////////////////////////////////////////////////skoða betur
    editStudentDialog edit(0, ID, username);
    edit.exec();
}

void MainWindow::on_pushButton_editComputer_clicked()
{
    int ID = ui->tableView_computers->currentIndex().row()+1;//////////////////////////////////////////////////////////skoða betur
    editComputerDialog edit(0, ID, username);
    edit.exec();
}

void MainWindow::on_pushButton_recycleBin_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query = _service.getRecycledComputers(username);

    modal->setQuery(query);

    ui->tableView_computers->setModel(modal);

    _service.closeDatabase();
}
