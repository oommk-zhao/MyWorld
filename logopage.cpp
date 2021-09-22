#include <QtMath>
#include "logopage.h"


LogoPage::LogoPage(QWidget *parent):
    QWidget(parent),
    totemGraphicsView_(nullptr),
    totemGraphicsScene_(nullptr),
    animateActiveButton_(nullptr),
    generatingCount_(0)
{
    this->setGeometry(0, 0, 1800, 900);

    totemGraphicsScene_ = new QGraphicsScene(this);
    totemGraphicsScene_->setSceneRect(-900, -450, 1800, 900);

    totemGraphicsView_ = new QGraphicsView(this);
    totemGraphicsView_->setGeometry(0, 0, 1800, 900);
    totemGraphicsView_->setScene(totemGraphicsScene_);
/*
    animateActiveButton_ = new QPushButton(this);
    animateActiveButton_->setGeometry(300, 480, 200, 80);
    animateActiveButton_->setText("Active Line Animatiion");
*/

    totemGraphicsView_->show();

    generatingCount_ = 20;

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
    SelfGenerateLine* basicLine = new SelfGenerateLine();
    basicLine->setLinePosStart(QPointF(-200, 400));
    basicLine->setLinePosEnd(QPointF(200, 400));
    totemGraphicsScene_->addItem(basicLine->getGraphicsItem());

    generatingLoop(QPointF(0,400));

}


void LogoPage::generatingLoop(QPointF startPos)
{
    if(generatingCount_ < 1)
    {
        return;
    }

    SelfGenerateLine * testLine_ = new SelfGenerateLine();
    testLine_->startLineGenerating(startPos);
    totemGraphicsScene_->addItem(testLine_->getGraphicsItem());
    --generatingCount_;

    generatingLoop(testLine_->getLinePosEnd());
}
























