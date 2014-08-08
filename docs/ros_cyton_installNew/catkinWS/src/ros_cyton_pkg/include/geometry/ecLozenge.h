#ifndef ecLozenge_H_
#define ecLozenge_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecLozenge.h
/// @class EcLozenge
/// @brief Holds a description of a 3D Lozenge. A lozenge is
///        defined as the set of all points a distance (r) from
///        a rectangle.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecRectangle.h"
#include "ecShape.h"

class EcAxisAlignedBoundingBox;
class EcCapsule;
class EcSphere;

/// Holds a class to describe a 3D lozenge (a distance from a rectangle).
class EC_FOUNDATION_GEOMETRY_DECL EcLozenge : public EcShape
{
public:
   /// default constructor
   /// Constructs a lozenge with a radius of 0.01 unit, edge0 as (0,0.1,0) and edge1 as (0.1,0,0.1)
   EcLozenge
      (
      );

   /// constructor from a line segment and a radius
   EcLozenge
      (
      const EcRectangle rect,
      EcReal radius
      );

   /// destructor
   virtual ~EcLozenge
      (
      );

   /// copy constructor
   EcLozenge
      (
      const EcLozenge& orig
      );

   /// assignment operator
   EcLozenge& operator=
      (
      const EcLozenge& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLozenge& orig
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

   /// set the rectangle
   virtual void setRectangle
      (
      const EcRectangle& rect
      );

   /// get the rectangle
   virtual const EcRectangle& rectangle
      (
      ) const;

   /// set radius
   virtual void setRadius
      (
      EcReal radius
      );

   /// get radius
   virtual EcReal radius
      (
      ) const;

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

   /// get the distance to a point
   /// returns zero if they are just touching and a
   /// negative number if they overlap.
   virtual EcReal distanceTo
      (
      const EcLineSegment& line
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

   /// get an empty polygon
   static EcLozenge nullObject
      (
      );

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const ;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
      const EcXmlVectorVector& points
      )  ;

   /// get support point index given a vector
   virtual EcVector supportPoint
      (
      const EcVector& v
      ) const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
      const EcShape& shape
      );

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const;

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
   /// Compute the distance and witness points to another shape using closed-form solutions. This is valid for both penetration and non-penetration cases
   /**
   \param[in] otherShape The other shape.
   \param[in] xform Transforms the other shape to this shape's coordinates.
   \param[in] computeDistancOnly If true, only distance will be computed.
   \param[out] witnessPointA Upon return, the witness point on this shape.
   \param[out] witnessPointB Upon return, the witness point on otherShape.
   \param[out] distance The distance between two shapes. Negative if they penetrate each other.
   \param[out] proxVec The proximity vector point from otherShape (B) to this shape (A).
   \return True if successful or false otherwise. If it returns false, other means such as using GJK should be pursued.
   */
   EcBoolean computeDistanceAndWitnessPoints
      (
      const EcShape& otherShape,
      const EcCoordinateSystemTransformation& xform,
      EcBoolean computeDistancOnly,
      EcVector & witnessPointA,
      EcVector & witnessPointB,
      EcReal& distance,
      EcVector& proxVec
      ) const;

protected:

   /// the rectangle defining the base of the lozenge
   EcRectangle m_Rectangle;

   /// the radius of the lozenge
   EcXmlReal m_Radius;
};

/// A vector of lozenges
typedef EcXmlVectorType<EcLozenge> EcLozengeVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the lozenge into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcLozenge operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcLozenge& m
   );

#endif // ecLozenge_H_
