#ifndef TOTEMANIMATINGWIDGET_H
#define TOTEMANIMATINGWIDGET_H

#include <QGraphicsView>
#include <QDebug>
#include <QList>
#include <QPropertyAnimation>

#include "selfgeneratebranch.h"


// Responsibility (not very clear yet)

// 1. for each turn of loop, get the generated graphic item
//    and forward it to the Scene

// 2. decide whether to generate new branch
//    set the parameters "length", "angel", "count" for the new branch

// 3. execute the main loop of the generating
//    and each branch will end itself when the "count" is at the end


class TotemAnimatingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TotemAnimatingWidget(QWidget *parent = nullptr);
    virtual ~TotemAnimatingWidget();

    void showWidget(void);

    QPointF getMainBranchStartPos(void);
    void setMainBranchStartPos(QPointF linePosStart);

    void setGraphicsScene();



signals:

private:

    SelfGenerateBranch * m_selfGenerateBranch_;

    QGraphicsScene * m_totemGraphicsScene_;

    QPropertyAnimation * m_selfGenerateAnimation_;



};

#endif // TOTEMANIMATINGWIDGET_H
