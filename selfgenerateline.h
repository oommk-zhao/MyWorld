#ifndef SELFGENERATELINE_H
#define SELFGENERATELINE_H

#include <QDebug>
#include <QObject>
#include <QPointF>
#include <QGraphicsLineItem>


class SelfGenerateLine : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QPointF m_linePosY READ getLinePosY WRITE setLinePosY)
    Q_PROPERTY(QPointF m_linePosX READ getLinePosX WRITE setLinePosX)

public:
    SelfGenerateLine(QObject * parent = nullptr);
    virtual ~SelfGenerateLine();

    void setGraphicsParent(QGraphicsItem * graphicsParent = nullptr);

    QPointF getLinePosX(void);
    void setLinePosX(QPointF linePosX);
    QPointF getLinePosY(void);
    void setLinePosY(QPointF linePosY);

    QGraphicsLineItem * getGraphicsItem(void);

private:

    QPointF m_linePosX_;
    QPointF m_linePosY_;
    QGraphicsLineItem * m_graphicsLineItem_;
};

#endif // SELFGENERATELINE_H
