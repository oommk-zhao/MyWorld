#ifndef LANDCOMPONENT_H
#define LANDCOMPONENT_H

#include "baseobject.h"
#include "MapComponents/landpropertycomp.h"
#include "MapComponents/landgraphiccomp.h"
#include "MapComponents/landmapcomp.h"

class LandComponent : public BaseObject
{
public:

    LandComponent();
    virtual ~LandComponent();

    // update contained components
    void updateWholeObject();


private:

    // basic property component
    LandPropertyComp m_basePropertyComp_;

    // basic map property component
    LandMapComp m_baseMapComp_;

    // graphic component to paint
    LandGraphicComp m_graphicComp_;


};

#endif // LANDCOMPONENT_H
