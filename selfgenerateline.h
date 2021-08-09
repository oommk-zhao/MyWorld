#ifndef SELFGENERATELINE_H
#define SELFGENERATELINE_H

#include <QDebug>
#include <QObject>
#include <QGraphicsLineItem>


class SelfGenerateLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    SelfGenerateLine(QObject * parent = nullptr);
    virtual ~SelfGenerateLine();

    void setGraphicsParent(QGraphicsItem * graphicsParent = nullptr);

private:


};

#endif // SELFGENERATELINE_H
