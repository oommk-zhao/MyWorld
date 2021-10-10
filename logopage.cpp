#include <QtMath>
#include "logopage.h"


LogoPage::LogoPage(QWidget *parent):
    QWidget(parent),
    m_totemGraphicsView_(nullptr),
    m_totemGraphicsScene_(nullptr),
    m_animateActiveButton_(nullptr),
    m_generatingCount_(0),
    m_startAngel_(-45),
    m_endAngel_(45),
    m_singleLineLength_(40),
    m_selfGenrateBranches_()
{
    this->setGeometry(0, 0, 1800, 900);

    m_totemGraphicsScene_ = new QGraphicsScene(this);
    m_totemGraphicsScene_->setSceneRect(-900, -450, 1800, 900);

    m_totemGraphicsView_ = new QGraphicsView(this);
    m_totemGraphicsView_->setGeometry(0, 0, 1800, 900);
    m_totemGraphicsView_->setScene(m_totemGraphicsScene_);
/*
    animateActiveButton_ = new QPushButton(this);
    animateActiveButton_->setGeometry(300, 480, 200, 80);
    animateActiveButton_->setText("Active Line Animatiion");
*/

    m_startAngel_ = -45;
    m_endAngel_ = 45;

    m_totemGraphicsView_->show();

    m_generatingCount_ = 20;

    generateTotem();
}


LogoPage::~LogoPage()
{
}


void LogoPage::showWidget(void)
{
    this->show();
}


void LogoPage::generateTotem(void)
{
    SelfGenerateBranch* basicBranch = new SelfGenerateBranch();
    basicBranch->setLinePosStart(QPointF(-200, 400));
    basicBranch->setLinePosEnd(QPointF(200, 400));
    basicBranch->setAngelParameters(m_startAngel_, m_endAngel_);
    basicBranch->setLength(m_singleLineLength_);

    m_totemGraphicsScene_->addItem(basicBranch->getGraphicsItem());

    generatingLoop(QPointF(0,400));

}


void LogoPage::generatingLoop(QPointF startPos)
{
    if(m_generatingCount_ < 1)
    {
        return;
    }

    SelfGenerateBranch * loopLine = new SelfGenerateBranch();
    loopLine->setAngelParameters(m_startAngel_, m_endAngel_);
    loopLine->setLength(m_singleLineLength_);
    loopLine->startLineGenerating(startPos);
    m_totemGraphicsScene_->addItem(loopLine->getGraphicsItem());
    --m_generatingCount_;

    generatingLoop(loopLine->getLinePosEnd());
}
























