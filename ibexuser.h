#ifndef IBEXUSER_H
#define IBEXUSER_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QDateTime>

#include <QDebug>

#include "ibex.h"


class ibexUser : public QObject
{
    Q_OBJECT
public:
    explicit ibexUser(QObject *parent = 0);
    ~ibexUser();
    
signals:
    void newVariableFound(int,QString);
    
public slots:
    void setFilename(QString);
    void constraintsText(QString);
    void feedIbexWithFunction();

protected slots:


private:
    QFile f;
    QString filename;
    ibex::Function *function;


    
};

#endif // IBEXUSER_H
