#ifndef ecRenderAxisAlignedBoundingBox_H_
#define ecRenderAxisAlignedBoundingBox_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderAxisAlignedBoundingBox.h
/// @brief Encapsulation of code used to create and render AABBs.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.

// Forward declarations.
namespace osg
{
   class Node;
}

class EC_RENDER_RENDCORE_DECL EcRenderAxisAlignedBoundingBox
{
public:
   /// Creates wireframe AABBs around this link.  Also registers
   /// an update callback to update the extents every frame.
   /// \\param[inout] root Top-level node to begin traversal from.
   static void init
      (
      osg::Node *root
      );

   /// Traverses node graph and removes AABBs.
   /// @param node Top-level node to begin traversal
   static void clear
      (
      osg::Node *node
      );
};

#endif // ecRenderAxisAlignedBoundingBox_H_
