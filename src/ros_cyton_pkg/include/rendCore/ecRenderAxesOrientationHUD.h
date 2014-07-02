#ifndef ec_RenderAxesOrientationHUD_H_
#define ec_RenderAxesOrientationHUD_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderAxesOrientationHUD.h
/// @class EcRenderAxesOrientationHUD
/// @brief An osg heads up display camera to show the global coordinate system axes
///        orientation in the main viewer window.  X = Red, Y = Green, Z = Blue
//
//------------------------------------------------------------------------------
#include <render/render_config.h>
#include <foundCore/ecTypes.h>

#include <osg/Camera>

class EC_RENDER_RENDCORE_DECL EcRenderAxesOrientationHUD : public osg::Camera
{
public:
   /// constructor
   EcRenderAxesOrientationHUD
      (
      );

   /// sets up the axes arrow geometry nodes
   virtual void setupDefaultGeometry
   (
   );

   /// traverse the camera and it's children
   /// update the axes arrow geometry coordinate system
   /// transformation from the current view matrix of 
   /// the main camera
   virtual void traverse(osg::NodeVisitor& nv);
   
   /// sets the main camera from the osg::Viewer
   virtual void setMainCamera(osg::Camera* camera);

protected:
   /// Safeguard against stack allocation
   ~EcRenderAxesOrientationHUD
      (
      );

   osg::observer_ptr<osg::Camera>        m_MainCamera;   ///< the main camera used to get the current view matrix
   osg::ref_ptr<osg::MatrixTransform>    m_rGroup;       ///< the axes group
   float m_Thickness;                                    ///< thickness of the lines
   float m_LineWidth;                                    ///< width of the lines
   float m_ConeRadius;                                   ///< radius of the cones that makes the arrow tips
   float m_ConeHeight;                                   ///< height of the cones
};

#endif // ec_RenderAxesOrientationHUD_H_
