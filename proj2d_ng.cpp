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
//    delete iUser;
}

void Proj2D_NG::on_parseButton_clicked()
{
    emit parseEntry(ui->plainTextContraints->toPlainText());
}

void Proj2D_NG::setIbexUser(ibexUser *iU)
{
    disconnect(iUser);

    iUser = iU;

    connect(this,SIGNAL(parseEntry(QString)),
            iUser,SLOT(constraintsText(QString)));
    connect(ui->parseButton,SIGNAL(clicked()),
            iUser,SLOT(feedIbexWithFunction()));
}
