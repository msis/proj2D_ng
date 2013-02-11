#ifndef IBEXUSER_H
#define IBEXUSER_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QDateTime>

#include <QDebug>

#include "ibex.h"

#include <iostream>


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
    void setVarInterval(int,QString,double,double);
    void setStartBox();

protected slots:


private:
    QFile f;
    QString filename;
    ibex::Function *function;
    ibex::IntervalVector *startBox;
    ibex::IntervalMatrix *outBox;
    QList<ibex::Interval> intervalList;

    QMap<int,QString> varNameMap;
    QMap<int,double> varLBMap;
    QMap<int,double> varUBMap;

    void processBox();

    
};

#endif // IBEXUSER_H
