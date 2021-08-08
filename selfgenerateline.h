#ifndef SELFGENERATELINE_H
#define SELFGENERATELINE_H

#include <QDebug>
#include <QObject>
#include <QGraphicsLineItem>


class SelfGenerateLine : public QObject, public QGraphicsLineItem
{

public:
    SelfGenerateLine(void);
    ~SelfGenerateLine();

private:


};

#endif // SELFGENERATELINE_H
