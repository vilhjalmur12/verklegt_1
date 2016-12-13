#include "mainwindow.h"
#include "ui_mainwindow.h"

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
