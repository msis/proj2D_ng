#ifndef PROJ2D_NG_H
#define PROJ2D_NG_H

#include <QMainWindow>

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

private:
    Ui::Proj2D_NG *ui;
    ibexUser *iUser;

signals:
    void parseEntry(QString);
};

#endif // PROJ2D_NG_H
