#include "pracownicy.h"
#include "ui_pracownicy.h"

Pracownicy::Pracownicy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pracownicy)
{
    ui->setupUi(this);

    qmodel=new QSqlQueryModel();
    ui->tableViewPracownicy->setModel(qmodel);
    ui->tableViewPracownicy->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Pracownicy::~Pracownicy()
{
    delete ui;
}
