#ifndef ecRenderShapeTerrain_H_
#define ecRenderShapeTerrain_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderShapeTerrain.h
/// @brief interface for the EcRenderShapeTerrain class.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <osg/Geode>

// Forward declarations
class EcShape;
class EcDataMap;
template <typename T> class                 EcXmlBasicType;
template <typename T1, typename T2> class   EcXmlMapType;
typedef EcXmlBasicType<EcString>            EcXmlString;
typedef EcXmlMapType<EcXmlString,EcDataMap> EcStringDataMapMap;

class EC_RENDER_RENDCORE_DECL EcRenderShapeTerrain : public osg::Geode
{
public:
   /// Constructor - Geometry created via OSG loader.
   EcRenderShapeTerrain
      (
      const osg::Geode& node,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// Factory method for creating proper EcRenderShapeTerrain class. It
   /// attempts to build geometry from an EcTerrain object.  If the EcShape
   /// is not of type EcTerrain, it will fail.
   /// \param[in] pShape    Pointer to EcShape to build from
   /// \param[in] manSurfaces Surface properties from parent manipulator
   /// \param[out] skipFlag
   /// \return EcRenderShapeTerrain* Pointer to new geometry or NULL
   static EcRenderShapeTerrain* newFromEcShape
      (
      const EcShape* pShape,
      const EcStringDataMapMap& manSurfaces,
      EcBoolean& skipFlag
      );

protected:
   /// Protected constructor
   EcRenderShapeTerrain
      (
      );

   /// Protected to keep from being explicitly called.
   virtual ~EcRenderShapeTerrain
      (
      );
};

#endif // ecRenderShapeTerrain_H_
