#include "graphicsviewobject.h"

GraphicsViewObject::GraphicsViewObject(QObject *parent, GraphicsSceneObject *sceneObject)
    : QObject{parent}
    , graphicsSceneObject_(sceneObject)
    , graphicsView_(nullptr)
{
    initialization();
}

void GraphicsViewObject::setGraphicsSceneObject(GraphicsSceneObject *sceneObject)
{
    graphicsSceneObject_ = sceneObject;
}

QGraphicsView *GraphicsViewObject::getGraphicsView(void)
{
    return graphicsView_;
}

void GraphicsViewObject::initialization(void)
{
    graphicsView_ = new QGraphicsView();

    if (graphicsSceneObject_) {
        graphicsView_->setScene(graphicsSceneObject_->getGraphicsScene());
    }
}
