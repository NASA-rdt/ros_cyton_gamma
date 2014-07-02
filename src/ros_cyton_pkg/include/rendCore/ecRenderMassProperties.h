#ifndef ecRenderMassProperties_H_
#define ecRenderMassProperties_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderMassProperties.h
/// @brief Encapsulation of code used to create and render mass
///        properties of an EcManipulatorLink using ellipsoids.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.

// Forward declarations.
namespace osg
{
   class Node;
}

class EC_RENDER_RENDCORE_DECL EcRenderMassProperties
{
public:
   /// Creates an ellipsoid representing the mass properties for this link.
   /// \\param[inout] root Top-level node to begin traversal from.
   static void init
      (
      osg::Node *root
      );

   /// Traverses node graph and removes bounding volumes.
   /// @param node Top-level node to begin traversal
   static void clear
      (
      osg::Node *node
      );
};

#endif // ecRenderMassProperties_H_
