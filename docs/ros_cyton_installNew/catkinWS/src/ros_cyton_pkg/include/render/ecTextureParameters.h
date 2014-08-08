#ifndef ecTextureParameters_H_
#define ecTextureParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecTextureParameters.h
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecGL.h"

class EcImage;

class EC_SENSOR_RENDER_DECL EcTextureParameters //: public EcXmlCompoundType
{
public:
   /// Internal representation of data.  Dictates how many components are
   /// used as well as pixel packing.
   enum PixelFormat
   {
      UnknownPF   = 0,
      GreyScale   = GL_LUMINANCE,
      GreyAlpha   = GL_LUMINANCE_ALPHA,
      RGB         = GL_RGB,
      RGBA        = GL_RGBA,
      /// Requires OpenGL 1.2
      BGRA        = GL_BGRA,
      /// These formats require GL_ARB_texture_float
      Float16Grey = GL_LUMINANCE16F_ARB,
      Float32Grey = GL_LUMINANCE32F_ARB,
      Float16RGB  = GL_RGB16F_ARB,
      Float16RGBA = GL_RGBA16F_ARB,
      Float32RGB  = GL_RGB32F_ARB,
      Float32RGBA = GL_RGBA32F_ARB,
      /// These formats require GL_NV_float_buffer
      FloatNV16Grey = GL_FLOAT_R16_NV,
      FloatNV32Grey = GL_FLOAT_R32_NV,
      FloatNV16RGB  = GL_FLOAT_RGB16_NV,
      FloatNV16RGBA = GL_FLOAT_RGBA16_NV,
      FloatNV32RGB  = GL_FLOAT_RGB32_NV,
      FloatNV32RGBA = GL_FLOAT_RGBA32_NV,
      /// These formats require GL_EXT_texture_integer
      GreyScaleInt    = GL_LUMINANCE_INTEGER_EXT,
      GreyAlphaInt    = GL_LUMINANCE_ALPHA_INTEGER_EXT,
      RGBInt          = GL_RGB_INTEGER_EXT,
      RGBAInt         = GL_RGBA_INTEGER_EXT,
      BGRInt          = GL_BGR_INTEGER_EXT,
      BGRAInt         = GL_BGRA_INTEGER_EXT,
      Int16Grey       = GL_LUMINANCE16I_EXT,
      Int32Grey       = GL_LUMINANCE32I_EXT,
      Int16GreyAlpha  = GL_LUMINANCE_ALPHA16I_EXT,
      Int32GreyAlpha  = GL_LUMINANCE_ALPHA32I_EXT,
      Int8RGB         = GL_RGB8I_EXT,
      Int8RGBA        = GL_RGBA8I_EXT,
      Int16RGB        = GL_RGB16I_EXT,
      Int16RGBA       = GL_RGBA16I_EXT,
      Int32RGB        = GL_RGB32I_EXT,
      Int32RGBA       = GL_RGBA32I_EXT,

      UInt16Grey      = GL_LUMINANCE16UI_EXT,
      UInt32Grey      = GL_LUMINANCE32UI_EXT,
      UInt16GreyAlpha = GL_LUMINANCE_ALPHA16UI_EXT,
      UInt32GreyAlpha = GL_LUMINANCE_ALPHA32UI_EXT,
      UInt8RGB        = GL_RGB8UI_EXT,
      UInt8RGBA       = GL_RGBA8UI_EXT,
      UInt16RGB       = GL_RGB16UI_EXT,
      UInt16RGBA      = GL_RGBA16UI_EXT,
      UInt32RGB       = GL_RGB32UI_EXT,
      UInt32RGBA      = GL_RGBA32UI_EXT,
      /// These formats require GL_ARB_depth_texture
      DepthFormat   = GL_DEPTH_COMPONENT,
      Depth16       = GL_DEPTH_COMPONENT16_ARB,
      Depth24       = GL_DEPTH_COMPONENT24_ARB,
      Depth32       = GL_DEPTH_COMPONENT32_ARB
   };

   /// External representation of texel data.
   enum DataFormat
   {
      UnknownDF   = 0,
      Unsigned8   = GL_UNSIGNED_BYTE,
      Signed8     = GL_BYTE,
      Unsigned16  = GL_UNSIGNED_SHORT,
      Signed16    = GL_SHORT,
      Float16     = GL_HALF_FLOAT_ARB, // requires GL_ARB_half_float_pixel
      Unsigned32  = GL_UNSIGNED_INT,
      Signed32    = GL_INT,
      Float32     = GL_FLOAT,
   };

   /// Default constructor
   EcTextureParameters
      (
      );

   /// Use the input image to specify parameters.
   // \param[in] image EcImage object to configure parameters from.
   EcTextureParameters
      (
      const EcImage &image
      );

   /// Copy constructor
   EcTextureParameters
      (
      const EcTextureParameters &orig
      );

   virtual ~EcTextureParameters
      (
      );

   /// Assignment
   EcTextureParameters & operator=
      (
      const EcTextureParameters &orig
      );

   /// Equality
   EcBoolean operator==
      (
      const EcTextureParameters &orig
      ) const;

   /// Process instance and generate calculated values.
   void getFormatFromImage
      (
      const EcImage &image
      );

   EcBoolean ApplyParameters
      (
      ) const;

   PixelFormat internalFormat
      (
      ) const;

   void setInternalFormat
      (
      const PixelFormat iFormat
      );

   void setTextureType
      (
      const GLenum type
      );

   GLenum textureType
      (
      ) const;

   GLenum requestedTextureType
      (
      ) const;

   DataFormat dataFormat
      (
      ) const;

   void setPixelFormat
      (
      const EcU32 numComponents
      );

   void setPixelFormat
      (
      const PixelFormat pFormat
      );

   PixelFormat pixelFormat
      (
      ) const;

   EcBoolean isFloatType
      (
      ) const;

   /// Check whether internal integer representation is being used.
   EcBoolean isIntegerType
      (
      ) const;

   /// Mutator and Accessor methods
   void setApplyType
      (
      const GLenum apply
      );

   GLenum applyType
      (
      ) const;

   void setWrapType
      (
      const GLenum wrap
      );

   GLenum wrapType
      (
      ) const;

   void setMinFilterType
      (
      const GLenum min
      );

   GLenum minFilterType
      (
      ) const;

   void setMagFilterType
      (
      const GLenum mag
      );

   GLenum magFilterType
      (
      ) const;

protected:
   /// Size of component values
   DataFormat    m_DataFormat;
   /// Number of component values
   PixelFormat   m_PixelFormat;
   /// How the data is stored in texture memory
   PixelFormat   m_InternalFormat;
   /// How to apply texture to surface.
   GLenum        m_ApplyType;
   /// Wrapping method same in both dimensions.
   GLenum        m_WrapType;
   /// Minification filter
   GLenum        m_MinFilterType;
   /// Magnification filter
   GLenum        m_MagFilterType;
   /// Texture specification type - 2D or TEXTURE_RECTANGLE
   GLenum        m_TextureType;
   /// Override for which texture type to use.
   GLenum        m_RequestedTextureType;
   /// Flag indicating if we are using a float format and support it in hardware.
   mutable EcBoolean m_IsFloat;
   /// Flag indicating if we are using an integer internal format and support it in hardware.
   mutable EcBoolean m_IsInteger;
};

#endif // ecTextureParameters_H_
