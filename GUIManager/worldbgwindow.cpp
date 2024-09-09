#include "worldbgwindow.h"

WorldBGWindow::WorldBGWindow(QObject *parent)
    : QObject{parent}
    , sceneObject_(nullptr)
    , viewObject_(nullptr)
    , instanceManager_(nullptr)
    , objectsManager_(nullptr)
    , worldBGWindow_(nullptr)
{}

void WorldBGWindow::createAndShowTrialWorld(void)
{
    trialWorldInitialization();
}

void WorldBGWindow::trialWorldInitialization(void)
{
    sceneObject_ = new GraphicsSceneObject(this);
    viewObject_ = new GraphicsViewObject(this);
    worldBGWindow_ = new QMainWindow();

    instanceManager_ = InstanceManager::getInstanceManager();
    objectsManager_ = instanceManager_->getObjectsManager().get();

    createTrialWorldObjects();

    createTrialGraphicsWorld();

    return;
}

void WorldBGWindow::createTrialWorldObjects(void)
{
    objectsManager_->createTrialWorldLandObjects();
}

void WorldBGWindow::createTrialGraphicsWorld(void)
{
    // We create GraphicsScene and View by hard code in Trial World
    // And should be improved during development of Trial World

    // Set Scene and View Rectangle and Geometry

    return;
}
