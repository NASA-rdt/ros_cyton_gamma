#ifndef ecCircularLozenge_H_
#define ecCircularLozenge_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecCircularLozenge.h
/// @class EcCircularLozenge
/// @brief Holds a class to describe a 3D circular lozenge (fixed
///        distance from a filled 3D circle).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecCircle.h"
#include "ecShape.h"
#include <xml/ecXmlVector.h>

class EcAxisAlignedBoundingBox;
class EcBasePhysicalExtent;

/// Holds a class to describe a 3D circular lozenge (fixed distance from
/// a filled 3D circle).
class EC_FOUNDATION_GEOMETRY_DECL EcCircularLozenge : public EcShape
{
public:
   /// default constructor
   /// Creates a circular lozenge with a radius of 0.1 unit
   EcCircularLozenge
      (
      );

   /// constructor from a line segment and a radius
   EcCircularLozenge
      (
      const EcCircle circle,
      EcReal radius
      );

   /// destructor
   virtual ~EcCircularLozenge
      (
      );

   /// copy constructor
   EcCircularLozenge
      (
      const EcCircularLozenge& orig
      );

   /// assignment operator
   EcCircularLozenge& operator=
      (
      const EcCircularLozenge& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCircularLozenge& orig
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

   /// get defining circle
   virtual const EcCircle& circle
      (
      ) const;

   /// set defining circle
   virtual void setCircle
      (
      const EcCircle& circle
      );

   /// get circle radius
   virtual EcReal circleRadius
      (
      ) const;

   /// set circle radius
   virtual void setCircleRadius
      (
      EcReal circleRadius
      );

   /// get normal vector
   virtual const EcVector& normal
      (
      ) const;

   /// set normal vector
   virtual void setNormal
      (
      const EcVector& normal
      );

   /// get center vector
   virtual const EcVector& center
      (
      ) const;

   /// set normal vector
   virtual void setCenter
      (
      const EcVector& center
      );

   /// get radius
   virtual EcReal radius
      (
      ) const;

   /// set radius
   virtual void setRadius
      (
      EcReal radius
      );

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
      const EcXmlVectorVector& points
      );

   /// scale the object by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      );

   /// transform the shape by the given coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// get the distance to a line segment
   /// returns zero if they are just touching and a
   /// negative number if they overlap.
   virtual EcReal distanceTo
      (
      const EcLineSegment& lineSeg
      ) const;

   /// get the distance to a point
   /// returns zero if the point is on the surface of the
   /// capsule and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /**
   \copydoc EcShape::intersectLineSegment()
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// check the intersection with line segment
   virtual EcBoolean checkIntersect
      (
      const EcLineSegment& lineSegment
      ) const;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const;

   /// calculate the volume
   virtual EcReal volume
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

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const  ;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
      const EcShape& shape
      );

   /// expand to include the set of points passed in
   virtual EcBoolean expandToInclude
      (
      const EcXmlVectorVector & points
      );

   /// get support point index given a vector
   virtual EcVector supportPoint
      (
      const EcVector& v
      ) const;

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const  ;

   /// get an empty capsule
   static EcCircularLozenge nullObject
      (
      );

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

   /// the creator function for this object
   static EcXmlObject* creator
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// get support point ID (last calculated)
   virtual EcU32 supportPointID
      (
      ) const;

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:

   /// the circle defining the disk for the lozenge
   EcCircle m_Circle;

   /// the radius
   EcXmlReal m_Radius;

   /// utility vector for fitFromShape
   mutable EcXmlVectorVector m_UsedPointVec;
};

/// A vector of lozenges
typedef EcXmlVectorType<EcCircularLozenge> EcCircularLozengeVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the capsule into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcCircularLozenge operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcCircularLozenge& m
   );

#endif // ecCircularLozenge_H_
