#include "zadania.h"
#include "ui_zadania.h"

Zadania::Zadania(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zadania)
{
    ui->setupUi(this);

    qmodel=new QSqlQueryModel();
    ui->tableViewZadania->setModel(qmodel);
    ui->tableViewZadania->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Wypełnienie listy comboBoxMiejscowosci danymi z bazy
    QString zapytanieMiejscowosci = "SELECT NAZWA FROM MIEJSCOWOSCI";
    QSqlQuery qMiejscowosci;
    qMiejscowosci.exec(zapytanieMiejscowosci);

    if(qMiejscowosci.size()!=0)
    {
        while(qMiejscowosci.next())
        {
            QString miejscowoscZBazy = qMiejscowosci.value(0).toString();
            ui->comboBoxMiejscowosci->addItem(miejscowoscZBazy);
        }
    }

    //Wypełnienie listy comboBoxKategorie danymi z bazy
    QString zapytanieKategorie = "SELECT NAZWA FROM KATEGORIA_ZADANIA";
    QSqlQuery qKategorie;
    qKategorie.exec(zapytanieKategorie);

    if(qKategorie.size()!=0)
    {
        while(qKategorie.next())
        {
            QString kategoriaZBazy = qKategorie.value(0).toString();
            ui->comboBoxKategoriaZadania->addItem(kategoriaZBazy);
        }
    }

    //Wypełnienie listy comboBoxStacje danymi z bazy
    QString zapytanieStacje = "SELECT NAZWA FROM STACJE";
    QSqlQuery qStacje;
    qStacje.exec(zapytanieStacje);

    if(qStacje.size()!=0)
    {
        while(qStacje.next())
        {
            QString stacjaZBazy = qStacje.value(0).toString();
            ui->comboBoxStacja->addItem(stacjaZBazy);
        }
    }
}

Zadania::~Zadania()
{
    delete ui;
    delete qmodel;
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

void Zadania::on_checkBoxKategoriaZadania_clicked(bool checked)
{
    switch (checked) {
    case true:
        ui->comboBoxKategoriaZadania->setEnabled(true);
        break;
    case false:
        ui->comboBoxKategoriaZadania->setEnabled(false);
        break;
    default:
        ui->comboBoxKategoriaZadania->setEnabled(false);
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

void Zadania::on_pushButtonWyszukajWszystko_clicked()
{
    QString zapytanie =  "SELECT z.NAZWA, z.STATUS, z.PRIORYTET, z.BUDZET, z.ZLECENIODAWCA, z.TRUDNOSC, z.KOSZTA, z.RODZAJ, z.OPIS, kz.NAZWA AS KATEGORIA_ZADANIA, m.NAZWA AS MIEJSCOWOŚĆ, T.DATA as DATA_ZADANIA FROM ZADANIA AS Z JOIN kategoria_zadania as KZ using(ID_KATEGORII) left JOIN stacje as S USING (ID_STACJI) left JOIN miejscowosci as M on(s.ID_MIASTA=m.ID_MIASTA) LEFT JOIN terminy as T USING(ID_TERMINU)";

    qmodel->setQuery(zapytanie);

}

void Zadania::on_pushButtonWyszukajPoKryteriach_clicked()
{
    odswiez();
}

void Zadania::odswiez()
{
    QString miejscowosc = " 1=1 ";
    QString stacja = " 1=1";
    QString kategoriaZadania = "1=1";
    QDate dataPoczatkowa;
    QDate dataKoncowa;
    QString dataPoczatkowaString = " 2000-01-01 ";
    QString dataKoncowaString = " 2099-12-12 ";

    if(ui->checkBoxMiejscowosci->isChecked())
    {
        miejscowosc = " M.NAZWA = '" + ui->comboBoxMiejscowosci->currentText() + "'";
    }
    if(ui->checkBoxStacja->isChecked())
    {
        stacja = " S.NAZWA = '" + ui->comboBoxStacja->currentText() + "'";
    }
    if(ui->checkBoxKategoriaZadania->isChecked())
    {
        kategoriaZadania = " KZ.NAZWA = '" + ui->comboBoxKategoriaZadania->currentText() + "'";
    }

    if(ui->checkBoxUwzglednijDate->isChecked())
    {
        dataPoczatkowa = ui->dateEdit->date();
        dataPoczatkowaString = dataPoczatkowa.toString("yyyy.MM.dd");

        dataKoncowa = ui->dateEdit_2->date();
        dataKoncowaString = dataKoncowa.toString("yyyy.MM.dd");
    }


    QString zapytanie =  "SELECT z.NAZWA, z.STATUS, z.PRIORYTET, z.BUDZET, z.ZLECENIODAWCA, z.TRUDNOSC, z.KOSZTA,\
 z.RODZAJ, z.OPIS, kz.NAZWA AS KATEGORIA_ZADANIA, m.NAZWA AS MIEJSCOWOŚĆ, T.DATA as DATA_ZADANIA\
 FROM ZADANIA AS Z JOIN kategoria_zadania as KZ using(ID_KATEGORII) left JOIN stacje as S USING (ID_STACJI)\
 left JOIN miejscowosci as M on(s.ID_MIASTA=m.ID_MIASTA) LEFT JOIN terminy as T USING(ID_TERMINU)\
 WHERE (" + miejscowosc + ") AND (" + stacja + ") AND (" + kategoriaZadania + ")\
 AND (T.DATA >= '" + dataPoczatkowaString + "' AND T.DATA <= '" + dataKoncowaString + "' )";

    qDebug()<<zapytanie;
    qmodel->setQuery(zapytanie);
    ui->tableViewZadania->setColumnWidth(0, 200); //Żeby się mieściło
    ui->tableViewZadania->setColumnWidth(9, 140);
}

void Zadania::on_comboBoxKategoriaZadania_currentTextChanged(const QString &arg1)
{
    odswiez();
}

void Zadania::on_comboBoxMiejscowosci_currentTextChanged(const QString &arg1)
{
    odswiez();
}

void Zadania::on_comboBoxStacja_currentTextChanged(const QString &arg1)
{
    odswiez();
}

void Zadania::on_dateEdit_dateChanged(const QDate &date)
{
    odswiez();
}

void Zadania::on_dateEdit_2_dateChanged(const QDate &date)
{
    odswiez();
}
