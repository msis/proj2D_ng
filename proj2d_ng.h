#ifndef PROJ2D_NG_H
#define PROJ2D_NG_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

#include "ibexuser.h"

#define VARLABELCOL 0
#define LOWERBOUNDCOL 1
#define UPPERBOUNDCOL 2

namespace Ui {
class Proj2D_NG;
}

class Proj2D_NG : public QMainWindow
{
    Q_OBJECT

public:
    explicit Proj2D_NG(QWidget *parent = 0);
    ~Proj2D_NG();

    void setIbexUser(const ibexUser *);

private slots:
    void on_parseButton_clicked();
    void setNewVariables(int,QString);

    void on_pushButtonVarValidate_clicked();

private:
    Ui::Proj2D_NG *ui;
    const ibexUser *iUser;

    QMap<int,QString> varMap;



signals:
    void parseEntry(QString);
    void varInterval(int,QString,double,double);
};

#endif // PROJ2D_NG_H
