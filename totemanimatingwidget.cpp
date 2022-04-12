#include <QPointF>
#include <QPalette>
#include <QColor>
#include "totemanimatingwidget.h"


TotemAnimatingWidget::TotemAnimatingWidget(QWidget *parent):
    QWidget(parent),
    m_generatingCount_(0),
    m_startAngel_(0),
    m_endAngel_(0),
    m_singleLineLength_(0),
    m_baseBranch_(nullptr),
    m_totemGraphicsScene_(nullptr),
    m_totemGraphicsView_(nullptr),
    m_selfGenerateAnimation_(nullptr),
    m_selfGenrateBranches_()
{
    initialization();
}


TotemAnimatingWidget::~TotemAnimatingWidget()
{
    if(m_baseBranch_ != nullptr)
    {
        delete m_baseBranch_;
        m_baseBranch_ = nullptr;
    }

    if(m_totemGraphicsScene_ != nullptr)
    {
        delete m_totemGraphicsScene_;
        m_totemGraphicsScene_ = nullptr;
    }

    if(m_totemGraphicsView_ != nullptr)
    {
        delete m_totemGraphicsView_;
        m_totemGraphicsView_ = nullptr;
    }

    if(m_selfGenerateAnimation_ != nullptr)
    {
        delete m_selfGenerateAnimation_;
        m_selfGenerateAnimation_ = nullptr;
    }

    for (SelfGenerateBranch * branchIt : m_selfGenrateBranches_)
    {
        if(branchIt != nullptr)
        {
            delete branchIt;
            branchIt = nullptr;
        }
    }

    m_selfGenrateBranches_.clear();
}


void TotemAnimatingWidget::showWidget(void)
{
    this->show();
}


void TotemAnimatingWidget::initialization(void)
{
    m_generatingCount_ = 0;
    m_startAngel_ = 0;
    m_endAngel_ = 0;
    m_singleLineLength_ = 0;

    this->setAutoFillBackground(true);
    QPalette currentPalette = this->palette();
    currentPalette.setColor(QPalette::Window, Qt::lightGray);
    this->setPalette(currentPalette);

    m_totemGraphicsScene_ = new QGraphicsScene(this);

    m_totemGraphicsScene_->setSceneRect(QRect(0, 0, 1024, 768));

    m_totemGraphicsView_ = new QGraphicsView(this);
    m_totemGraphicsView_->setGeometry(0, 0, 1024, 768);
    m_totemGraphicsView_->setScene(m_totemGraphicsScene_);

    m_selfGenerateAnimation_ = new QPropertyAnimation(this);

    m_selfGenrateBranches_.clear();

    generateBaseView();
}


void TotemAnimatingWidget::startAnimation(void)
{
    QPointF startPos(512, 600);
    generateLoop(startPos);
}


void TotemAnimatingWidget::stopAnimation(void)
{

}


QPointF TotemAnimatingWidget::getMainBranchStartPos(void)
{

}


void TotemAnimatingWidget::setMainBranchStartPos(QPointF linePosStart)
{

}


void TotemAnimatingWidget::startGenerating(void)
{
    QPointF startPos(512, 600);
    generateLoop(startPos);
}

void TotemAnimatingWidget::generateBaseView(void)
{
    m_baseBranch_ = new SelfGenerateBranch(m_totemGraphicsScene_);
    m_baseBranch_->setLinePosStart(QPointF(112, 600));
    m_baseBranch_->setLinePosEnd(QPointF(912, 600));

    m_totemGraphicsScene_->addItem(m_baseBranch_->getGraphicsItem());
}


void TotemAnimatingWidget::generateLoop(QPointF startPos)
{
    SelfGenerateBranch * branchTemp = new SelfGenerateBranch();
    branchTemp->setAngelParameters(-20, 20);
    branchTemp->setLength(20);
    branchTemp->setGeneratingCount(20);
    branchTemp->setGraphicScene(m_totemGraphicsScene_);
    branchTemp->setAnimationObj(m_selfGenerateAnimation_);

    branchTemp->startLineGenerating(startPos);


}








