#ifndef ecRenderCaptureManager_H_
#define ecRenderCaptureManager_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderCaptureManager.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecSGWindow.h"

#include <foundCore/ecWait.h>

// for generic method or function binding
#include <boost/function.hpp>

// Forward declarations.
namespace osg
{
   class Image;
}

namespace osgViewer
{
   class Viewer;
}

class EC_RENDER_RENDCORE_DECL EcRenderCaptureManager : public EcSGWindow::ImageCaptureDrawCallback
{
public:
   /// Signature of callback function to register.
   //typedef void (* CallbackFunction)(const osg::Image*);
   typedef boost::function< void (const osg::Image*) > CallbackFunction;

   enum CurrentMode
   {
      ModeCapture,
      ModePaused
   };

   EcRenderCaptureManager
      (
      );

   virtual EcBoolean preRender
      (
      osgViewer::Viewer *viewer
      );

   virtual void setFrameRate
      (
      const EcF32 rate
      );

   virtual void setCaptureSize
      (
      const EcU32 width,
      const EcU32 height
      );

   virtual void setMode
      (
      const CurrentMode mode
      );

   CurrentMode getMode
      (
      ) const;

   virtual EcBoolean postRender
      (
      osgViewer::Viewer *viewer = EcNULL
      );

   virtual void setCallbackFunction
      (
      CallbackFunction fn
      );

   osg::ref_ptr<osg::Image> getCapturedImage
      (
      ) const;

protected:

   virtual ~EcRenderCaptureManager
      (
      );

   /// Internal timer to determine spacing between frames.
   boost::posix_time::ptime m_Timer;

   osg::ref_ptr<osg::Image> m_rOutputImage; //< Only used if scaling

   EcBoolean m_ImageScaling;
   /// Desired output framerate in milliseconds.
   EcF32 m_FrameTimeInMS;

   /// Desired image width.
   EcU32 m_OutputWidth;
   /// Desired image height.
   EcU32 m_OutputHeight;

   CurrentMode m_CurrentMode;
   CallbackFunction m_pCallback;
};

#endif // ecRenderCaptureManager_H_
