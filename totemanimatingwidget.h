#ifndef TOTEMANIMATINGWIDGET_H
#define TOTEMANIMATINGWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QPropertyAnimation>

#include "selfgeneratebranch.h"


// Responsibility (not very clear yet)

// 1. for each turn of loop, get the generated graphic item
//    and forward it to the Scene

// 2. decide whether to generate new branch
//    set the parameters "length", "Angle", "count" for the new branch

// 3. execute the main loop of the generating
//    and each branch will end itself when the "count" is at the end

// 4. hold the graphic scene and view of automatic generated totem

// ?5. pass QPropertyAnimation to all sub branch object,
//     to active the animation

// new update -
//     This widget is the object of the tree itself
//     For convenient, combined the tree object inside this widget
//     If improved, could take this tree object outside

//  TBD: how to manage the SelfGenerateBranch list
//       for all its leaves


class TotemAnimatingWidget : public QWidget
{
    Q_OBJECT
public:
    TotemAnimatingWidget(QWidget *parent = nullptr);
    virtual ~TotemAnimatingWidget();

    void showWidget(void);
    void initialization(void);
    void startAnimation(void);
    void stopAnimation(void);

    QPointF getMainBranchStartPos(void);
    void setMainBranchStartPos(QPointF linePosStart);

signals:

public slots:

    void startGenerating(void);

    void generateLeaves(SelfGenerateBranch *);

private:

    void generateBaseView(void);

    /* This is for the root */
    void generateLoop(QPointF startPos);

    int m_generatingCount_;

    int m_singleLineLength_;

    // this is the ground/grand line
    SelfGenerateBranch * m_baseBranch_;

    QGraphicsScene * m_totemGraphicsScene_;
    QGraphicsView * m_totemGraphicsView_;

    QList<SelfGenerateBranch*> m_selfGenrateBranches_;



};

#endif // TOTEMANIMATINGWIDGET_H
