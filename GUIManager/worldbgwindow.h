#ifndef WORLDBGWINDOW_H
#define WORLDBGWINDOW_H

// Here, manage the Logo Page and Main widgets of the whole world
// For example, the Map components, and character components

// All elements/things/objects of this world are components
// Those components, the graphics related, like QGraphics items
// Shall be stored here

// The big huge Graphics objects Container and Manager

// **************************************************************************
// We need a Factory for the creation
// This is the first time to use the Factory
// Let's do/test it ourselves and see what kind of problem/issue we will meet
// **************************************************************************

#include <QMainWindow>

#include "BaseComponents/graphicssceneobject.h"
#include "BaseComponents/graphicsviewobject.h"

class WorldBGWindow : public QObject
{
    Q_OBJECT
public:
    explicit WorldBGWindow(QWidget *parent = nullptr);

signals:

private:
    void trialWorldInitialization(void);

    GraphicsSceneObject *sceneObject_;
    GraphicsViewObject *viewObject_;
    QMainWindow *worldBGWindow_;
};

#endif // WORLDBGWINDOW_H
