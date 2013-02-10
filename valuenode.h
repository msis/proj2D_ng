#ifndef VALUENODE_H
#define VALUENODE_H

#include "expnode.h"

class valueNode : public expNode
{
    Q_OBJECT
public:
    explicit valueNode(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // VALUENODE_H
