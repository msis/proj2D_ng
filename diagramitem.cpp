/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>

#include "diagramitem.h"
#include "arrow.h"

//! [0]
DiagramItem::DiagramItem(DiagramType diagramType, QMenu *contextMenu,
                         QGraphicsItem *parent, QGraphicsScene *scene)
    : QGraphicsPolygonItem(parent, scene)
{
    myDiagramType = diagramType;
    myContextMenu = contextMenu;
    myGText = new QGraphicsSimpleTextItem(this,scene);

    QPainterPath path;
    switch (myDiagramType) {
    case StartEnd:
        path.moveTo(200, 50);
        path.arcTo(150, 0, 50, 50, 0, 90);
        path.arcTo(50, 0, 50, 50, 90, 90);
        path.arcTo(50, 50, 50, 50, 180, 90);
        path.arcTo(150, 50, 50, 50, 270, 90);
        path.lineTo(200, 25);
        myPolygon = path.toFillPolygon();
        myText = "StartEnd";
        break;
    case Conditional:
        myPolygon << QPointF(-50, 0) << QPointF(0, 50)
                  << QPointF(50, 0) << QPointF(0, -50)
                  << QPointF(-50, 0);
        myText = "Conditional";
        break;
    case Step:
        myPolygon << QPointF(-50, -50) << QPointF(50, -50)
                  << QPointF(50, 50) << QPointF(-50, 50)
                  << QPointF(-50, -50);
        myText = "Step";
        break;
    case Compo:
        myPolygon << QPointF(-50, 0) << QPointF(0, 50)
                  << QPointF(50, 0) << QPointF(0, -50)
                  << QPointF(-50, 0);
        myText = /*"Composition " + */QString::fromUtf8("  \u2229");
        myGText->setScale(3);
        break;
    case Union:
        myPolygon << QPointF(-50, 0) << QPointF(0, 50)
                  << QPointF(50, 0) << QPointF(0, -50)
                  << QPointF(-50, 0);
        myText = /*"Union " +*/QString::fromUtf8("  \u222A");
        myGText->setScale(3);
        break;
    case Constraint:
        myPolygon << QPointF(-50, -50) << QPointF(50, -50)
                  << QPointF(50, 50) << QPointF(-50, 50)
                  << QPointF(-50, -50);
        myText = "Constraint";
        break;
    case Io:
        myPolygon << QPointF(-60, -40) << QPointF(-35, 40)
                  << QPointF(60, 40) << QPointF(35, -40)
                  << QPointF(-60, -40);
        myText = "Input/Output";
        break;
    default:
        myPolygon << QPointF(-60, -40) << QPointF(-35, 40)
                  << QPointF(60, 40) << QPointF(35, -40)
                  << QPointF(-60, -40);
        myText = "Default";
        break;
    }
    setPolygon(myPolygon);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    myGText->setText(myText);

    myGText->setPos(this->boundingRect().topLeft());

    ub = 0;
    lb = 0;
}
//! [0]

//! [1]
void DiagramItem::removeArrow(Arrow *arrow)
{
    int index = arrows.indexOf(arrow);

    if (index != -1)
        arrows.removeAt(index);
}
//! [1]

//! [2]
void DiagramItem::removeArrows()
{
    foreach (Arrow *arrow, arrows) {
        arrow->startItem()->removeArrow(arrow);
        arrow->endItem()->removeArrow(arrow);
        scene()->removeItem(arrow);
        delete arrow;
    }
}
//! [2]

//! [3]
void DiagramItem::addArrow(Arrow *arrow)
{
    arrows.append(arrow);
}
//! [3]

//! [4]
QPixmap DiagramItem::image() const
{
    QPixmap pixmap(250, 250);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(125, 125);
    painter.drawPolyline(myPolygon);

    return pixmap;
}
//! [4]

void DiagramItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if ((myDiagramType == Constraint) || (myDiagramType == Io))
    {
        itemParametersDialog* ipd = new itemParametersDialog(textParameters,&lb,&ub);
        ipd->show();
    }
}

QString DiagramItem::parameters()
{
    return textParameters;
}



//! [5]
void DiagramItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    myContextMenu->exec(event->screenPos());
}
//! [5]

//! [6]
QVariant DiagramItem::itemChange(GraphicsItemChange change,
                                 const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange) {
        foreach (Arrow *arrow, arrows) {
            arrow->updatePosition();
        }
    }

    return value;
}
//! [6]




