#include <QRandomGenerator>
#include <QtMath>
#include "selfgeneratebranch.h"

SelfGenerateBranch::SelfGenerateBranch(QObject * parent):
    QObject(parent),
    m_linePosStart_(),
    m_linePosEnd_(),
    m_graphicsLineItem_(nullptr),
    m_singleLineDuration_(0),
    m_angelBegin_(0),
    m_angelEnd_(0),
    m_length_(40)
{
    m_graphicsLineItem_ = new QGraphicsLineItem(0, 0, 0, 0);
    setSingleAnimationDuration(500);
}


SelfGenerateBranch::~SelfGenerateBranch()
{

}


void SelfGenerateBranch::setGraphicsParent(QGraphicsItem * graphicsParent)
{
    this->m_graphicsLineItem_->setParentItem(graphicsParent);

    return;
}


QPointF SelfGenerateBranch::getLinePosStart(void)
{
    return m_linePosStart_;
}


void SelfGenerateBranch::setLinePosStart(QPointF linePosStart)
{
    m_linePosStart_ = linePosStart;
    refreshGraphicsLinePosition();
}


QPointF SelfGenerateBranch::getLinePosEnd(void)
{
    return m_linePosEnd_;
}


void SelfGenerateBranch::setLinePosEnd(QPointF linePosEnd)
{
    m_linePosEnd_ = linePosEnd;
    refreshGraphicsLinePosition();
}


void SelfGenerateBranch::refreshGraphicsLinePosition(void)
{
    m_graphicsLineItem_->setLine(m_linePosStart_.x(), m_linePosStart_.y(), m_linePosEnd_.x() ,m_linePosEnd_.y());
}


QGraphicsLineItem * SelfGenerateBranch::getGraphicsItem(void)
{
    return m_graphicsLineItem_;
}


void SelfGenerateBranch::setGraphicsLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    setLinePosStart(QPointF(x1, y1));
    setLinePosEnd(QPointF(x2, y2));

    refreshGraphicsLinePosition();
}


void SelfGenerateBranch::startLineGenerating(QPointF startPos)
{
    setLinePosStart(startPos);
    generateEndPos();
}


void SelfGenerateBranch::setSingleAnimationDuration(int durationTime)
{
    m_singleLineDuration_ = durationTime;
}


void SelfGenerateBranch::setAngelParameters(int startAngel, int endAngel)
{
    m_angelBegin_ = startAngel;
    m_angelEnd_ = endAngel;
}


void SelfGenerateBranch::setLength(double length)
{
    m_length_ = length;
}


void SelfGenerateBranch::generateEndPos(void)
{
    //calculate the Delta(direction and length) -> have the end position
    double targetEndPosX = m_linePosStart_.x();
    double targetEndPosY = m_linePosStart_.y();

    int angel = 0;
    angel = QRandomGenerator::global()->bounded(m_angelBegin_, m_angelEnd_);

    targetEndPosX = generateEndPosX(angel);
    targetEndPosY = generateEndPosY(angel);

    setLinePosEnd(QPointF(targetEndPosX, targetEndPosY));

}


double SelfGenerateBranch::generateEndPosX(int angel)
{
    double targetEndPosX = m_linePosStart_.x();

    double targetDelta = m_length_ * qSin(qDegreesToRadians(angel));

    targetEndPosX += targetDelta;

    qDebug() << "random target X :  " << targetEndPosX << "  random angel : " << angel << Qt::endl;

    return targetEndPosX;
}


double SelfGenerateBranch::generateEndPosY(int angel)
{
    double targetEndPosY = m_linePosStart_.y();

    double targetDelta = m_length_ * qCos(qDegreesToRadians(angel)) * -1;

    targetEndPosY += targetDelta;

    qDebug() << "random target Y :  " << targetEndPosY << "  random angel : " << angel << Qt::endl;


    return targetEndPosY;
}

























