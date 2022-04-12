#ifndef SelfGenerateBranch_H
#define SelfGenerateBranch_H

#include <QDebug>
#include <QObject>
#include <QPointF>
#include <QList>
#include <QGraphicsLineItem>
#include <QPropertyAnimation>

#include "singlesimplebranch.h"

// Responsibility: Done

// this is the object of one entire whole branch.
// from the start point, to the end of the whole generation.
// BUT, only for the one line of generated branch.

// and this shall notify this parent to generate a new branch during the loop

// and return the end single branch/leaf, its graphics item

//-----------------------------
// the following are pending
// change this object to be a container
// to be the maintainer of the single simple branch list
// to return the generated looping graphics branch
// to do the loop
// to adjust the parameters of the looping

class SelfGenerateBranch : public QObject
{
    Q_OBJECT

public:
    SelfGenerateBranch(QObject * parent = nullptr);
    virtual ~SelfGenerateBranch();

    void setGraphicsParent(QGraphicsItem * graphicsParent = nullptr);

    QPointF getLinePosStart(void);
    void setLinePosStart(QPointF linePosStart);
    QPointF getLinePosEnd(void);
    void setLinePosEnd(QPointF linePosEnd);

    void refreshGraphicsLinePosition(void);

    QGraphicsLineItem * getGraphicsItem(void);

    void setGraphicsLine(qreal x1, qreal y1, qreal x2, qreal y2);

    void startLineGenerating(QPointF startPos);

    void setSingleAnimationDuration(int durationTime);

    void setAngelParameters(int startAngel, int endAngel);

    void setLength(double length);

    void setGeneratingCount(int count);

    void setGraphicScene(QGraphicsScene * branchScene);

    void setAnimationObj(QPropertyAnimation * animationObj);

private slots:

    void generatingBranches(void);

private:

    QPointF m_linePosStart_;
    QPointF m_linePosEnd_;
    QGraphicsLineItem * m_graphicsLineItem_;

    // unit = ms
    int m_singleLineDuration_;

    int m_angelBegin_;
    int m_angelEnd_;
    double m_length_;
    int m_generatingCount_;

    QPropertyAnimation * m_selfGenerateAnimation_;

    QGraphicsScene * m_branchesScene_;

    QList<SingleSimpleBranch *> m_singleBranchList_;

};

#endif // SelfGenerateBranch_H
