#ifndef ecTexture_H_
#define ecTexture_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecTexture.h
/// @brief This class encapsulates the OpenGL calls necessary to create,
///        load, render, and delete 2D textures.  It also has support for
///        texture rectangles.  No support yet for 1D or 3D textures.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecTextureParameters.h"
#include <sensCore/ecImage.h>

class EC_SENSOR_RENDER_DECL EcTexture
{
public:
   EcTexture
      (
      );

   EcTexture
      (
      const EcTexture &orig
      );

   virtual ~EcTexture
      (
      );

   virtual EcTexture &operator=
      (
      const EcTexture &orig
      );

   virtual EcBoolean operator==
      (
      const EcTexture &orig
      ) const;

   // Default data orientation for files is TopToBottom
   virtual EcBoolean loadFromFile
      (
      const EcString& fileName,
      const EcTextureParameters &params = EcTextureParameters(),
      const EcImage::Orientation orient = EcImage::TopToBottom
      );

   // All loading is accomplished via this call.
   virtual EcBoolean loadFromImage
      (
      const EcImage &image,
      const EcTextureParameters &params = EcTextureParameters()
      );

   // Create placeholder texture on GPU.
   virtual EcBoolean loadShell
      (
      const EcU32 width,
      const EcU32 height,
      const EcTextureParameters &params
      );

   // Enable texturing and make current.
   virtual EcBoolean bind
      (
      ) const;

   // Unbinds the texture from its texture type
   virtual EcBoolean unbind
      (
      ) const;

   // Delete texture from GPU memory.
   virtual EcBoolean release
      (
      ) const;

   // Modify texture matrix if needed.
   virtual void scaleTexture
      (
      ) const;

   // Return normalized texture coordinates.  Modified by m_Orientation
   // to give the 4 corners of the texture starting from the origin.
   virtual void textureCoords
      (
      EcF32 *texFraction
      ) const;

   // Helper routine to draw a quadrilateral to the screen.
   virtual EcBoolean drawScreenAlignedQuad
      (
      const EcF32 posX,
      const EcF32 posY,
      const EcF32 width,
      const EcF32 height
      ) const;

   // Draw the quad with 2 textures.
   virtual EcBoolean drawMultiTextureScreenAlignedQuad
      (
      const EcTexture &tex,
      const EcF32 posX,
      const EcF32 posY,
      const EcF32 width,
      const EcF32 height
      ) const;

   // Mutators and accessors
   virtual GLuint id
      (
      ) const;

   virtual void setUnit
      (
      const GLuint unit
      ) const;

   virtual GLuint unit
      (
      ) const;

   virtual void setTextureParameters
      (
      const EcTextureParameters &params
      );

   virtual const EcTextureParameters &textureParameters
      (
      ) const;

   void setPerformFloatConversion
      (
      const EcBoolean convert
      );

   // Orientation dictates how the image is/will be stored in memory.
   EcImage::Orientation orientation
      (
      ) const;

   void setOrientation
      (
      const EcImage::Orientation orient
      );

   GLenum textureType
      (
      ) const;

   EcU32 width
      (
      ) const;

   EcU32 height
      (
      ) const;

protected:
   /// Determines whether the image is a POT or we can support in hardware.
   virtual EcBoolean calculatePOT
      (
      const EcU32 width,
      const EcU32 height
      );

   /// Internal routine for loading data onto the GPU
   virtual EcBoolean load
      (
      const EcU8 *data,
      const EcU32 sizeOfData
      );

   mutable GLuint      m_ID;   ///< OpenGL texture id
   mutable GLuint      m_Unit; ///< Texture unit

   /// Parameters used to configure texture.
   EcTextureParameters m_Params;

   /// Actual size of image in pixels.
   mutable EcU32       m_Width;
   mutable EcU32       m_Height;

   mutable EcBoolean   m_Reuse; ///< Whether to try and reuse existing texture

   /// Determine whether we need to scale the texture coordinates.
   EcBoolean           m_TextureScaling;
   // Flag dictating whether the incoming values should be loaded as float data.
   EcBoolean           m_PerformFloatConversion;

   /// Location and extent of image in texture memory
   mutable EcF32       m_TexCoords[4];

   /// How the texture is stored in texture memory.
   mutable EcImage::Orientation m_Orientation;
};

#endif // ecTexture_H_
