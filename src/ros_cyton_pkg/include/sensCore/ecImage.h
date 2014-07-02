#ifndef ecImage_H_
#define ecImage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecImage.h
/// @class EcImage
/// @brief Holds a description of raster data.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecSensorData.h"
#include <xml/ecXmlVectorType.h>

//forward declarations
class EcImageBlock;
class EcImagePoint;
class EcImageRectangle;
class EcPixel;

/** Holds a description of raster data.  Image and image-like raster data is
 ordered such that image(x,y) has x incrementing left to right and y incrementing
 top to bottom (i.e., [column,row]).  Position (0,0) is always in the upper
 left-hand corner.
*/
class EC_SENSOR_IMAGE_DECL EcImage : public EcSensorData
{
public:
   // Internal representation of image layout.  This parameter affects how
   // the data will be stored on the hardware.
   enum Orientation
   {
      BottomToTop,
      TopToBottom
   };

   ECXMLOBJECT(EcImage);

   /// constructor giving a zero image
   /// freed when it is no longer used.
   EcImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 imageWidth,
      EcU32 imageHeight
      );

   /// constructor to create a EcImage handle from existing data
   EcImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 imageWidth,
      EcU32 imageHeight,
      EcU8* data
      );

   using EcSensorData::copyDataFrom;
   /// copies data from the other without reference counting
   virtual void copyDataFrom
      (
      const EcImage& orig
      );

   /// subtraction
   virtual EcBoolean subtract
      (
      const EcImage& other,
      EcImage& rslt
      ) const;

   /// element-wise max operator
   virtual EcBoolean max
      (
      const EcImage& img1,
      const EcImage& img2
      );

   /// element-wise min operator
   virtual EcBoolean min
      (
      const EcImage& img1,
      const EcImage& img2
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// determine if two EcImages are approximately equal
   virtual EcBoolean approxEq
      (
      const EcImage& other,
      EcReal tolerance
      ) const;

   /// init the image to the size specified with initial value.
   virtual EcBoolean initImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 width,
      EcU32 height,
      EcU8  initValue
      );

   /// zero the image to the size specified.
   virtual EcBoolean zeroImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 width,
      EcU32 height
      );

   /// init the image through the flipped pointer
   /// to the size specified with initial value.
   EcBoolean initFlippedImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 width,
      EcU32 height,
      EcU8  initValue
      );

   /// zero the image through the flipped pointer
   /// to the size specified.
   EcBoolean zeroFlippedImage
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 width,
      EcU32 height
      );

   /// override parent's zero method to properly
   /// set the height and width parameters to give a
   /// wide, single-pixel-tall image.
   virtual EcBoolean zero
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 numValues
      );

   /// have to also redefine parent's  method
   /// just set the image in place to initvalue.
   virtual EcBoolean setTo
      (
      EcU8 initValue
      );

   /// have to also redefine parent's zero() method
   /// just zeros the image in place.
   virtual EcBoolean zero
      (
      );

   /// convert the image to three-channel RGB by any means necessary
   virtual void convertSelfToRGB
      (
      );

   /// set with width and height.
   virtual EcBoolean setImage
      (
      const EcU8Vector& vMultibytes,
      const EcU8Vector& vSubbytes,
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 imageWidth,
      EcU32 imageHeight
      );

   /// override parent's set method to properly
   /// set the height and width parameters to give a
   /// wide, single-pixel-tall image.
   virtual EcBoolean set
      (
      const EcU8Vector& vMultibytes,
      const EcU8Vector& vSubbytes,
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 numValues
      );

   using EcSensorData::multibyteValue;
   /// get a multibyte value
   virtual EcU8 multibyteValue
      (
      EcU32 columnIndex,
      EcU32 rowIndex,
      EcU32 byteIndex
      ) const;

   /// get a multibyte value
   virtual EcU8 multibyteValue
      (
      const EcPixel& pixel,
      EcU32 byteIndex
      ) const;

   using EcSensorData::setMultibyteValue;
   /// set a multibyte value from indices
   virtual EcBoolean setMultibyteValue
      (
      EcU32 columnIndex,
      EcU32 rowIndex,
      EcU32 byteIndex,
      EcU8 value
      );

   /// set a multibyte value from pixel descriptor
   virtual EcBoolean setMultibyteValue
      (
      const EcPixel& pixel,
      EcU32 byteIndex,
      EcU8 value
      );

   /// set multiple multibyte value from pixel descriptor
   virtual EcBoolean setMultibyteValues
      (
      const EcPixel& pixel,
      const EcU8Vector& values
      );

   /// set a 3 byte value
   virtual EcBoolean set3ByteValue
	   (
	   const EcU32& column,
	   const EcU32& row,
	   const EcU8&	red,
	   const EcU8&	green,
	   const EcU8&	blue
	   );

   using EcSensorData::subbyteBit;
   /// get a subbyte bit
   virtual EcBoolean subbyteBit
      (
      EcU32 columnIndex,
      EcU32 rowIndex,
      EcU32 bitIndex
      ) const;

   /// get a subbyte bit
   virtual EcBoolean subbyteBit
      (
      const EcPixel& pixel,
      EcU32 bitIndex
      ) const;

   using EcSensorData::setSubbyteBit;
   /// set a subbyte bit
   virtual EcBoolean setSubbyteBit
      (
      EcU32 columnIndex,
      EcU32 rowIndex,
      EcU32 bitIndex,
      EcBoolean value
      );

   /// set a subbyte bit
   virtual EcBoolean setSubbyteBit
      (
      const EcPixel& pixel,
      EcU32 bitIndex,
      EcBoolean value
      );

   /// gets the image width
   virtual EcU32 imageWidth
      (
      ) const;

   /// gets the image height
   virtual EcU32 imageHeight
      (
      ) const;

   /// gets the comment string
   virtual const EcString& comments
      (
      ) const;

   /// sets the comment string
   virtual void setComments
      (
      const EcString& comments
      );

   /// gets the value groups
   virtual const EcXmlU32Vector& valueGroups
      (
      ) const;

   /// sets the value groups
   virtual void setValueGroups
      (
      const EcXmlU32Vector& valueGroups
      );

   /// gets a pointer to the multibyte data - const
   /// use with great caution.
   virtual const EcU8* multibytePointer
      (
      ) const;

   /// gets a pointer to the multibyte data - nonconst
   /// use with great caution.
   virtual EcU8* multibytePointer
      (
      );

   /// check to see if a pixel is inside the image
   virtual EcBoolean containsPixel
      (
      const EcPixel& pixel
      ) const;

   /// check to see if an image point is inside the image
   virtual EcBoolean containsImagePoint
      (
      const EcImagePoint& imagePoint
      ) const;

   /// check to see if a block is inside the image
   virtual EcBoolean containsBlock
      (
      const EcImageBlock& block
      ) const;

   /// check to see if a rectangle is inside the image
   virtual EcBoolean containsRectangle
      (
      const EcImageRectangle& rectangle
      ) const;

   /// gets the number of values.  Overridden here to return image
   /// height times image width.
   virtual EcU32 numValues
      (
      ) const;

   /// gets the number of channel values in the image.  This equals
   /// the number of values times the number of multibyes
   /// per value.
   virtual EcU32 numChannelValues
      (
      ) const;

   /// gets the pixel type
   virtual EcU32 pixelType
      (
      const EcPixel& pixel
      ) const;

   /// extract a subimage
   virtual EcBoolean getSubimage
      (
      const EcImageBlock& block,
      EcImage& subimage
      ) const;

   /// insert a subimage with upper-left corner as specified
   virtual EcBoolean setSubimage
      (
      const EcPixel& topLeft,
      const EcImage& subimage
      );

   /// inserts an EcImage into this image starting at the
   /// upper-left hand point specified
   virtual EcBoolean insertImage
      (
      EcImage &image,
      const EcPixel &upperLeft
      );

   /// copy data from one area to the other, flipping vertically in the process.
   virtual EcBoolean copyFromOrToFlipped
      (
      const EcBoolean fromFlipped = EcTrue
      );

   /// Copy from flipped buffer if needed.
   virtual EcBoolean copyFromFlippedIfNeeded
      (
      ) const;

   /// get m_pFlippedData
   virtual EcU8* flippedMultibytePointer
      (
      );

   /// get m_pFlippedData as a const pointer
   virtual const EcU8* flippedMultibytePointer
      (
      ) const;

   /// accessor to need-to-copy flag
   virtual EcBoolean needToCopyFromFlipped
      (
      ) const;


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

   /// return image with pixels greater than a threshold
   virtual EcBoolean greaterThan
      (
      const EcU8& thresh,
      const EcU32& channel,
      EcImage& rslt
      )const;

   /// return image with pixels less than a threshold
   virtual EcBoolean lessThan
      (
      const EcU8& thresh,
      const EcU32& channel,
      EcImage& rslt
      )const;
protected:
   /// get the number of columns for printing
   virtual EcU32 numColumns
      (
      ) const;

   /// copy the content of one multibyte array into another
   virtual EcBoolean copyContent
      (
      const EcU8* source,
      EcU8*& dest,
      EcU32* pSize = 0
      );

   /// image width
   EcXmlU32       m_ImageWidth;

   /// image height
   EcXmlU32       m_ImageHeight;

   /// comments
   EcXmlString    m_Comments;

   /// grouping
   EcXmlU32Vector m_ValueGroups;

   /// a pointer to the flipped multibytes
   EcU8*          m_pFlippedMultibytes;

   /// a flag indicating whether or not the normal bytes are valid
   EcBoolean      m_NeedToCopyFromFlipped;

   /// The number of allocated flipped multibytes
   EcU32          m_AllocatedFlippedMultibytes;
};

/// A vector of images
typedef EcXmlVectorType<EcImage> EcImageVector;

#endif // ecImage_H_
