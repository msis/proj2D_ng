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

    disconnect(iUser);
}

void Proj2D_NG::on_parseButton_clicked()
{
    emit parseEntry(ui->plainTextContraints->toPlainText());
    ui->tabVar->setEnabled(true);
}

void Proj2D_NG::setIbexUser(const ibexUser *iU)
{
    disconnect(iUser);

    iUser = iU;

    connect(this,SIGNAL(parseEntry(QString)),
            iUser,SLOT(constraintsText(QString)));
    connect(ui->parseButton,SIGNAL(clicked()),
            iUser,SLOT(feedIbexWithFunction()));
    connect(iUser,SIGNAL(newVariableFound(int,QString)),
            this,SLOT(setNewVariables(int,QString)));
    connect(this,SIGNAL(varInterval(int,QString,double,double)),
            iUser,SLOT(setVarInterval(int,QString,double,double)));
    connect(ui->pushButtonVarValidate,SIGNAL(clicked()),
            iUser,SLOT(setStartBox()));
}

void Proj2D_NG::setNewVariables(int i, QString s)
{
    if (!varMap.contains(i))
    {
        varMap.insert(i,s); //the insert automatically erases already existing variable

        // rajout du dernier element au tableau
        int lastRow = ui->gridLayoutVariables->rowCount();

        QLabel *varLab = new QLabel(s);
        ui->gridLayoutVariables->addWidget(varLab,lastRow,VARLABELCOL);

        QLineEdit *lBound = new QLineEdit();
        lBound->setObjectName(s+"lB");
        ui->gridLayoutVariables->addWidget(lBound,lastRow,LOWERBOUNDCOL);

        QLineEdit *uBound = new QLineEdit();
        uBound->setObjectName(s+"uB");
        ui->gridLayoutVariables->addWidget(uBound,lastRow,UPPERBOUNDCOL);
    }
}


void Proj2D_NG::on_pushButtonVarValidate_clicked()
{
    QMapIterator<int, QString> i(varMap);
    while (i.hasNext())
    {
        i.next();

        QLineEdit *lBound = ui->tabVar->findChild<QLineEdit *>(i.value()+"lB");
        QLineEdit *uBound = ui->tabVar->findChild<QLineEdit *>(i.value()+"uB");

        qDebug() << i.key() << " : " << i.value()
                 << " lb:" << lBound->text().toDouble()
                 << " ub:" << uBound->text().toDouble();

        emit varInterval(i.key(),i.value(),lBound->text().toDouble(),
                         uBound->text().toDouble());
    }
}
