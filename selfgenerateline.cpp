#include "selfgenerateline.h"

SelfGenerateLine::SelfGenerateLine(QObject * parent):
    QObject(parent),
    QGraphicsLineItem(nullptr)
{

}


SelfGenerateLine::~SelfGenerateLine()
{

}


void SelfGenerateLine::setGraphicsParent(QGraphicsItem * graphicsParent)
{
    this->setParentItem(graphicsParent);

    return;
}
