#ifndef ecRenderPath_H_
#define ecRenderPath_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderPath.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <foundCore/ecTypes.h>
#include <foundCore/ecVector.h>

#include <osg/ref_ptr>
#include <osg/Array>
#include <osgSim/ColorRange>
#include <osgSim/ScalarBar>

// Forward declarations.
namespace osg
{
   class Group;
   class MatrixTransform;
   class Node;
}

class EC_RENDER_RENDCORE_DECL EcRenderPath
{
public:
   
   EcRenderPath
      (
      );

   virtual ~EcRenderPath
      (
      );

   virtual EcBoolean init
      (
      osg::Group* rootNode,
      EcU32 maxCount = 500
      );

   virtual void setMaxCount
   (
     EcU32 max
   );

   virtual EcU32 maxCount
   (
   ) const;

   virtual void setPathVisibilityEnabled
      (
      EcBoolean isVisible
      );

   virtual EcBoolean pathVisibilityEnabled
      (
      ) const;

   virtual void setColorRange
      (
       osgSim::ColorRange* colorRange
      );

   virtual void setPathColor
   (
     const osg::Vec4& color
   );

   virtual const osg::Vec4& pathColor
   (
   ) const;

   virtual void setUseColorRange
   (
      EcBoolean useColorRange
   );

   virtual EcBoolean useColorRange
   (
   ) const;

   virtual EcBoolean addPointToPath
      (
      const EcVector& pointPosition,
      EcReal scalar
      );

protected:

   osg::Group*                  m_pRootNode;       ///< the root osg node of the scene
   EcU32                        m_MaxCount;        ///< Max number of points to render
   EcU32                        m_Count;           ///< Current number of rendered points
   EcU32                        m_CurrentIndex;    ///< Index array for next set point

   EcF32                        m_LineWidth;       ///< Width of the path line
   osg::ref_ptr<osg::Geode>     m_pPointGroupNode; ///< Point owning group
   osg::DrawArrays*             m_vpPointElements; ///< Handle to array manipulation
   osg::Vec3Array*              m_vpPoints;        ///< List of renderable tracer points
   osg::Vec4Array*              m_vpColors;        ///< Colors of renderable tracer points

   osgSim::ColorRange*          m_pColorRange;     ///< color range to map scalars to colors
   osg::Vec4                    m_PathColor;       ///< solid Color for the path, used if m_UseScalarsToColors is false
   EcBoolean                    m_UseColorRange;   ///< color paths using ScalarsToColors if true, use PathColor if false

   osg::Vec3d                   m_OldPosition;     ///< Previous position

};

#endif // ecRenderPath_H_
