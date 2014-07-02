#ifndef ecRenderBoundingVolumes_H_
#define ecRenderBoundingVolumes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderBoundingVolumes.h
/// @brief Encapsulates the creation and rendring of bounding volumes for
///        the shapes contained within an EcManipulatorLink.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCommon/ecDataMap.h>

#include <osg/ref_ptr>

// Forward declarations.
class EcShape;
namespace osg { class Node; }

class EC_RENDER_RENDCORE_DECL EcRenderBoundingVolumes
{
public:
   /// Traverses node graph and inserts bounding volumes.
   /// @param node Top-level node to begin traversal
   static void init
      (
      osg::Node *node
      );

   /// Traverses node graph and removes bounding volumes.
   /// @param node Top-level node to begin traversal
   static void clear
      (
      osg::Node *node
      );

   /// Creates a set of bounding volumes based off of the incoming EcShape.
   /// @param  pOrigShape              EcShape from which to pull BV data from
   /// @param  manSurfaces             Base manipulator surface properties
   /// @param  jointIndex              Index for this link
   /// @return osg::ref_ptr<osg::Node> Completed bounding volume[s]
   static osg::ref_ptr<osg::Node> makeBV
      (
      const EcShape *pOrigShape,
      const EcStringDataMapMap &manSurfaces,
      const EcU32 jointIndex
      );
};

#endif // ecRenderBoundingVolumes_H_
