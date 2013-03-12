#include "itemparametersdialog.h"
#include "ui_itemparametersdialog.h"

itemParametersDialog::itemParametersDialog(QString& parameters, double* ilb, double* iub, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::itemParametersDialog), param(&parameters),
    lb(ilb), ub(iub)
{
    ui->setupUi(this);

    ui->lineEdit->setText(*param);

    ui->doubleSpinBoxLB->setValue(*lb);
    ui->doubleSpinBoxUB->setValue(*ub);
}

itemParametersDialog::~itemParametersDialog()
{
    delete ui;
}

void itemParametersDialog::on_buttonBox_accepted()
{
    *param = ui->lineEdit->text();
    *lb = ui->doubleSpinBoxLB->value();
    *ub = ui->doubleSpinBoxUB->value();
}





void itemParametersDialog::on_doubleSpinBoxLB_valueChanged(double arg1)
{
    if (arg1 > ui->doubleSpinBoxUB->value())
    {

    }
}

void itemParametersDialog::on_doubleSpinBoxUB_valueChanged(double arg1)
{
    if (arg1 < ui->doubleSpinBoxLB->value())
    {

    }

}
