#include "zadania.h"
#include "ui_zadania.h"

Zadania::Zadania(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zadania)
{
    ui->setupUi(this);
}

Zadania::~Zadania()
{
    delete ui;
}

void Zadania::on_checkBoxUwzglednijDate_clicked(bool checked)
{
    switch (checked) {
    case true:
        ui->dateEdit->setEnabled(true);
        ui->dateEdit_2->setEnabled(true);
        break;
    case false:
        ui->dateEdit->setEnabled(false);
        ui->dateEdit_2->setEnabled(false);
        break;
    default:
        ui->dateEdit->setEnabled(false);
        ui->dateEdit_2->setEnabled(false);
        break;
    }
}

void Zadania::on_checkBoxMiejscowosci_clicked(bool checked)
{
    switch (checked) {
    case true:
        ui->comboBoxMiejscowosci->setEnabled(true);
        break;
    case false:
        ui->comboBoxMiejscowosci->setEnabled(false);
        break;
    default:
        ui->comboBoxMiejscowosci->setEnabled(false);
        break;
    }
}

void Zadania::on_checkBoxZespoly_clicked(bool checked)
{
    switch (checked) {
    case true:
        ui->comboBoxZespoly->setEnabled(true);
        break;
    case false:
        ui->comboBoxZespoly->setEnabled(false);
        break;
    default:
        ui->comboBoxZespoly->setEnabled(false);
        break;
    }
}

void Zadania::on_checkBoxStacja_clicked(bool checked)
{
    switch (checked) {
    case true:
        ui->comboBoxStacja->setEnabled(true);
        break;
    case false:
        ui->comboBoxStacja->setEnabled(false);
        break;
    default:
        ui->comboBoxStacja->setEnabled(false);
        break;
    }
}
