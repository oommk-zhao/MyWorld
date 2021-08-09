#include "selfgenerateline.h"

SelfGenerateLine::SelfGenerateLine(QObject * parent):
    QObject(parent),
    QGraphicsLineItem(nullptr),
    m_linePosY()
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


QPointF SelfGenerateLine::getLinePosY(void)
{
    return m_linePosY;
}


void SelfGenerateLine::setLinePosY(QPointF linePosY)
{
    m_linePosY = linePosY;
}
