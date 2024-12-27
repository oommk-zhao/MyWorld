#include "worldbgwindow.h"
#include "MapComponents/landobject.h"

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
    viewObject_ = new GraphicsViewObject(this, sceneObject_);
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

    // Set Scene Retangle by default first, in trial version
    // sceneObject_->setSceneRectangle(0, 0, 0, 0);
    // And same for the Graphics View
    // viewObject->setSceneRect(0, 0, 0, 0);

    // okay, how is the proper way to add graphicsItem?

    // lets say in trial first version, we use static_cast for temporary solution

    auto itemList = objectsManager_->getTrialWorldLandObjectList();

    for (auto itemIt : itemList) {
        auto graphicsItem = itemIt->getGraphicsItem();
        sceneObject_->addItems(graphicsItem);
    }

    return;
}
