#ifndef ecImageBlock_H_
#define ecImageBlock_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageBlock.h
/// @class EcImageBlock
/// @brief Holds a description of a discrete block of pixels in
///        an image.  Image and image-like raster data is ordered such that
///        image(x,y) has x incrementing left to right and y incrementing top
///        to bottom (i.e., [column,row]).  Position (0,0) is always in the
///        upper left-hand corner.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecPixel.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of a discrete block of pixels in an image.
/** Image and image-like
 raster data is ordered such that image(x,y) has x incrementing left to right and y
 incrementing top to bottom (i.e., [column,row]).  Position (0,0) is
 always in the upper left-hand corner.
*/
class EC_SENSOR_IMAGE_DECL EcImageBlock : public EcXmlCompoundType
{
public:
   /// default constructor
   EcImageBlock
      (
      );

   /// constructor giving initial values
   EcImageBlock
      (
      const EcPixel& topLeft,
      const EcPixel& bottomRight
      );

   /// destructor
   virtual ~EcImageBlock
      (
      );

   /// copy constructor
   EcImageBlock
      (
      const EcImageBlock& orig
      );

   /// assignment operator
   EcImageBlock& operator=
      (
      const EcImageBlock& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImageBlock& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
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

   /// get top left pixel
   virtual const EcPixel& topLeft
      (
      ) const;

   /// set top left pixel
   virtual void setTopLeft
      (
      const EcPixel& topLeft
      );

   /// get bottom right pixel
   virtual const EcPixel& bottomRight
      (
      ) const;

   /// set bottom right pixel
   virtual void setBottomRight
      (
      const EcPixel& bottomRight
      );

   /// set from pixels
   virtual void set
      (
      EcPixel topLeft,
      EcPixel bottomRight
      );

   /// get the block width
   virtual EcU32 width
      (
      ) const;

   /// get the block height
   virtual EcU32 height
      (
      ) const;

   /// expand this block to include another
   virtual void expandSelfToInclude
      (
      const EcImageBlock& other
      );

   /// calculate the area of the block
   virtual EcU32 area
      (
      )const;

   /// see if this block contains a pixel
   /// returns true if the pixel is inside
   virtual EcBoolean contains
      (
      const EcPixel& pixel
      ) const;

   virtual const EcToken& token
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

   /// read this object from a binary stream
   virtual EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   virtual EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// get a null object
   static EcImageBlock nullObject
      (
      );

protected:
   EcPixel m_TopLeft;         ///< top left pixel
   EcPixel m_BottomRight;     ///< bottom right pixel
};

/// A vector of image blocks
typedef EcXmlVectorType<EcImageBlock> EcImageBlockVector;

#endif // ecImageBlock_H_
