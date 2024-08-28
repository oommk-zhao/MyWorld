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

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

class WorldBGWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit WorldBGWindow(QWidget *parent = nullptr);

signals:

};

#endif // WORLDBGWINDOW_H
