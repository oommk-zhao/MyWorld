#ifndef GRAPHICSSCENEOBJECT_H
#define GRAPHICSSCENEOBJECT_H

#include "graphicsviewobject.h"

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QObject>

// This is for QGraphicsScene container

class GraphicsSceneObject : public QObject
{
    Q_OBJECT

    friend class GraphicsViewObject;

public:
    explicit GraphicsSceneObject(QObject *parent = nullptr);

    void addItems(std::vector<QGraphicsItem *> graphicsItemList);
    void addItems(QGraphicsItem *graphicsItem);

signals:

private:
    // Will not return/expose QGraphicsScene to the outside
    // So, return QGraphicsView is forbidden here
    QGraphicsScene *getGraphicsScene(void);

    QGraphicsScene *graphicsScene_;
};

#endif // GRAPHICSSCENEOBJECT_H
