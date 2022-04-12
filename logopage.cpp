#include <QtMath>
#include "logopage.h"


LogoPage::LogoPage(QWidget *parent):
    QWidget(parent),
    m_totemWidget_(nullptr),
    m_animateActiveButton_(nullptr)
{
    this->setGeometry(0, 0, 1800, 900);

    m_totemWidget_ = new TotemAnimatingWidget(this);
    m_totemWidget_->setGeometry(388, 20, 1024, 768);
    m_totemWidget_->showWidget();

    m_animateActiveButton_ = new QPushButton(this);
    m_animateActiveButton_->setGeometry(800, 800, 200, 80);

    connect(m_animateActiveButton_, SIGNAL(clicked()), m_totemWidget_, SLOT(startGenerating()));

}


LogoPage::~LogoPage()
{
    if(m_totemWidget_ != nullptr)
    {
        delete m_totemWidget_;
        m_totemWidget_ = nullptr;
    }

    if(m_animateActiveButton_ != nullptr)
    {
        delete m_animateActiveButton_;
        m_animateActiveButton_ = nullptr;
    }
}


void LogoPage::showWidget(void)
{
    this->show();
}

















