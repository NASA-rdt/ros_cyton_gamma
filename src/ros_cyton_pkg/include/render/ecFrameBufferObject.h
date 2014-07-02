#ifndef ecFrameBufferObject_H_
#define ecFrameBufferObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameBufferObject.h
/// @brief Encapsulation of OpenGL Frame Buffer Object (FBO) that allows
///        for off-screen rendering.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecGL.h"

class EcTexture;
class EcTextureParameters;

class EC_SENSOR_RENDER_DECL EcFrameBufferObject
{
public:
   enum FBOType
   {
      COLOR = GL_COLOR_ATTACHMENT0_EXT,
      DEPTH = GL_DEPTH_ATTACHMENT_EXT,
      COLOR_DEPTH = 1
   };

   EcFrameBufferObject
      (
      );

   virtual ~EcFrameBufferObject
      (
      );

   /// Make sure that extensions are available.
   virtual EcBoolean init
      (
      const EcTexture &tex,
      const FBOType type = COLOR,
      const EcU32 id = 0
      );

   virtual EcBoolean isValid
      (
      ) const;

   /// Convenience method for isValid()
   EcBoolean operator!
      (
      ) const;

   virtual EcBoolean attach
      (
      const EcTexture &tex,
      const EcU32 id = 0
      ) const;

   virtual EcBoolean detach
      (
      const EcTexture &tex,
      const EcU32 id = 0
      ) const;

   virtual void bind
      (
      ) const;

   /// Turn off off-screen rendering.
   static void unbind
      (
      );

protected:
   GLuint m_FrameBufferID;
   GLuint m_DepthBufferID;
   GLuint m_Width;
   GLuint m_Height;

   /// Flag to verify extension support.
   EcBoolean m_Initialized;
};

#endif // ecFrameBufferObject_H_
