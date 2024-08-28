#ifndef BASEGRAPHICCOMPONENT_H
#define BASEGRAPHICCOMPONENT_H

// The basic component of the all kinds of Graphic Components

#include <QGraphicsObject>

class BaseGraphicComponent
{

public:
    BaseGraphicComponent();
    virtual ~BaseGraphicComponent();

    virtual void updateGraphics();

    QGraphicsObject *getGraphicsObject(void);

    // We put graphics object here first, in the base class.
protected:
    QGraphicsObject *graphicsObject_;
};

#endif // BASEGRAPHICCOMPONENT_H
