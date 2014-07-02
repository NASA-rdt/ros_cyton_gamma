#ifndef ecTextRenderingTool_H_
#define ecTextRenderingTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecTextRenderingTool.h
/// @class EcTextRenderingTool
/// @brief A class for rendering text onto an EcImage.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImagePoint.h"
#include <xml/ecXmlCompType.h>

class EcImage;
class EcTextDescriptor;

/// Provide forward declarations of Freetype types to limit header proliferation
struct FT_FaceRec_;
typedef FT_FaceRec_* FT_Face;

struct FT_LibraryRec_;
typedef FT_LibraryRec_* FT_Library;

struct FT_Bitmap_;
typedef FT_Bitmap_ FT_Bitmap;


class EC_SENSOR_SENSCORE_DECL EcTextRenderingTool
{
public:
   /// supported fonts
   enum FontTypeEnum
   {
      TIMES_NEW_ROMAN,
      ARIAL,
#if defined(WIN32) || defined(__APPLE__)
      ARIALNB,
#endif
      COURIER,
      TAHOMA,
      FONT_LIST_LENGTH,
   };
   typedef EcU32 EcFontType;

   /// default constructor
   EcTextRenderingTool
      (
      );

   /// destructor
   virtual ~EcTextRenderingTool
      (
      );

   /// copy constructor
   EcTextRenderingTool
      (
      const EcTextRenderingTool& orig
      );

   /// add text to the EcImage
   /// @param[in] textBox (EcTextDescriptor&) text to be rendered
   /// @param[in] image (EcImage&) rendering image
   /// @return The rendering status
   virtual EcBoolean addText
      (
      const EcTextDescriptor& textBox,
      EcImage& image
      ) const;

   /// assignment operator
   EcTextRenderingTool& operator=
      (
      const EcTextRenderingTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTextRenderingTool& orig
      ) const;

protected:
   /// Release the loaded font map
   void unloadFontMap
      (
      ) const;

   /// load the font map
   /// @param[in] font (EcFontType) The font of the character to be rendered.
   EcBoolean loadFontMap
      (
      const EcFontType font
      ) const;

   /// set the size of the character to be rendered
   /// @param[in] charSz (EcPixel) The character size to be rendered
   /// @return The rendering status
   EcBoolean setFontCharacterSize
      (
      const EcPixel& charSz
      ) const;

   /// inserts the character pixel map onto the image
   /// @param[in] bitmap (FT_Bitmap*) The bitmap on which the character is rendered
   /// @param[in] currentCharPosition (EcPixel&) position of the character on the original image
   /// @param[out] image (EcImage&) output image on which the character is rendered
   /// @param[in] character (EcU8) The character which is to be renderd
   void insertPixmap
      (
      const FT_Bitmap* bitmap,
      const EcPixel& currentCharPosition,
      const EcU8 character,
      EcImage& image
      ) const;

   mutable FT_Library m_pRenderingEngine; ///< The Freetype rendering library
   mutable FT_Face    m_pFontFace; ///< The character font type
   static const EcString m_SystemFontPath; ///< the system level font path
   static const EcString m_TheFontNameTable[FONT_LIST_LENGTH]; ///< the default font path
};

#endif // ecTextRenderingTool_H_
