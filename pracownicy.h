#ifndef PRACOWNICY_H
#define PRACOWNICY_H

#include <QWidget>

namespace Ui {
class Pracownicy;
}

class Pracownicy : public QWidget
{
    Q_OBJECT

public:
    explicit Pracownicy(QWidget *parent = 0);
    ~Pracownicy();

private:
    Ui::Pracownicy *ui;
};

#endif // PRACOWNICY_H
