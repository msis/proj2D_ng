#ifndef ITEMPARAMETERSDIALOG_H
#define ITEMPARAMETERSDIALOG_H

#include <QDialog>
#include <QMessageBox>

//#include "diagramitem.h"

namespace Ui {
class itemParametersDialog;
}

//class DiagramItem;

class itemParametersDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit itemParametersDialog(QString& parameters,double* ilb,double* iub,QWidget *parent = 0);
    ~itemParametersDialog();
    
private slots:
    void on_buttonBox_accepted();

    void on_doubleSpinBoxLB_valueChanged(double arg1);

    void on_doubleSpinBoxUB_valueChanged(double arg1);

private:
    Ui::itemParametersDialog *ui;
    QString* param;
    double* ub;
    double* lb;
};

#endif // ITEMPARAMETERSDIALOG_H
