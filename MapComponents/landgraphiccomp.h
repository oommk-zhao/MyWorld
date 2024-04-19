#ifndef LANDGRAPHICCOMP_H
#define LANDGRAPHICCOMP_H

#include "BaseComponents/basegraphiccomp.h"

#include <QGraphicsObject>

class LandGraphicComp : public BaseGraphicComponent
{
public:
    LandGraphicComp();
    LandGraphicComp(const LandGraphicComp &);
    LandGraphicComp(LandGraphicComp &&);

    LandGraphicComp &operator=(const LandGraphicComp &);
    LandGraphicComp &operator=(LandGraphicComp &&);

private:
    // yes, let's first keep QGraphicItem in each Object
    // And TRY.

    // For the reason, there is no QGraphicsStandardItem,
    // Is it necessary to create the standard graphics item for this version?

    //QGraphicsObject graphicItem_;
};

#endif // LANDGRAPHICCOMP_H
