#ifndef ecImageRectangle_H_
#define ecImageRectangle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageRectangle.h
/// @class EcImageRectangle
/// @brief Holds a description of a rectangle in an image.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImagePoint.h"
#include <xml/ecXmlCompType.h>

// forward declarations
class EcImageBlock;

/** Holds a description of a rectangle in an image.  Image and image-like raster data is
 ordered such that image(x,y) has x incrementing left to right and y incrementing
 top to bottom (i.e., [column,row]).  One unit equals one pixel.  Position (0,0) is
 always in the upper left-hand corner.
*/
class EC_SENSOR_IMAGE_DECL EcImageRectangle : public EcXmlCompoundType
{
public:
   /// default constructor
   EcImageRectangle
      (
      );

   /// constructor giving initial values
   EcImageRectangle
      (
      const EcImagePoint& topLeft,
      const EcImagePoint& bottomRight
      );

   /// destructor
   virtual ~EcImageRectangle
      (
      );

   /// copy constructor
   EcImageRectangle
      (
      const EcImageRectangle& orig
      );

   /// constructor from an image block
   EcImageRectangle
      (
      const EcImageBlock& block
      );

   /// assignment operator
   EcImageRectangle& operator=
      (
      const EcImageRectangle& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImageRectangle& orig
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

   /// get top left image point
   virtual const EcImagePoint& topLeft
      (
      ) const;

   /// set top left image point
   virtual void setTopLeft
      (
      const EcImagePoint& topLeft
      );

   /// get bottom right image point
   virtual const EcImagePoint& bottomRight
      (
      ) const;

   /// set bottom right image point
   virtual void setBottomRight
      (
      const EcImagePoint& bottomRight
      );

   /// set from image points
   virtual void set
      (
      EcImagePoint topLeft,
      EcImagePoint bottomRight
      );

   /// get the rectangle width
   virtual EcReal width
      (
      ) const;

   /// get the rectangle height
   virtual EcReal height
      (
      ) const;

   /// calculate the overlap area between this and a pixel
   virtual EcReal overlapWith
      (
      const EcPixel& pixel
      );

   /// expand this rectangle to include another
   virtual void expandSelfToInclude
      (
      const EcImageRectangle& other
      );

   /// scale the rectangle by the given value, keeping the
   /// centroid the same
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      );

   /// calculate the area of the rectangle
   virtual EcReal area
      (
      ) const;

   /// see if this rectangle contains an image point
   /// returns true if the point is inside
   virtual EcBoolean contains
      (
      const EcImagePoint& point
      ) const;

   /// calculate the distance to an image point
   virtual EcReal distanceTo
      (
      const EcImagePoint& imagePoint
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
   static EcImageRectangle nullObject
      (
      );

protected:
   EcImagePoint m_TopLeft;       ///< top left corner
   EcImagePoint m_BottomRight;   ///< bottom right corner
};

#endif // ecImageRectangle_H_
