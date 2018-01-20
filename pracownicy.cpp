#include "pracownicy.h"
#include "ui_pracownicy.h"

Pracownicy::Pracownicy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pracownicy)
{
    ui->setupUi(this);
}

Pracownicy::~Pracownicy()
{
    delete ui;
}
