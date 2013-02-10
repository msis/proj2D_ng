#ifndef EXPNODE_H
#define EXPNODE_H

#include <QObject>
#include "ibex.h"

//using namespace ibex;

class expNode : public QObject
{
    Q_OBJECT
public:
    explicit expNode(QObject *parent = 0);

    expNode* right();
    expNode* left();

    virtual ibex::IntervalVector value() = 0;

signals:

public slots:
    void setRight(expNode*);
    void setLeft(expNode*);

private:
    expNode *nRight;
    expNode *nLeft;

};

#endif // EXPNODE_H
