#ifndef ZESPOLY_H
#define ZESPOLY_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class Zespoly;
}

class Zespoly : public QWidget
{
    Q_OBJECT

public:
    explicit Zespoly(QWidget *parent = 0);
    ~Zespoly();

private:
    Ui::Zespoly *ui;
    QSqlQueryModel *qmodel;
};

#endif // ZESPOLY_H
