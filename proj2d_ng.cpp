#include "proj2d_ng.h"
#include "ui_proj2d_ng.h"

Proj2D_NG::Proj2D_NG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Proj2D_NG)
{
    ui->setupUi(this);


    ui->intervalTypeComboBox->addItem("Union");
    ui->intervalTypeComboBox->addItem("Intersection");

//    ui->varComboBox->hide();
//    ui->intervalTypeComboBox->hide();
//    ui->upperBoundSpinBox->hide();
//    ui->lowerBoundSpinBox->hide();
}

Proj2D_NG::~Proj2D_NG()
{
    delete ui;
//    delete iUser;
}

void Proj2D_NG::on_parseButton_clicked()
{
    emit parseEntry(ui->plainTextContraints->toPlainText());
    ui->tabVar->setEnabled(true);
}

void Proj2D_NG::setIbexUser(ibexUser *iU)
{
    disconnect(iUser);

    iUser = iU;

    connect(this,SIGNAL(parseEntry(QString)),
            iUser,SLOT(constraintsText(QString)));
    connect(ui->parseButton,SIGNAL(clicked()),
            iUser,SLOT(feedIbexWithFunction()));
    connect(iUser,SIGNAL(newVariableFound(int,QString)),
            this,SLOT(setNewVariables(int,QString)));
}

void Proj2D_NG::setNewVariables(int i, QString s)
{
    varMap.insert(i,s); //the insert automatically erases already existing variable

    if(ui->varComboBox->findText(s)==-1) //adds the variable if not already there
        ui->varComboBox->addItem(s);

//    QComboBox newV(ui->varComboBox);
//    QComboBox newIntervalType(ui->intervalTypeComboBox);
//    QDoubleSpinBox newLowerBound(ui->lowerBoundSpinBox);
//    QDoubleSpinBox newUpperBound(ui->upperBoundSpinBox);

//    QHBoxLayout layout;
//    layout.addWidget(&newV);
//    layout.addWidget(&newIntervalType);
//    layout.addWidget(&newLowerBound);
//    layout.addWidget(&newUpperBound);

//    int beforeLastRow = ui->varGridLayout->rowCount()-2;

//    ui->varGridLayout->setLayout(&layout,beforeLastRow,0,4,1);

}
