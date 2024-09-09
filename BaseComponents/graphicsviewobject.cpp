#include "graphicsviewobject.h"

GraphicsViewObject::GraphicsViewObject(QObject *parent)
    : QObject{parent}
    , graphicsView_(nullptr)
{

}

QGraphicsView *GraphicsViewObject::getGraphicsView(void)
{
    return graphicsView_;
}
