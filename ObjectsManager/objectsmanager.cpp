#include "objectsmanager.h"
#include "MapComponents/landobject.h"


ObjectsManager::ObjectsManager()
{

}


ObjectsManager::~ObjectsManager()
{

}



BaseObject * ObjectsManager::createLandObject()
{
    LandObject * landObjectTemp = new LandObject();
    m_landObjectList_.push_back(landObjectTemp);

    return nullptr;
}
