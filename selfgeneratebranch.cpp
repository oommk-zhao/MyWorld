#include <QRandomGenerator>
#include <QGraphicsScene>
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
    m_length_(40),
    m_generatingCount_(0),
    m_selfGenerateAnimation_(nullptr),
    m_branchesScene_(nullptr),
    m_singleBranchList_()
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
    generatingBranches();
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


void SelfGenerateBranch::setGeneratingCount(int count)
{
    m_generatingCount_ = count;
}


void SelfGenerateBranch::setGraphicScene(QGraphicsScene * branchScene)
{
    m_branchesScene_ = branchScene;
}


void SelfGenerateBranch::setAnimationObj(QPropertyAnimation * animationObj)
{
    m_selfGenerateAnimation_ = animationObj;
}


void SelfGenerateBranch::generatingBranches(void)
{
    QPointF startPosTemp = m_linePosStart_;

    m_generatingCount_ = 2;

    while (m_generatingCount_ > 0)
    {
        SingleSimpleBranch * singleTemp = new SingleSimpleBranch(this);
        singleTemp->setAngelParameters(m_angelBegin_, m_angelEnd_);
        singleTemp->setLength(m_length_);
        singleTemp->startLineGenerating(startPosTemp);

        m_branchesScene_->addItem(singleTemp->getGraphicsItem());

        m_selfGenerateAnimation_->setTargetObject(singleTemp);
        m_selfGenerateAnimation_->setPropertyName(QByteArray("m_linePosEnd_"));
        m_selfGenerateAnimation_->setDuration(5000);
        m_selfGenerateAnimation_->setStartValue(startPosTemp);
        m_selfGenerateAnimation_->setEndValue(singleTemp->getLinePosEnd());
        m_selfGenerateAnimation_->start();

        startPosTemp = singleTemp->getLinePosEnd();



        m_generatingCount_--;
    }
}
























