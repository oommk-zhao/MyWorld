#ifndef LOGOPAGE_H
#define LOGOPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QPointF>
#include <QList>
#include "totemanimatingwidget.h"



class LogoPage : public QWidget
{
    Q_OBJECT

public:
    LogoPage(QWidget *parent = nullptr);
    virtual ~LogoPage();

    void showWidget(void);

private:

    TotemAnimatingWidget * m_totemWidget_;
    QPushButton * m_animateActiveButton_;

};
#endif // LOGOPAGE_H
