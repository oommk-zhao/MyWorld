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

    void setAngleParameters(int baseAngle, int startAngle, int endAngle);

    void setLength(double length);

    void setGeneratingCount(int count);

    void setGraphicScene(QGraphicsScene * branchScene);

    // This return the current process of generation
    // the return is useful for when need calculation the value of parameter,
    // which will be passed to its leaves.
    // The return value is a double, tell the rest rate of the whole generation
    double getGenerationProcess(void);

signals:

    /* the life itself shall decide which direction for its own next generation! */
    /* at the mean time, the outside environment decide whether its generation grown. */
    /* the passing object is more like the seed */
    void signalNewBranch(SelfGenerateBranch *);

private slots:

    void singleenerationStep(void);

    void generatingBranches(void);

    /* Using parameter instead of Object here */
    /* To indicate the properites of next generation */
    void generateLeafBranch(QPointF startPos,  int parentSelectedAngle,
                            SelfGenerateBranch * parentBranch);

private:

    QPointF m_linePosStart_;
    QPointF m_linePosEnd_;
    QGraphicsLineItem * m_graphicsLineItem_;

    // unit = ms
    int m_singleLineDuration_;

    int m_angleMinus_;
    int m_anglePlus_;
    int m_baseAngle_;

    // each single branch length
    double m_length_;

    // indicate whole generation count
    int m_generationCount_;

    // indicate current generation
    // start from 0
    // to the value of the m_generationCount_
    int m_currentGeneration_;


    QPropertyAnimation * m_selfGenerateAnimation_;

    QGraphicsScene * m_branchesScene_;

    QList<SingleSimpleBranch *> m_singleBranchList_;

};

#endif // SelfGenerateBranch_H
