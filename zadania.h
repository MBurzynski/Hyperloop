#ifndef ZADANIA_H
#define ZADANIA_H

#include <QWidget>

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

    void on_checkBoxZespoly_clicked(bool checked);

    void on_checkBoxStacja_clicked(bool checked);

private:
    Ui::Zadania *ui;
};

#endif // ZADANIA_H
