#ifndef PROJ2D_NG_H
#define PROJ2D_NG_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

#include "ibexuser.h"

#define VARLABELCOL 0
#define INTERVALCOMBINATIONTYPECOL 3
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

    void setIbexUser(ibexUser *);

private slots:
    void on_parseButton_clicked();
    void setNewVariables(int,QString);




private:
    Ui::Proj2D_NG *ui;
    ibexUser *iUser;

    QMap<int,QString> varMap;

    QGridLayout* varsGridLayout;

    QStringList *vars;
//    QStringList *intComType;

    void updateTabVar();


signals:
    void parseEntry(QString);
};

#endif // PROJ2D_NG_H
