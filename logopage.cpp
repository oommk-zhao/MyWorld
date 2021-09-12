#include "logopage.h"


LogoPage::LogoPage(QWidget *parent):
    QWidget(parent),
    totemGraphicsView_(nullptr),
    totemGraphicsScene_(nullptr),
    testLine_(nullptr),
    animateActiveButton_(nullptr),
    generatingCount_(0)
{
    this->setGeometry(0, 0, 800, 600);

    totemGraphicsScene_ = new QGraphicsScene(this);
    totemGraphicsScene_->setSceneRect(200, 150, 400, 300);

    totemGraphicsView_ = new QGraphicsView(this);
    totemGraphicsView_->setGeometry(200, 150, 400, 300);
    totemGraphicsView_->setScene(totemGraphicsScene_);

    testLine_ = new SelfGenerateLine();
    testLine_->setGraphicsLine(250,250,400,400);
    totemGraphicsScene_->addItem(testLine_->getGraphicsItem());


    animateActiveButton_ = new QPushButton(this);
    animateActiveButton_->setGeometry(300, 480, 200, 80);
    animateActiveButton_->setText("Active Line Animatiion");

    totemGraphicsView_->show();

    generatingCount_ = 20;
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
    generatingLoop(QPointF(0,0));

}


void LogoPage::generatingLoop(QPointF startPos)
{
    if(generatingCount_ < 1)
    {
        return;
    }

    testLine_ = new SelfGenerateLine();
    testLine_->startLineGenerating(startPos);
    totemGraphicsScene_->addItem(testLine_->getGraphicsItem());
    --generatingCount_;

    generatingLoop(testLine_->getLinePosEnd());
}
























