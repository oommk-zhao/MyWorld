#include "landgraphiccomp.h"
#include "GraphicsObjects/mgraphicsobject.h"

LandGraphicComp::LandGraphicComp()
    : BaseGraphicComponent()
{
    BaseGraphicComponent::graphicsObject_ = new MGraphicsObject();
}
