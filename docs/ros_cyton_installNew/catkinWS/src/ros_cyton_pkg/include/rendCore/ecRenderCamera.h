#ifndef ecRenderCamera_H_
#define ecRenderCamera_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderCamera.h
/// @brief Class to encapsulate another osg::CameraNode into the scene
///        Can be used for off-screen rendering, high range (float)
///        buffers, or just another view.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <osg/Camera>
#include <osg/Texture2D>
#include <osgUtil/SceneView>

class EcSGWindow;

class EC_RENDER_RENDCORE_DECL EcRenderCamera
{
public:
   enum CaptureMode
   {
      CAPTURE_COLOR,
      CAPTURE_DEPTH
   };

   EcRenderCamera
      (
      );

   virtual ~EcRenderCamera
      (
      );

   EcBoolean init
      (
      osg::ref_ptr<osgUtil::SceneView> sv,
      const GLenum format = GL_RGB
      );

   virtual void update
      (
      const osg::Matrix &projectionMatrix,
      const osg::Matrix &viewMatrix
      );

   virtual void postDraw
      (
      );

   virtual void setPixelFormat
      (
      const GLenum format
      );

   void setCaptureMode
      (
      const CaptureMode mode
      );

   osg::Image *getImage
      (
      ) const;

   osg::Image *getDepthImage
      (
      ) const;

   osg::CameraNode *getCamera
      (
      ) const;


protected:
   struct cameraCallback : public osg::CameraNode::DrawCallback
   {
      cameraCallback
         (
         EcRenderCamera *cam
         );

      virtual void operator()
         (
         const osg::Camera &node
         ) const;

      EcRenderCamera *m_pCam;
   };

   EcBoolean             m_Initialized;
   GLenum                m_PixelFormat;
   GLenum                m_PixelType;
   CaptureMode           m_CaptureMode;

   osg::ref_ptr<osgUtil::SceneView> m_rScene;
   osg::ref_ptr< osg::Texture2D> m_rDepthTexture;
   osg::ref_ptr<     osg::Image> m_rImage;
   osg::ref_ptr<     osg::Image> m_rDepthImage;
   osg::ref_ptr<osg::Camera> m_rCamera;
};

#endif // ecRenderCamera_H_
