#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QtMath>
#include <QThread>
#include "selfgeneratebranch.h"

SelfGenerateBranch::SelfGenerateBranch(QObject * parent):
    QObject(parent),
    m_linePosStart_(),
    m_linePosEnd_(),
    m_graphicsLineItem_(nullptr),
    m_singleLineDuration_(0),
    m_baseAngle_(0),
    m_angleMinus_(0),
    m_anglePlus_(0),
    m_length_(40),
    m_generationCount_(0),
    m_selfGenerateAnimation_(nullptr),
    m_branchesScene_(nullptr),
    m_singleBranchList_()
{
    /* Each branch shall have its own Animation object */
    /* Each Animation object means one independent Animation generation */
    m_selfGenerateAnimation_ = new QPropertyAnimation(this);
    connect(m_selfGenerateAnimation_, SIGNAL(finished()), this, SLOT(singleenerationStep()));

    m_graphicsLineItem_ = new QGraphicsLineItem(0, 0, 0, 0);
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


void SelfGenerateBranch::setAngleParameters(int baseAngle, int minusAngle, int plusAngle)
{
    m_baseAngle_ = baseAngle % 360;
    m_angleMinus_ = (baseAngle + minusAngle) % 360;
    m_anglePlus_ = (baseAngle + plusAngle) % 360;
}


void SelfGenerateBranch::setLength(double length)
{
    m_length_ = length;
}


void SelfGenerateBranch::setGeneratingCount(int count)
{
    m_generationCount_ = count;
    m_currentGeneration_ = 0;
}


void SelfGenerateBranch::setGraphicScene(QGraphicsScene * branchScene)
{
    m_branchesScene_ = branchScene;
}


double SelfGenerateBranch::getGenerationProcess(void)
{
    float currentProcess = 0.0;

    // Here is the int devide int, the result is int
    // But, both value shall not be the float or double
    // improve the algorithm, but not simply change from int to the double/float
    currentProcess = 1.0 - static_cast<float>(m_currentGeneration_) / m_generationCount_;

    return currentProcess;
}


void SelfGenerateBranch::singleenerationStep(void)
{
    if (m_generationCount_ > m_currentGeneration_)
    {
        generatingBranches();
    }
}


// Add "connect" function here, to connect leaf generation.
void SelfGenerateBranch::generatingBranches(void)
{
    SingleSimpleBranch * singleTemp = new SingleSimpleBranch(this);

    int angleMinusTemp = m_baseAngle_ + m_angleMinus_;
    int anglePlusTemp = m_baseAngle_ + m_anglePlus_;

    singleTemp->setAngleParameters(angleMinusTemp, anglePlusTemp);
    int selectedAngleTemp = singleTemp->getSelectedAngle();

    singleTemp->setLength(m_length_);
    singleTemp->startLineGenerating(m_linePosStart_);
    m_singleBranchList_.append(singleTemp);

    m_branchesScene_->addItem(singleTemp->getGraphicsItem());

    m_linePosStart_ = singleTemp->getLinePosEnd();

    m_currentGeneration_++;

    m_selfGenerateAnimation_->setTargetObject(singleTemp);
    m_selfGenerateAnimation_->setPropertyName(QByteArray("m_linePosEnd_"));
    m_selfGenerateAnimation_->setStartValue(singleTemp->getLinePosStart());
    m_selfGenerateAnimation_->setEndValue(singleTemp->getLinePosEnd());
    m_selfGenerateAnimation_->start();

    /* if generated new leaf then-> */
    //generateLeafBranch(m_linePosEnd_, selectedAngleTemp, this);

}


void SelfGenerateBranch::generateLeafBranch(QPointF startPos,  int parentSelectedAngle,
                                            SelfGenerateBranch * parentBranch)
{
    // This branch base Angle is depended on its parent "Single Branch selected Angle"
    // So that the parameter is from the SingleGenerateBranch
    // Instead of the SelfGenerateBranch

    SelfGenerateBranch * leafBranch = new SelfGenerateBranch();
    qDebug() << "here is the parentSelectedAngle : " << parentSelectedAngle << Qt::endl;
    qDebug() << "here is the m_angleMinus_ : " << m_angleMinus_ << Qt::endl;
    qDebug() << "here is the m_anglePlus_ : " << m_anglePlus_ << Qt::endl;
    leafBranch->setAngleParameters(parentSelectedAngle, m_angleMinus_, m_anglePlus_);

    int leafGenerationCount = m_generationCount_ - m_currentGeneration_;
    leafBranch->setGeneratingCount(leafGenerationCount);
    leafBranch->setGraphicScene(m_branchesScene_);
    leafBranch->setLinePosStart(startPos);

    double leafLength = m_length_ * getGenerationProcess();
    qDebug() << "The Process is here: " << getGenerationProcess() << Qt::endl;

    qDebug() << "The Length is here: " << leafLength << Qt::endl;
    leafBranch->setLength(leafLength);

    emit signalNewBranch(leafBranch);


}
























