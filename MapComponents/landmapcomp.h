#ifndef LANDMAPCOMP_H
#define LANDMAPCOMP_H

#include "BaseComponents/basemapcomp.h"

class LandMapComp : public BaseMapCompoment
{
public:
    LandMapComp();
    LandMapComp(const LandMapComp &);
    LandMapComp(LandMapComp &&);

    LandMapComp &operator=(const LandMapComp &);
    LandMapComp &operator=(LandMapComp &&);

    void updateComp();

private:
    // First make the world map flat
    // Keep the posibility of extension, the world could be any shape.
    int mapIndex_;
    int mapSize_;
};

#endif // LANDMAPCOMP_H
