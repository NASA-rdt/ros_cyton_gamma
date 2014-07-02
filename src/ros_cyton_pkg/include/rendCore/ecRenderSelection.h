#ifndef ecRenderSelection_H_
#define ecRenderSelection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderSelection.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

// Forward declarations
class EcRenderShape;
namespace osg { class Node; }

class EC_RENDER_RENDCORE_DECL EcRenderSelection
{
public:
   /// Sets the selected attribute for the node given by the shape key.
   /// \param[in] pRenderShape Node for this manipulator to set.
   static void setSelected
      (
      EcRenderShape *pRenderShape
      );

   /// Updates nodes that have not been selected.  This will update any alpha
   /// values if changed.
   /// \param[in,out] root             Base Node to traverse.
   /// \param[in]     alpha            Alpha value to set node to.
   /// \param[in]     removeSelections If true, then  all selection information
   ///                                 is purged from scene graph.
   static void setNonselected
      (
      osg::Node *root,
      const EcF32 alpha,
      const EcBoolean removeSelections
      );
};

#endif // ecRenderSelection_H_
