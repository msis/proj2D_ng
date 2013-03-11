#ifndef ITEMPARAMETERSDIALOG_H
#define ITEMPARAMETERSDIALOG_H

#include <QDialog>

//#include "diagramitem.h"

namespace Ui {
class itemParametersDialog;
}

//class DiagramItem;

class itemParametersDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit itemParametersDialog(QString& parameters,QWidget *parent = 0);
    ~itemParametersDialog();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::itemParametersDialog *ui;
    QString* param;
};

#endif // ITEMPARAMETERSDIALOG_H
