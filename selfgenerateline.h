#ifndef SELFGENERATELINE_H
#define SELFGENERATELINE_H

#include <QDebug>
#include <QObject>
#include <QPointF>
#include <QGraphicsLineItem>


class SelfGenerateLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT

    Q_PROPERTY(QPointF m_linePosY READ getLinePosY WRITE setLinePosY)

public:
    SelfGenerateLine(QObject * parent = nullptr);
    virtual ~SelfGenerateLine();

    void setGraphicsParent(QGraphicsItem * graphicsParent = nullptr);

    QPointF getLinePosY(void);
    void setLinePosY(QPointF linePosY);

private:

    QPointF m_linePosY;
};

#endif // SELFGENERATELINE_H
