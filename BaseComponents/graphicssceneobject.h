#ifndef GRAPHICSSCENEOBJECT_H
#define GRAPHICSSCENEOBJECT_H

#include <QGraphicsScene>
#include <QObject>

// This is for QGraphicsScene container

class GraphicsSceneObject : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsSceneObject(QObject *parent = nullptr);

signals:

private:
    // Will not return/expose QGraphicsScene to the outside
    // So, return QGraphicsView is forbidden here
    QGraphicsScene *getGraphicsScene(void) { return nullptr; }

    QGraphicsScene *graphicsScene_;
};

#endif // GRAPHICSSCENEOBJECT_H
