#include <QDebug>

#include "landobject.h"



LandObject::LandObject():
    BaseObject(),
    m_basePropertyComp_p(),
    m_baseMapComp_p(),
    m_graphicComp_p()
{
    simpleInitialization();
}


LandObject::LandObject(const LandObject& inputObject):
    BaseObject(inputObject),
    m_basePropertyComp_p(inputObject.m_basePropertyComp_p),
    m_baseMapComp_p(inputObject.m_baseMapComp_p),
    m_graphicComp_p(inputObject.m_graphicComp_p)
{
    qDebug() << "Here is in the LandObject Copy Constructor" << Qt::endl;

}


LandObject::LandObject(LandObject&& inputObject):
    BaseObject(inputObject),
    m_basePropertyComp_p(nullptr),
    m_baseMapComp_p(nullptr),
    m_graphicComp_p(nullptr)
{
    m_basePropertyComp_p = inputObject.m_basePropertyComp_p;
    m_baseMapComp_p = inputObject.m_baseMapComp_p;
    m_graphicComp_p = inputObject.m_graphicComp_p;

    delete inputObject.m_basePropertyComp_p;
    delete inputObject.m_baseMapComp_p;
    delete inputObject.m_graphicComp_p;

    qDebug() << "Here is in the LandObject right value Constructor" << Qt::endl;
}


LandObject& LandObject::operator=(const LandObject& inputObject)
{
    if( this != &inputObject )
    {
        delete m_basePropertyComp_p;
        delete m_baseMapComp_p;
        delete m_graphicComp_p;

        m_basePropertyComp_p = inputObject.m_basePropertyComp_p;
        m_baseMapComp_p = inputObject.m_baseMapComp_p;
        m_graphicComp_p = inputObject.m_graphicComp_p;

    }

    qDebug() << "Here is the operator =, reload function..." << Qt::endl;

    return *this;
}


LandObject& LandObject::operator=(LandObject&& inputObject)
{
    if( this != &inputObject )
    {
        delete m_basePropertyComp_p;
        delete m_baseMapComp_p;
        delete m_graphicComp_p;

        m_basePropertyComp_p = inputObject.m_basePropertyComp_p;
        m_baseMapComp_p = inputObject.m_baseMapComp_p;
        m_graphicComp_p = inputObject.m_graphicComp_p;

        delete inputObject.m_basePropertyComp_p;
        delete inputObject.m_baseMapComp_p;
        delete inputObject.m_graphicComp_p;
    }

    qDebug() << "Here is the operator =, RIGHT Value, reload function..." << Qt::endl;

    return *this;
}


LandObject::~LandObject()
{
    if ( m_basePropertyComp_p )
    {
        delete m_basePropertyComp_p;
        m_basePropertyComp_p = nullptr;
    }

    if ( m_basePropertyComp_p )
    {
        delete m_basePropertyComp_p;
        m_basePropertyComp_p = nullptr;
    }

    if ( m_basePropertyComp_p )
    {
        delete m_basePropertyComp_p;
        m_basePropertyComp_p = nullptr;
    }
}


// update contained components
void LandObject::updateWholeObject()
{

}


void LandObject::simpleInitialization()
{
    m_basePropertyComp_p = new LandPropertyComp();


    m_baseMapComp_p = new LandMapComp();


    m_graphicComp_p = new LandGraphicComp();

}

