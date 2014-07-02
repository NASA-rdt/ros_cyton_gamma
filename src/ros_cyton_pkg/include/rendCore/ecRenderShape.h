#ifndef ecRenderShape_H_
#define ecRenderShape_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderShape.h
/// @brief interface for the EcRenderShape class.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderTypes.h"
#include <foundCommon/ecDataMap.h>
#include <geometry/ecTriangle.h>

#include <osg/Geode>
#include <boost/shared_ptr.hpp>

// Forward declarations
class EcBasePhysicalExtent;
class EcTriPhysicalExtent;
class EcManipulatorLink;

namespace osg
{
   class Geometry;
}

class EC_RENDER_RENDCORE_DECL EcRenderShape :public osg::Geode
{
public:
   /// Constructor - Geometry created via OSG loader.
   EcRenderShape
      (
      const osg::Geode &node,
      const osg::CopyOp &copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// Constructor - Creates node hierarchy for this physical extent.
   /// \param[in] pPhy        Pointer to PE to use.
   /// \param[in] manSurfaces Surface properties from parent manipulator.
	EcRenderShape
      (
      const EcBasePhysicalExtent *pPhy,
      const EcStringDataMapMap &manSurfaces
      );

   /// Factory method for creating proper EcRenderShape class.
   /// \param[in] link        Link used to determine shape type.
   /// \param[in] pPhy        Pointer to arrays for building geometry.
   /// \param[in] manSurfaces Surfaces properties from manipulator.
   /// \return Pointer to newly allocated class of proper type.
   static EcRenderShape *newEcRenderShape
      (
      const EcManipulatorLink &link,
      const EcBasePhysicalExtent *pPhy,
      const EcStringDataMapMap &manSurfaces
      );

   /// Retrieves the complete list of all attributes set.
   virtual EcRenderTypes::TypeAttribute getAttributes
      (
      ) const;

   /// Sets an individual attribute for this node.
   virtual void setAttribute
      (
      const EcRenderTypes::Attributes attr
      );

   /// Clears and individual attribute for this node.
   virtual void clearAttribute
      (
      const EcRenderTypes::Attributes attr
      );

   /// Tests an individual attribute for this node.
   virtual EcBoolean isAttributeSet
      (
      const EcRenderTypes::Attributes attr
      ) const;

   /// Method intended to be overloaded by sub-classes for deformation, etc.
   /// \param[in] pPhy Pointer to current PE to pull data from.
   virtual void update
      (
      EcBasePhysicalExtent *pPhy
      );

   virtual void updateAlpha
      (
      const EcF32 alpha
      );

   /// Converts generic physical extent to a geode group.
   /// \param[in] pPhy Physical extent to create geode from.
   /// \return Passes back populated Node.
   static osg::ref_ptr<osg::Geode> createGeometry
      (
      const EcBasePhysicalExtent *pPhy
      );

   boost::shared_ptr<EcRenderShape> getSharedPtr
      (
      ) const;

   osg::ref_ptr<osg::Group> getFXPtr
      (
      ) const;

protected:
   /// Protected to keep from explicitly being called.
   virtual ~EcRenderShape
      (
      );

   /// Takes a tri physical extent and triangle indices and generates
   /// a set of geometry.
   /// \param[in] pTriPhy Physical extent to pull vectors from
   /// \param[in] tris    Triangle vector of indices.
   /// \param[in] surface Surface property to associate with this geometry.
   /// \return Returns geometry node.
   osg::ref_ptr<osg::Geometry> addGroup
      (
      const EcTriPhysicalExtent *pTriPhy,
      const EcTriangleVector &tris,
      const EcDataMap &surface
      );

   /// Indicates whether geode is deformable or selected.
   EcRenderTypes::TypeAttribute m_Attributes;

   /// Internal reference counted pointer to this instance to pass to physical extent.
   mutable boost::shared_ptr<EcRenderShape> m_rSharedThis;

   mutable osg::ref_ptr<osg::Group> m_pFX;
};

#endif // ecRenderShape_H_
