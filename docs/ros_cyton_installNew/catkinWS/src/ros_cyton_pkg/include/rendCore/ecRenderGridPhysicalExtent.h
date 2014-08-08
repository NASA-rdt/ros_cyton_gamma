#ifndef ecRenderGridPhysicalExtent_H_
#define ecRenderGridPhysicalExtent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderGridPhysicalExtent.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <geometry/ecGridPhysicalExtent.h>

// Forward declarations
namespace osg
{
   class Geode;
   class Texture1D;
}

class EC_RENDER_RENDCORE_DECL EcRenderGridPhysicalExtent
{
public:
   static osg::Texture1D *createLUTTexture
      (
      const EcXmlVectorVector &lutTable
      );

   /// render this GridPhysicalExtent
   static osg::Geode *init
      (
      const EcGridPhysicalExtent *pPhy
      );
};

#endif // ecRenderGridPhysicalExtent_H_
