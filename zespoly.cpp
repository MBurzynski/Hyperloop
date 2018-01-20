#include "zespoly.h"
#include "ui_zespoly.h"

Zespoly::Zespoly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zespoly)
{
    ui->setupUi(this);
}

Zespoly::~Zespoly()
{
    delete ui;
}
