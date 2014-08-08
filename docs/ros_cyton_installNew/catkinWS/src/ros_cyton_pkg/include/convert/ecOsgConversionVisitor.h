#ifndef ecOsgConversionVisitor_H_
#define ecOsgConversionVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecOsgConversionVisitor.h
/// @class EcOsgConversionVisitor
/// @brief Utility class for OSG file loader
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <boost/shared_ptr.hpp>

#include <osg/Geometry>
#include <osg/NodeVisitor>

#include <geometry/ecShapeAccumulator.h>
#include <manipulator/ecIndManipulator.h>

// Forward declarations
namespace osg
{
    class Material;
    class Texture2D;
}

//----------------------------------------------------------------------------
/**
 *  \class EcOsgConversionVisitor
 *  \brief Visits nodes in an osg node file to create a EcPolyPhysicalExtent
 */
//----------------------------------------------------------------------------
class EC_RENDER_CONVERT_DECL EcOsgConversionVisitor : public osg::NodeVisitor
{
public:
    EcOsgConversionVisitor (void);

    void populateManipulatorShape (EcIndividualManipulator& manip) const;

    // Implementation of osg::NodeVisitor interface
    virtual void reset (void);
    virtual void apply (osg::Geode& node);
    virtual EcReal scaleFactor
       (
       ) const;
    virtual void setScaleFactor
       (
       EcReal scaleFactor
       );

protected:
    typedef boost::shared_ptr<EcPolyPhysicalExtent> ExtentPtr;

    void getSurfaces
    (
        osg::ref_ptr<osg::Geometry> geometry,
        const EcDataMap&            geodeSurface,
        EcStringDataMapMap&         surfaces
    );

    void transformExtent
    (
        const osg::Geode& node,
        ExtentPtr         pExtent
    );

    //---
    // Static conversion functions
    //---

    static void convertArrayToPlanarVectorVector
    (
        const osg::Array&     array,
        EcPlanarVectorVector& planarVectorVector
    );

    static void convertArrayToXmlVectorVector
    (
        const osg::Geometry::ArrayData& arrayData,
        EcXmlVectorVector&              xmlVectorVector
    );

    //---
    // Static surface conversion functions
    //---

    static void convertMaterialToSurface
    (
        const osg::Material* material,
        EcDataMap&           surface
    );

    static void convertStateSetToSurface
    (
        const osg::StateSet* stateSet,
        EcDataMap&           surface
    );

    static void convertTextureToSurface
    (
        const osg::Texture2D* texture,
        EcDataMap&            surface
    );

    static const osg::Texture2D* getTexture
    (
        const osg::StateSet* stateSet
    );

    //---
    // Static geometry conversion functions
    //---

    static void convertDrawArrayLengthsToPolygonVector
    (
        const osg::DrawArrayLengths* drawArrayLengths,
        GLenum                       mode,
        EcPolygonWithKeyVector&      polygonVector
    );

    static void convertDrawArraysToPolygonVector
    (
        const osg::DrawArrays*  drawArrays,
        GLenum                  mode,
        EcPolygonWithKeyVector& polygonVector
    );

    static void convertDrawElementsUShortToPolygonVector
    (
        const osg::DrawElementsUShort* drawElements,
        GLenum                         mode,
        EcPolygonWithKeyVector&        polygonVector
    );

    static void convertPrimitiveSetListToPolygonVector
    (
        const osg::Geometry::PrimitiveSetList& primitiveSets,
        EcPolygonWithKeyVector&                polygonVector
    );

    //---
    // Static geometry conversion functions for osg::PrimitiveSet::TRIANGLES
    //---

    static void convertTrianglesToPolygonVector
    (
        const osg::DrawArrayLengths* drawArrayLengths,
        EcPolygonWithKeyVector&      polygonVector
    );

    static void convertTrianglesToPolygonVector
    (
        const osg::DrawArrays*  drawArrays,
        EcPolygonWithKeyVector& polygonVector
    );

    static void convertTrianglesToPolygonVector
    (
        const osg::DrawElementsUShort* drawElements,
        EcPolygonWithKeyVector&        polygonVector
    );

    //---
    // Static geometry conversion functions for osg::PrimitiveSet::TRIANGLE_STRIP
    //---

    static void convertTriangleStripToPolygonVector
    (
        const osg::DrawArrayLengths* drawArrayLengths,
        EcPolygonWithKeyVector&      polygonVector
    );

    static void convertTriangleStripToPolygonVector
    (
        const osg::DrawArrays*  drawArrays,
        EcPolygonWithKeyVector& polygonVector
    );

    static void convertTriangleStripToPolygonVector
    (
        const osg::DrawElementsUShort* drawElements,
        EcPolygonWithKeyVector&        polygonVector
    );

    //---
    // Static geometry conversion functions for osg::PrimitiveSet::TRIANGLE_FAN
    //---

    static void convertTriangleFanToPolygonVector
    (
        const osg::DrawElementsUShort* drawElements,
        EcPolygonWithKeyVector&        polygonVector
    );

    //---
    // Static geometry conversion functions for osg::PrimitiveSet::QUADS
    //---

    static void convertQuadsToPolygonVector
    (
        const osg::DrawArrays*  drawArrays,
        EcPolygonWithKeyVector& polygonVector
    );

    //---
    // Static geometry conversion functions for osg::PrimitiveSet::POLYGON
    //---

    static void convertPolygonToPolygonVector
    (
        const osg::DrawArrayLengths* drawArrayLengths,
        EcPolygonWithKeyVector&      polygonVector
    );

    static void convertPolygonToPolygonVector
    (
        const osg::DrawArrays*  drawArrays,
        EcPolygonWithKeyVector& polygonVector
    );

    //---
    // Data members
    //---

    typedef boost::shared_ptr<EcManipulatorLink> LinkPtr;
    typedef std::vector<LinkPtr>                 LinkPtrVector;

    EcShapeAccumulator m_ShapeAccumulator;
    LinkPtrVector      m_LinkPtrVector;
    EcBoolean          m_LoadAsIndividualLinks;
    EcReal             m_ScaleFactor;     /// scale factor for model size
};

#endif // ecOsgConversionVisitor_H_
