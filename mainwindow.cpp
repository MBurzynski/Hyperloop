#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //Nawiązanie połączenia z bazą
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("hyperloop");
    db.setUserName("root");
    db.setPassword("");

    //Próba otwarcia połączenia
    if(!db.open())
        std::cout<<"Błąd połączenia z bazą";
    else
        std::cout<<"Połączono się z bazą";

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
