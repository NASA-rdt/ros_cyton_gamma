#ifndef ecEncodedImage_H_
#define ecEncodedImage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecEncodedImage.h
/// @class EcEncodedImage
/// @brief Holds a description of encoded raster data (using Base64 encoding)
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImage.h"
#include <xml/ecXmlEnumType.h>

/// Holds a description of encoded raster data.
class EC_SENSOR_SENSCORE_DECL EcEncodedImage : public EcImage
{
public:
   /// options for image format
   enum IMAGE_FORMAT
   {
      BMP,                ///< Bitmap
      JPEG_COMP           ///< Compressed JPEG
   };

   /// default constructor
   EcEncodedImage
      (
      );

   /// constructor giving a zero image
   /// freed when it is no longer used.
   EcEncodedImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 imageWidth,
      EcU32 imageHeight
      );

   /// destructor
   virtual ~EcEncodedImage
      (
      );

   /// copy constructor
   EcEncodedImage
      (
      const EcEncodedImage& orig
      );

   /// assignment operator
   EcEncodedImage& operator=
      (
      const EcEncodedImage& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEncodedImage& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components
   virtual void registerComponents
      (
      );

   /// register enumerations
   virtual void registerEnumerations
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// encode image
   /**
      \param format image file format
   */
   virtual EcBoolean encodeImage
      (
      const IMAGE_FORMAT format
      );

   /// decode image
   virtual EcBoolean decodeImage
      (
      );

   /// encode BMP image
   virtual EcBoolean encodeBmp
      (
      );

   /// decode BMP image
   virtual EcBoolean decodeBmp
      (
      );

   /// encode compressed JPEG image
   virtual EcBoolean encodeJpegComp
      (
      );

   /// decode compressed JPEG image
   virtual EcBoolean decodeJpegComp
      (
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write this object to an XML schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// read the value from an unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// get a null object
   static EcEncodedImage nullObject
      (
      );

protected:
   virtual EcBoolean readBmpBase
      (
      std::istream &ifs
      );

   virtual EcBoolean writeBmpBase
      (
      std::ostream &ifs
      ) const;

   /// encoded data
   EcXmlString  m_EncodedImage;

   /// option for image format
   EcXmlEnumU16 m_ImageFormat;

   /// Internal string used during encoding/decoding. Its only
   /// a member variable so the dynamic memory can be reused.
   EcString m_CodingString;
};

#endif // ecEncodedImage_H_
