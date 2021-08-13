#include "logopage.h"

LogoPage::LogoPage(QWidget *parent):
    QWidget(parent),
    totemGraphicsView_(nullptr),
    totemGraphicsScene_(nullptr),
    testLine_(nullptr),
    animateActiveButton_(nullptr)
{
    this->setGeometry(0, 0, 800, 600);

    totemGraphicsScene_ = new QGraphicsScene(this);
    totemGraphicsScene_->setSceneRect(200, 150, 400, 300);

    totemGraphicsView_ = new QGraphicsView(this);
    totemGraphicsView_->setGeometry(200, 150, 400, 300);
    totemGraphicsView_->setScene(totemGraphicsScene_);

    testLine_ = new SelfGenerateLine(this);
    totemGraphicsScene_->addItem(testLine_->getGraphicsItem());
    testLine_->setGraphicsLine(250,250,400,400);

    animateActiveButton_ = new QPushButton(this);
    animateActiveButton_->setGeometry(300, 480, 200, 80);
    animateActiveButton_->setText("Active Line Animatiion");

    totemGraphicsView_->show();
}


LogoPage::~LogoPage()
{
}


void LogoPage::showWidget(void)
{
    this->show();
}
