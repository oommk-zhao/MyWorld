#include "instancemanager.h"
#include "objectsmanager.h"

InstanceManager *InstanceManager::instanceManager_ = nullptr;

InstanceManager::InstanceManager()
    : objectsManager_(nullptr)
{
    objectsManager_ = new ObjectsManager();
}

InstanceManager::InstanceManager(InstanceManager &) {}

InstanceManager::~InstanceManager()
{
    return;
}

InstanceManager *InstanceManager::getInstanceManager(void)
{
    if (instanceManager_ == nullptr) {
        instanceManager_ = new InstanceManager();
    }
    return instanceManager_;
}

std::shared_ptr<ObjectsManager> InstanceManager::getObjectsManager(void)
{
    return std::shared_ptr<ObjectsManager>(objectsManager_);
}
