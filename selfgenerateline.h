#ifndef SELFGENERATELINE_H
#define SELFGENERATELINE_H

#include <QDebug>
#include <QObject>
#include <QPointF>
#include <QGraphicsLineItem>


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

    QGraphicsLineItem * getGraphicsItem(void);

    void setLine(qreal x1, qreal y1, qreal x2, qreal y2);

private:

    QPointF m_linePosStart_;
    QPointF m_linePosEnd_;
    QGraphicsLineItem * m_graphicsLineItem_;
};

#endif // SELFGENERATELINE_H
