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

    QSqlQuery query = data.showScientistData(username, searchString);

    modal->setQuery(query);

    ui->tableView->setModel(modal);

    data.databaseClose();
}

void MainWindow::on_pushButton_loadComputer_clicked()
{
    QString searchString = ui->lineEdit_searchComputer->text();

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query = data.showComputerData(username, searchString);

    modal->setQuery(query);

    ui->tableView_computers->setModel(modal);

    data.databaseClose();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    rowChosenScientist = ui->tableView->model()->data(index).toString();
}



void MainWindow::on_pushButton_deleteScientist_clicked()
{
    qDebug() << rowChosenScientist << endl;
}

void MainWindow::on_pushButton_editScientist_clicked()
{
    editStudentDialog edit;
    //Finna leið til að parsa inn ID
    edit.exec();
}

void MainWindow::on_pushButton_editComputer_clicked()
{
    int ID = ui->tableView_computers->currentIndex().row()+1;
    editComputerDialog edit(0, ID, username);
    edit.exec();
}
