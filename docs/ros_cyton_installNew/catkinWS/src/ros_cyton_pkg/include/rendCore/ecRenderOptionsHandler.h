#ifndef ec_RenderOptionsHandler_H_
#define ec_RenderOptionsHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderOptionsHandler.h
/// @brief Provides a hook by which optional components may be
///        inserted and used within the scenegraph.  It is currently
///        set so that it will be called for all EcRenderWindow-based
///        windows.  This may be changed later to only process if the
///        simulation file contains capability to exercise this optional
///        code.  Currently used for EcRenderSelection, rendering
///        transparency as well as deformable geometry.
//
//------------------------------------------------------------------------------
#include <foundCore/ecTypes.h>

#include <osgGA/GUIEventHandler>

class EcRenderShape;
class EcRenderWindow;

namespace Ec
{

/// Unique identifier (linkID, shapeID) for a geometry group.
typedef std::pair<EcU32, EcU32> LinkShapePair;
/// Maps unique identifier to a render shape.
typedef std::map<LinkShapePair, osg::ref_ptr<EcRenderShape> > LinkShapePairMap;
/// Vector of maps
typedef std::vector<LinkShapePairMap> LinkShapePairMapVector;

class RenderOptionsHandler : public osgGA::GUIEventHandler
{
public:
   RenderOptionsHandler
      (
      EcRenderWindow* pWin
      );

   bool handle
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& aa
      );

protected:
   LinkShapePairMapVector m_ShapeMap; ///< Map of link shapes
   EcRenderWindow* m_pWindow;         ///< Handle to window in use
};

} // namespace Ec

#endif // ec_RenderOptionsHandler_H_
