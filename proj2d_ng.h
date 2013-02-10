#ifndef PROJ2D_NG_H
#define PROJ2D_NG_H

#include <QMainWindow>
#include "ibex.h"

namespace Ui {
class Proj2D_NG;
}

class Proj2D_NG : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Proj2D_NG(QWidget *parent = 0);
    ~Proj2D_NG();
    
private:
    Ui::Proj2D_NG *ui;
};

#endif // PROJ2D_NG_H
