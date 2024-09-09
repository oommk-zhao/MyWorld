#ifndef GRAPHICSVIEWOBJECT_H
#define GRAPHICSVIEWOBJECT_H

#include <QGraphicsView>
#include <QObject>

// This is for QGraphicsView container

class GraphicsViewObject : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsViewObject(QObject *parent = nullptr);

signals:

private:
    // Will not return/expose QGraphicsView to the outside
    // So, return QGraphicsView is forbidden here
    QGraphicsView *getGraphicsView(void);

    QGraphicsView *graphicsView_;
};

#endif // GRAPHICSVIEWOBJECT_H
