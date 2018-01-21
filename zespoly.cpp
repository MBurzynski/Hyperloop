#include "zespoly.h"
#include "ui_zespoly.h"

Zespoly::Zespoly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zespoly)
{
    ui->setupUi(this);

    qmodel=new QSqlQueryModel();
    ui->tableViewZespoly->setModel(qmodel);
    ui->tableViewZespoly->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Zespoly::~Zespoly()
{
    delete ui;
}
