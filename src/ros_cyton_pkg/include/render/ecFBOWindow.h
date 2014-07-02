#ifndef ecFBOWindow_H_
#define ecFBOWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecFBOWindow.h
/// @brief Adds capability to perform off-screen rendering to a rendering
///        window.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecSimpleWindow.h"
#include "ecFrameBufferObject.h"
#include "ecTexture.h"

class EC_SENSOR_RENDER_DECL EcFBOWindow : public EcSimpleWindow
{
public:
   EcFBOWindow
      (
      );

   virtual ~EcFBOWindow
      (
      );

   ///////////////////////////////////////////////////////////////////////////
   /// Pre-init routines.  These methods are allowed before window          //
   /// initialization.                                                      //
   ///////////////////////////////////////////////////////////////////////////

   virtual EcBoolean setOffScreenRendering
      (
      const EcBoolean isOffScreenRendering
      );

   virtual EcBoolean getOffScreenRendering
      (
      ) const;

   virtual void setKeepBound
      (
      const EcBoolean isKeepBound
      );

   virtual EcBoolean getKeepBound
      (
      ) const;

   virtual void setBufferParams
      (
      const EcTextureParameters &params
      );

   /// Set the current context to write to this window.
   virtual void makeCurrent
      (
      ) const;

   ///////////////////////////////////////////////////////////////////////////
   /// Init and post-init routines.  These methods either initialize        //
   /// or force initialization when called.                                 //
   ///////////////////////////////////////////////////////////////////////////

   virtual EcBoolean init
      (
      );

   /// Draw to buffer
   virtual EcBoolean renderScene
      (
      const EcBoolean swap = EcTrue
      );

   /// render the scene and capture into an EcImage
   /// currently 3 or 4 channels supported
   virtual EcBoolean renderSceneAndCaptureImage
      (
      EcImage &image,
      const CaptureMode mode = CaptureFlippedColor,
      const EcImageBlock *const imageBlock = EcNULL
      );

protected:
   EcFrameBufferObject m_FBO;
   EcTexture m_FBOTex;
   EcTextureParameters m_Params;
   EcBoolean m_OffScreenRendering;
   EcBoolean m_KeepBound;
};

#endif // ecFBOWindow_H_
