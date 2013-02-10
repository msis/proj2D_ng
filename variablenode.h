#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "expnode.h"

class variableNode : public expNode
{
    Q_OBJECT
public:
    explicit variableNode(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // VARIABLENODE_H
