#ifndef ecRenderAxis_H_
#define ecRenderAxis_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderAxis.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

#include <osg/ref_ptr>

// Forward declarations.
namespace osg
{
   class Group;
   class MatrixTransform;
   class Node;
}

class EC_RENDER_RENDCORE_DECL EcRenderAxis
{
public:
   /// Insert link axis nodes throughout scene graph.
   /// \param[in,out] root Top of node graph to traverse.
   static void init
      (
      osg::Node *root
      );

   /// Retrieve a referenced-copy of the global guide axis.
   /// \param[in] asGeode  Specify whether or not to return the just the osg::Geode
   ///            or include a parent osg::MatrixTransform for rotation.
   /// \return    Returns an osg::Node to either the parent MatrixTransform
   ///            or just the Geode itself.
   static osg::ref_ptr<osg::Node> linkAxis
      (
      const EcBoolean asGeode = EcFalse
      );

   /// Size all guide axes with a uniform scale factor.
   /// \param[in] scale Size to scale axis to.
   static void scaleAxis
      (
      const EcReal scale
      );

protected:
   /// guide frame axis reused for all transforms.
   static osg::ref_ptr<osg::MatrixTransform> m_theLinkAxis;
};

#endif // ecRenderAxis_H_
