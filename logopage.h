#ifndef LOGOPAGE_H
#define LOGOPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QPointF>
#include <QList>
#include "selfgeneratebranch.h"

// Responsibility
// 1. decide whether to generate new branch
//    set the parameters "length", "angel", "count" for the new branch
// 2. execute the main loop of the generating
//    and each branch will end itself when the "count" is at the end
// 3. for each turn of loop, get the generated graphic item
//    and forward it to the Scene

class LogoPage : public QWidget
{
    Q_OBJECT

public:
    LogoPage(QWidget *parent = nullptr);
    virtual ~LogoPage();

    void showWidget(void);

private slots:

    void generateTotem(void);
    void generatingLoop(QPointF startPos);

private:

    QGraphicsView * m_totemGraphicsView_;
    QGraphicsScene * m_totemGraphicsScene_;

    QPushButton * m_animateActiveButton_;

    int m_generatingCount_;

    int m_startAngel_;
    int m_endAngel_;
    int m_singleLineLength_;

    QList<SelfGenerateBranch*> m_selfGenrateBranches_;

};
#endif // LOGOPAGE_H
