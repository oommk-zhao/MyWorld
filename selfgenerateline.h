#ifndef SELFGENERATELINE_H
#define SELFGENERATELINE_H

#include <QDebug>
#include <QObject>
#include <QPointF>
#include <QGraphicsLineItem>
#include <QPropertyAnimation>


class SelfGenerateLine : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QPointF m_linePosStart_ READ getLinePosStart WRITE setLinePosStart)
    Q_PROPERTY(QPointF m_linePosEnd_ READ getLinePosEnd WRITE setLinePosEnd)

public:
    SelfGenerateLine(QObject * parent = nullptr);
    virtual ~SelfGenerateLine();

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

private:

    void generateEndPos(void);
    double generateEndPosX(int angel);
    double generateEndPosY(int angel);

    QPointF m_linePosStart_;
    QPointF m_linePosEnd_;
    QGraphicsLineItem * m_graphicsLineItem_;

    // unit = ms
    int m_singleLineDuration_;

    int m_angelBegin_;
    int m_angelEnd_;
    double m_length_;

};

#endif // SELFGENERATELINE_H
