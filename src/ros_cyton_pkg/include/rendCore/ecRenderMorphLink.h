#ifndef ecRenderMorphLink_H_
#define ecRenderMorphLink_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderMorphLink.h
/// @brief Morph rendering class.  Data for this class is held within an
///        EcIndividualManipulator.  This class uses an OSG update visitor
///        node to traverse the already-built scene graph.  It looks for nodes
///        of type EcRenderManipulator, which contains a handle to the manipulator.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <osg/ref_ptr>
#include <map>

/// Forward declarations.
class EcRenderManipulator;
class MorphTexture;

namespace osg
{
   class Node;
}

class EC_RENDER_RENDCORE_DECL EcRenderMorphLink
{
public:
   /// Traverses node graph and creates morphing geometry.
   /// \param[in, out] root Top-level node to begin traversal.
   static void init
      (
      osg::Node *root
      );

protected:
   static osg::ref_ptr<MorphTexture> updateVertexTexture
      (
      EcRenderManipulator *root
      );

   static void createGeometry
      (
      EcRenderManipulator *root
      );
   typedef std::map<EcU32, osg::ref_ptr<MorphTexture> > MorphTextureMap;

   static MorphTextureMap m_MorphTextureMap;
};

#endif // ecRenderMorphLink_H_
