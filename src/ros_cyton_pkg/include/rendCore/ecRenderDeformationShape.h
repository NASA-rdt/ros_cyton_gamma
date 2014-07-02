#ifndef ecRenderDeformationShape_H_
#define ecRenderDeformationShape_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderDeformationShape.h
/// @brief interface for the EcRenderDeformationShape class.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderShape.h"

// Forward declarations
class EcCuttingPhysicalExtent;

namespace osg
{
   class Texture;
}

class EC_RENDER_RENDCORE_DECL EcRenderDeformationShape : public EcRenderShape
{
public:
	EcRenderDeformationShape
      (
      const EcBasePhysicalExtent *pPhy,
      const EcStringDataMapMap &manSurfaces
      );

   virtual ~EcRenderDeformationShape
      (
      );

   /// Update for deformation code
   virtual void update
      (
      EcBasePhysicalExtent *pPhy
      );

   /// Update for transparent alpha
   virtual void updateAlpha
      (
      const EcF32 alpha
      );

   virtual void updateCutting
      (
      const EcU32 gid,
      const EcU32 index,
      const EcCuttingPhysicalExtent *pPhy
      );

protected:
   virtual EcBoolean addCuttingGroup
      (
      const EcU32 index,
      const EcCuttingPhysicalExtent *pCutPhy
      );

   virtual osg::Texture *createTextureMarkingRenderer
      (
      const osg::Texture *tex,
      osg::Group *parent,
      const EcTriPhysicalExtent *pPhyTri
      );

   /// number of new triangles drawn in previous loop.
   EcU32 m_PreDrawnFacetInCut;

   std::map<osg::Geometry *, EcBoolean> m_MarkingMap;
};

#endif // ecRenderDeformationShape_H_
