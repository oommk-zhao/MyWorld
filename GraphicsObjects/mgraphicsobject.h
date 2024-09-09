#ifndef MGRAPHICSOBJECT_H
#define MGRAPHICSOBJECT_H

// The basic component of the all kinds of Graphic Components

#include <QGraphicsObject>

class MGraphicsObject : QGraphicsObject
{
    Q_OBJECT

public:
    MGraphicsObject();
    virtual ~MGraphicsObject();

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) override;
    // We put graphics object here first, in the base class.
};

#endif // GRAPHICSOBJECT_H
