#include "selfgenerateline.h"

SelfGenerateLine::SelfGenerateLine(QObject * parent):
    QObject(parent),
    m_linePosX_(),
    m_linePosY_(),
    m_graphicsLineItem_(nullptr)
{
    m_graphicsLineItem_ = new QGraphicsLineItem(30, 30, 220, 200);
}


SelfGenerateLine::~SelfGenerateLine()
{

}


void SelfGenerateLine::setGraphicsParent(QGraphicsItem * graphicsParent)
{
    this->m_graphicsLineItem_->setParentItem(graphicsParent);

    return;
}


QPointF SelfGenerateLine::getLinePosY(void)
{
    return m_linePosY_;
}


void SelfGenerateLine::setLinePosY(QPointF linePosY)
{
    m_linePosY_ = linePosY;
}


QPointF SelfGenerateLine::getLinePosX(void)
{
    m_graphicsLineItem_->setLine(300,300,600,600);

    return m_linePosX_;
}


void SelfGenerateLine::setLinePosX(QPointF linePosX)
{
    m_linePosX_ = linePosX;
}


QGraphicsLineItem * SelfGenerateLine::getGraphicsItem(void)
{
    return m_graphicsLineItem_;
}
