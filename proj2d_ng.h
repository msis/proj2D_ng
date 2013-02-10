#ifndef PROJ2D_NG_H
#define PROJ2D_NG_H

#include <QMainWindow>
#include <QGridLayout>

#include "ibexuser.h"

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


signals:
    void parseEntry(QString);
};

#endif // PROJ2D_NG_H
