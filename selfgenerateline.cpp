#include "selfgenerateline.h"

SelfGenerateLine::SelfGenerateLine(QObject * parent):
    QObject(parent),
    m_linePosStart_(),
    m_linePosEnd_(),
    m_graphicsLineItem_(nullptr)
{
    m_graphicsLineItem_ = new QGraphicsLineItem(0, 0, 0, 0);
}


SelfGenerateLine::~SelfGenerateLine()
{

}


void SelfGenerateLine::setGraphicsParent(QGraphicsItem * graphicsParent)
{
    this->m_graphicsLineItem_->setParentItem(graphicsParent);

    return;
}


QPointF SelfGenerateLine::getLinePosStart(void)
{
    return m_linePosStart_;
}


void SelfGenerateLine::setLinePosStart(QPointF linePosStart)
{
    m_linePosStart_ = linePosStart;
    refreshGraphicsLinePosition();
}


QPointF SelfGenerateLine::getLinePosEnd(void)
{
    return m_linePosEnd_;
}


void SelfGenerateLine::setLinePosEnd(QPointF linePosEnd)
{
    m_linePosEnd_ = linePosEnd;
    refreshGraphicsLinePosition();
}


void SelfGenerateLine::refreshGraphicsLinePosition(void)
{
    m_graphicsLineItem_->setLine(m_linePosStart_.x(), m_linePosStart_.y(), m_linePosEnd_.x() ,m_linePosEnd_.y());
}


QGraphicsLineItem * SelfGenerateLine::getGraphicsItem(void)
{
    return m_graphicsLineItem_;
}


void SelfGenerateLine::setGraphicsLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    this->m_graphicsLineItem_->setLine(x1,y1, x2, y2);
}



