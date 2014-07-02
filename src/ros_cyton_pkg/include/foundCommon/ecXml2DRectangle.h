#ifndef ecXml2DRectangle_H_
#define ecXml2DRectangle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DRectangle.h
/// @class EcXml2DRectangle
/// @brief implementation of the EcXml2DRectangle class;
/// @todo remove rectanglePosition()
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

#include <foundCommon/ecXml2DShape.h>


/*!
\class EcXml2DRectangle
\brief EcXml2DRectangle - defines 2D rectangle
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DRectangle : public EcXml2DShape
{
public:


   /// Constructor
   EcXml2DRectangle
      (
      );

   /// Constructor
   EcXml2DRectangle
      (
      EcReal centreX,
      EcReal centreY,
      EcReal length,
      EcReal width
      );

   /// Destructor
   virtual ~EcXml2DRectangle
      (
      );

   /// Copy constructor
   EcXml2DRectangle
      (
      const EcXml2DRectangle& orig
      );

   /// Copy assignment operator
   EcXml2DRectangle& operator=
      (
      const EcXml2DRectangle& orig
      );

   /// Equality operator
   EcBoolean operator==
      (
      const EcXml2DRectangle& orig
      ) const;

   /// Clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// Register components with the parent
   virtual void registerComponents
      (
      );

   /// Equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// Virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// Return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// returns id for the shape
   virtual const EcString id
      (
      )const;

   /// copies the data into the newData
   virtual void copyData
      (
      EcXml2DShape* newData
      );


   /// Get the X coordinate of the rectangle  center (pixels)
   EcReal centerX
      (
      ) const;

   /// Set the X coordinate of the rectangle  center (pixels)
   void setCenterX
      (
      EcReal x
      );

   /// Get the Y coordinate of the rectangle  center (pixels)
   EcReal centerY
      (
      ) const;

   /// Set the Y coordinate of the rectangle  center (pixels)
   void setCenterY
      (
      EcReal y
      );

   /// Get the length (major axis) of the rectangle (pixels)
   EcReal length
      (
      ) const;

   /// Set the length (major axis) of the rectangle (pixels)
   void setLength
      (
      EcReal l
      );

   /// Get the width (minor axis) of the rectangle (pixels)
   EcReal width
      (
      ) const;

   /// Set the width (minor axis) of the rectangle (pixels)
   void setWidth
      (
      EcReal w
      );

   /// Get the counter-clockwise (CCW) rotation angle of the rectangle (radians)
   EcReal rotation
      (
      ) const;

   /// Set the counter-clockwise (CCW) rotation angle of the rectangle (radians)
   void setRotation
      (
      EcReal r
      );

   /// sets bit flag for rectangle item
   void setBitFlags
      (
      EcU32 flags
      );

   /// returns the bit flag that defines the properties of the rectangle item
   EcU32 bitFlags
      (
      ) const;

   /// merges the this rectangle and given rectangle d
   void merge
      (
      const EcXml2DRectangle& d
      );

   /// returns true or face based on given point is inside the shape or not
   EcBoolean contains
      (
      EcReal x,
      EcReal y
      );

   /// returns a copy of this rectangle
   EcXml2DRectangle rectanglePosition
      (
      );

protected:
   EcXmlReal m_CenterX;  ///< X coordinate of the rectangle center (pixels)
   EcXmlReal m_CenterY;  ///< Y Coordinate of the rectangle center (pixels)
   EcXmlReal m_Length;   ///< Length (major axis) of the rectangle (pixels)
   EcXmlReal m_Width;    ///< Width (minor axis) of the rectangle (pixels)
   EcXmlReal m_Rotation; ///< Counter-clockwise rotation angle of the rectangle (radians)
   EcXmlU32  m_BitFlags; ///< Arbitrary bitflags to delineate different  classes
};

#endif // EcXmlRectangularItem_H_
