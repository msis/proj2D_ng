#include "expnode.h"

expNode::expNode(QObject *parent) :
    QObject(parent)
{
}

expNode *expNode::right()
{
    return nRight;
}

expNode *expNode::left()
{
    return nLeft;
}

void expNode::setRight(expNode *r)
{
    this->nRight = r;
}

void expNode::setLeft(expNode *l)
{
    this->nLeft = l;
}

