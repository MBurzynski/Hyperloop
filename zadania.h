#ifndef ZADANIA_H
#define ZADANIA_H

#include <QWidget>
#include <QtSql>
#include <QDebug>

namespace Ui {
class Zadania;
}

class Zadania : public QWidget
{
    Q_OBJECT

public:
    explicit Zadania(QWidget *parent = 0);
    ~Zadania();

private slots:

    void on_checkBoxUwzglednijDate_clicked(bool checked);

    void on_checkBoxMiejscowosci_clicked(bool checked);

    void on_checkBoxKategoriaZadania_clicked(bool checked);

    void on_checkBoxStacja_clicked(bool checked);

    void on_pushButtonWyszukajWszystko_clicked();

    void on_pushButtonWyszukajPoKryteriach_clicked();

    void odswiez();

    void on_comboBoxKategoriaZadania_currentTextChanged(const QString &arg1);

    void on_comboBoxMiejscowosci_currentTextChanged(const QString &arg1);

    void on_comboBoxStacja_currentTextChanged(const QString &arg1);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_dateEdit_2_dateChanged(const QDate &date);

private:
    Ui::Zadania *ui;
    QSqlQueryModel *qmodel;
    QSortFilterProxyModel *m;
};

#endif // ZADANIA_H
