#include "proj2d_ng.h"
#include "ui_proj2d_ng.h"

Proj2D_NG::Proj2D_NG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Proj2D_NG)
{
    ui->setupUi(this);
}

Proj2D_NG::~Proj2D_NG()
{
    delete ui;
}
