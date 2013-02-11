#include "proj2d_ng.h"
#include "ui_proj2d_ng.h"

Proj2D_NG::Proj2D_NG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Proj2D_NG)
{
    ui->setupUi(this);

    varsGridLayout= new QGridLayout(ui->tabVar);

    QLabel* labelVar = new QLabel("Variables");
    QLabel* labelType = new QLabel("Union / Intersection");
    QLabel* labelLB = new QLabel("Lower Bound");
    QLabel* labelUB = new QLabel("Upper Bound");

    varsGridLayout->addWidget(labelVar,0,VARLABELCOL);
    varsGridLayout->addWidget(labelLB,0,LOWERBOUNDCOL);
    varsGridLayout->addWidget(labelUB,0,UPPERBOUNDCOL);
//    varsGridLayout->addWidget(labelType,0,INTERVALCOMBINATIONTYPECOL);


    vars = new QStringList();
//    intComType = new QStringList();
//    intComType->append("Union");
//    intComType->append("Intersection");
}

Proj2D_NG::~Proj2D_NG()
{
    delete vars;
//    delete intComType;

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

    if (!vars->contains(s))
    {
        vars->append(s);
        updateTabVar();
    }

}

void Proj2D_NG::updateTabVar()
{
    //mettre à jour les anciens widget
    foreach (QComboBox *cB, ui->tabVar->findChildren<QComboBox *>()) {
        cB->clear();
        cB->addItems(*vars);
    }

    // rajout du dernier element au tableau
    int lastRow = varsGridLayout->rowCount();

    QComboBox *vB = new QComboBox();
    vB->addItems(*vars);

    varsGridLayout->addWidget(vB,lastRow,VARLABELCOL);

    QLineEdit *lBound = new QLineEdit();
    varsGridLayout->addWidget(lBound,lastRow,LOWERBOUNDCOL);

    QLineEdit *uBound = new QLineEdit();
    varsGridLayout->addWidget(uBound,lastRow,UPPERBOUNDCOL);

//    QComboBox *iCT = new QComboBox();//intervalCombinationType;
//    iCT->addItems(*intComType);
//    varsGridLayout->addWidget(iCT,lastRow,INTERVALCOMBINATIONTYPECOL);
}
