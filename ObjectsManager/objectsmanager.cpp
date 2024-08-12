#include "objectsmanager.h"
#include "MapComponents/landobject.h"

ObjectsManager::ObjectsManager() {}

ObjectsManager::~ObjectsManager()
{
    m_landObjectList_.clear();
}

BaseObject *ObjectsManager::createLandObject()
{
    LandObject * landObjectTemp = new LandObject();
    m_landObjectList_.push_back(landObjectTemp);

    return nullptr;
}

void ObjectsManager::createTrialWorld(void)
{
    // Target 0_0_0
    // Trial world
    // in this world, we use ObjectsManager as factory and maintainer

    // All are simple and easy implementation.
    // will be improved and refactored in the future.

    // We need a executable world first!

    int trialLandNumber = 9;

    return;
}
