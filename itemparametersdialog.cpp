#include "itemparametersdialog.h"
#include "ui_itemparametersdialog.h"

itemParametersDialog::itemParametersDialog(QString& parameters, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::itemParametersDialog), param(&parameters)
{
    ui->setupUi(this);

    ui->plainTextEdit->setPlainText(*param);

}

itemParametersDialog::~itemParametersDialog()
{
    delete ui;
}

void itemParametersDialog::on_buttonBox_accepted()
{
    *param = ui->plainTextEdit->toPlainText();
}


