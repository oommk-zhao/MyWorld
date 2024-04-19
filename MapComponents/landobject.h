#ifndef LANDOBJECT_H
#define LANDOBJECT_H

#include "BaseComponents/baseobject.h"
#include "MapComponents/landpropertycomp.h"
#include "MapComponents/landgraphiccomp.h"
#include "MapComponents/landmapcomp.h"

// We need copy constructor, operator "=" here for this class

class LandObject: public BaseObject
{
public:

    LandObject();
    LandObject(const LandObject&);
    LandObject(LandObject&&);

    LandObject &operator=(const LandObject&);
    LandObject &operator=(LandObject&&);


    virtual ~LandObject();

    // update contained components
    void updateWholeObject();

    // private functions/methods
private:

    void simpleInitialization();

    // private variables
private:

    // Make all components first be the pointer
    // Depends on the performance
    // Changes them to the Objects, if needed

    // basic property component
    LandPropertyComp * m_basePropertyComp_p;

    // basic map property component
    LandMapComp * m_baseMapComp_p;

    // graphic component to paint
    LandGraphicComp * m_graphicComp_p;


};

#endif // LANDOBJECT_H
