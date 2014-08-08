#ifndef ecImagePoint_H_
#define ecImagePoint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecImagePoint.h
/// @class EcImagePoint
/// @brief Holds a description of a point in an image.  Image and
///        image-like raster data is ordered such that image(x,y) has x
///        incrementing left to right and y incrementing top to bottom (i.e.,
///        [column,row]).  One unit equals one pixel.  Position (0,0) is
///        always in the upper left-hand corner.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declaration
class EcPixel;

/** Holds a description of a point in an image.  Image and image-like raster data is
 ordered such that image(x,y) has x incrementing left to right and y incrementing
 top to bottom (i.e., [column,row]).  One unit equals one pixel.  Position (0,0) is
 always in the upper left-hand corner.
*/
class EC_SENSOR_IMAGE_DECL EcImagePoint : public EcXmlCompoundType
{
public:
   /// default constructor
   EcImagePoint
      (
      );

   /// constructor giving an initial pixel location
   EcImagePoint
      (
      EcReal xx,
      EcReal yy
      );

   /// destructor
   virtual ~EcImagePoint
      (
      );

   /// copy constructor
   EcImagePoint
      (
      const EcImagePoint& orig
      );

   /// assignment operator
   EcImagePoint& operator=
      (
      const EcImagePoint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImagePoint& orig
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
   virtual EcReal x
      (
      ) const;

   /// set x (column from left)
   virtual void setX
      (
      EcReal value
      );

   /// get y (row from top)
   virtual EcReal y
      (
      ) const;

   /// set y (row from top)
   virtual void setY
      (
      EcReal value
      );

   /// set x and y (column from left, row from top)
   virtual void set
      (
      EcReal xx,
      EcReal yy
      );

   /// set to the upper-left corner of the pixel
   virtual void setToTopLeftCorner
      (
      const EcPixel& pixel
      );

   /// set to the lower-right corner of the pixel
   virtual void setToBottomRightCorner
      (
      const EcPixel& pixel
      );

   /// set to the center of the pixel
   virtual void setToCenter
      (
      const EcPixel& pixel
      );

   /// get the pixel containing this point
   virtual void getPixelContaining
      (
      EcPixel& pixel
      ) const;

   /// get the Euclidean distance to another image point
   virtual EcReal distanceTo
      (
      const EcImagePoint& other
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

   /// get a null object
   static EcImagePoint nullObject
      (
      );

protected:
   EcXmlReal m_X;    ///< X position
   EcXmlReal m_Y;    ///< Y position
};

/// A vector of image points
typedef EcXmlVectorType<EcImagePoint> EcImagePointVector;

#endif // ecImagePoint_H_
