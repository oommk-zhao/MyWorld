#include <QRandomGenerator>
#include <QtMath>
#include "selfgenerateline.h"

SelfGenerateLine::SelfGenerateLine(QObject * parent):
    QObject(parent),
    m_linePosStart_(),
    m_linePosEnd_(),
    m_graphicsLineItem_(nullptr),
    m_singleLineDuration_(0),
    m_endDirectionDelta_(0),
    m_endLengthDelta_(40)
{
    m_graphicsLineItem_ = new QGraphicsLineItem(0, 0, 0, 0);
    setSingleAnimationDuration(500);
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
    setLinePosStart(QPointF(x1, y1));
    setLinePosEnd(QPointF(x2, y2));

    refreshGraphicsLinePosition();
}


void SelfGenerateLine::startLineGenerating(QPointF startPos)
{
    setLinePosStart(startPos);
    generateEndPos();
}


void SelfGenerateLine::setSingleAnimationDuration(int durationTime)
{
    m_singleLineDuration_ = durationTime;
}


void SelfGenerateLine::generateEndPos(void)
{
    //calculate the Delta(direction and length) -> have the end position
    double targetEndPosX = m_linePosStart_.x();
    double targetEndPosY = m_linePosStart_.y();

    int angel = 0;
    angel = QRandomGenerator::global()->bounded(-45, 45);

    targetEndPosX = generateEndPosX(angel);
    targetEndPosY = generateEndPosY(angel);

    setLinePosEnd(QPointF(targetEndPosX, targetEndPosY));

}


double SelfGenerateLine::generateEndPosX(int angel)
{
    double targetEndPosX = m_linePosStart_.x();

    double targetDelta = m_endLengthDelta_ * qSin(qDegreesToRadians(angel));

    targetEndPosX += targetDelta;

    qDebug() << "random target X :  " << targetEndPosX << "  random angel : " << angel << Qt::endl;

    return targetEndPosX;
}


double SelfGenerateLine::generateEndPosY(int angel)
{
    double targetEndPosY = m_linePosStart_.y();

    double targetDelta = m_endLengthDelta_ * qCos(qDegreesToRadians(angel)) * -1;

    targetEndPosY += targetDelta;

    qDebug() << "random target Y :  " << targetEndPosY << "  random angel : " << angel << Qt::endl;


    return targetEndPosY;
}

























