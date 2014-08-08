#ifndef ecPixel_H_
#define ecPixel_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPixel.h
/// @class EcPixel
/// @brief Holds a description of a pixel location.  Image and
///        image-like raster data is ordered such that image(x,y) has x
///        incrementing left to right and y incrementing top to bottom
///        (i.e., [column,row]).  Position (0,0) is always in the upper
///        left-hand corner.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of a pixel location.
/** Image and image-like raster data is
 ordered such that image(x,y) has x incrementing left to right and y incrementing
 top to bottom (i.e., [column,row]).  Position (0,0) is always in the upper
 left-hand corner.
*/
class EC_SENSOR_IMAGE_DECL EcPixel : public EcXmlCompoundType
{
public:
   /// pixel location enumeration.
   /// a pixel can only be of one type
   /// for pixel-thin images, pixels take on the TOP- or LEFT-associated values
   /// for single-pixel images the one pixel is defined as TOP_LEFT
   enum {TOP_RIGHT,
         TOP_LEFT,
         BOTTOM_LEFT,
         BOTTOM_RIGHT,
         RIGHT,
         TOP,
         LEFT,
         BOTTOM,
         CENTRAL,
         OUTSIDE};

   /// default constructor
   EcPixel
      (
      );

   /// constructor giving an initial pixel location
   EcPixel
      (
      EcU32 xx,
      EcU32 yy
      );

   /// destructor
   virtual ~EcPixel
      (
      );

   /// copy constructor
   EcPixel
      (
      const EcPixel& orig
      );

   /// assignment operator
   EcPixel& operator=
      (
      const EcPixel& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPixel& orig
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

   /// get x (column from left)
   virtual EcU32 x
      (
      ) const;

   /// set x (column from left)
   virtual void setX
      (
      EcU32 value
      );

   /// get y (row from top)
   virtual EcU32 y
      (
      ) const;

   /// set y (row from top)
   virtual void setY
      (
      EcU32 value
      );

   /// set x and y (column from left, row from top)
   virtual void set
      (
      EcU32 xx,
      EcU32 yy
      );

   /// get/set by index
   virtual EcU32& operator[]
      (
      EcU32 index
      );

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
   static EcPixel nullObject
      (
      );

   /// distance to
   virtual EcReal distanceTo
      (
      const EcPixel& p2
      ) const;

protected:
   EcXmlU32  m_X;    ///< x position (left-to-right)
   EcXmlU32  m_Y;    ///< y position (top-to-bottom)
};

/// A vector of pixels
typedef EcXmlVectorType<EcPixel> EcPixelVector;

typedef EcXmlVectorType<EcPixelVector> EcPixelVectorVector;

typedef EcXmlVectorType<EcPixelVectorVector> EcPixelVector3D;


#endif // ecPixel_H_
