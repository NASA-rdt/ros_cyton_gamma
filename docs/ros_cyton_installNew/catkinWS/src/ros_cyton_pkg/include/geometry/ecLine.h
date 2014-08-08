#ifndef ecLine_H_
#define ecLine_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecLine.h
/// @class EcLine
/// @brief Holds a class to describe a 3D line.  Using a point
///        on the line and a unit vector along the line.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

// forward declarations
class EcCoordinateSystemTransformation;

/// Holds a class to describe a 3D line.
class EC_FOUNDATION_GEOMETRY_DECL EcLine : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLine
      (
      );

   /// constructor from endpoints
   EcLine
      (
      const EcVector& point,
      const EcVector& unitVector
      );

   /// destructor
   virtual ~EcLine
      (
      );

   /// copy constructor
   EcLine
      (
      const EcLine& orig
      );

   /// assignment operator
   EcLine& operator=
      (
      const EcLine& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLine& orig
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

   /// set the point
   virtual void setPoint
      (
      const EcVector& point
      );

   /// get point
   virtual const EcVector& point
      (
      ) const;

   /// set unit vector
   virtual void setUnitVector
      (
      const EcVector& unitVector
      );

   /// get unit vector
   virtual const EcVector& unitVector
      (
      ) const;

   /// transform by a coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// get the distance squared from this line to a point
   virtual EcReal distanceSquaredFromLineTo
      (
      const EcVector& vec
      ) const;

   /// get the distance squared from this line to a point.
   /// This version also returns the t-value for the closest
   /// point.  The closest point equals point+tValue*unitVector.
   virtual EcReal distanceSquaredFromLineTo
      (
      const EcVector& vec,
      EcReal& tValue
      ) const;

   /// get the distance squared from this line to another.  This
   /// returns the t-values for both this and the other line.
   virtual EcReal distanceSquared
      (
      const EcLine& other,
      EcReal& thisTValue,
      EcReal& otherTValue
      ) const;

   /// find the point on the line closest to another point
   virtual EcVector pointOnLineClosestTo
      (
      const EcVector vec
      ) const;

   /// get token
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

   /// get an empty object
   static EcLine nullObject
      (
      );

protected:

   /// the point on the line
   EcXmlVector m_Point;

   /// the unit vector aligned with the line
   EcXmlVector m_UnitVector;
};

/// A vector of lines
typedef EcXmlVectorType<EcLine> EcLineVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the line in an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcLine operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcLine& m
   );

#endif // ecLine_H_
