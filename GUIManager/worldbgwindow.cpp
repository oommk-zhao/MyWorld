#include "worldbgwindow.h"

WorldBGWindow::WorldBGWindow(QWidget *parent)
    : QObject{parent}
    , sceneObject_(nullptr)
    , viewObject_(nullptr)
    , worldBGWindow_(nullptr)
{
    trialWorldInitialization();
}

void WorldBGWindow::trialWorldInitialization(void)
{
    sceneObject_ = new GraphicsSceneObject();
    viewObject_ = new GraphicsViewObject();
    worldBGWindow_ = new QMainWindow();

    return;
}
