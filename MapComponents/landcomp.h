#ifndef LANDCOMPONENT_H
#define LANDCOMPONENT_H

#include "MapComponents/landpropertycomp.h"
#include "MapComponents/landgraphiccomp.h"
#include "MapComponents/landmapcomp.h"

class LandComponent
{
public:

    LandComponent();

    // update contained components
    void updateSubComponents();


private:

    // basic property component
    LandPropertyComp m_baseComp_;

    // basic map property component
    LandMapComp m_baseMapComp_;

    // graphic component to paint
    LandGraphicComp m_graphicComp_;


};

#endif // LANDCOMPONENT_H
