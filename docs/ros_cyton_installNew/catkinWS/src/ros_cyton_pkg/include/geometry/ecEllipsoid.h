#ifndef ecEllipsoid_H_
#define ecEllipsoid_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecEllipsoid.h
/// @class EcEllipsoid
/// @brief Holds a class to describe an ellipsoid.  The ellipsoid
///        is described using semiaxes and an coordinate system
///        transformation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShape.h"
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecSpatialMatrix.h>

// forward declarations
class EcAxisAlignedBoundingBox;
class EcLineSegment;
class EcGeomTriangle;
class EcPlane;
class EcRectangle;

/** Holds a class to describe a 3D ellipsoid.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcEllipsoid : public EcShape
{
public:
   /// default constructor
   EcEllipsoid
      (
      );

   /// constructor from three ellipsoid parameters (semiaxes) and a transformation
   EcEllipsoid
      (
      const EcReal& a,
      const EcReal& b,
      const EcReal& c,
      const EcCoordinateSystemTransformation& xform
      );

   /// constructor from three ellipsoid parameters (semiaxes)
   /// uses the identity transformation
   EcEllipsoid
      (
      const EcReal& a,
      const EcReal& b,
      const EcReal& c
      );

   /// destructor
   virtual ~EcEllipsoid
      (
      );

   /// copy constructor
   EcEllipsoid
      (
      const EcEllipsoid& orig
      );

   /// assignment operator
   EcEllipsoid& operator=
      (
      const EcEllipsoid& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEllipsoid& orig
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

   /// set a
   virtual void setA
      (
      const EcReal& a
      );

   /// get a
   virtual const EcReal& a
      (
      ) const;

   /// set b
   virtual void setB
      (
      const EcReal& b
      );

   /// get b
   virtual const EcReal& b
      (
      ) const;

   /// set c
   virtual void setC
      (
      const EcReal& c
      );

   /// get c
   virtual const EcReal& c
      (
      ) const;


   /// set the coordinate system transform
   virtual void setXform
      (
      const EcCoordinateSystemTransformation &xform
      );

   /// return the coordinate system transform
   virtual const EcCoordinateSystemTransformation& xform
      (
      ) const;

   /// get the center of the ellipsoid
   virtual const EcVector& center
      (
      ) const;

   /// returns the A matrix for the ellipsoid
   /// described as (X-C)^T A (X-C) = 1

   virtual const EcSpatialMatrix& aMatrix
      (
      ) const ;


   /// sets the A^-1 matrix for the ellipsoid
   /// described as (X-C)^T A (X-C) = 1
   virtual const EcSpatialMatrix& inverseAMatrix
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

   /// get the distance to a plane
   /// returns zero if they are just touching and a
   /// negative number if they overlap.
   EcReal distanceTo
      (
      const EcPlane& plane
      ) const ;

   /// get the distance squared to line segment
   /// returns zero if the line is tangent to the surface of the
   /// sphere and a negative number if it is inside.
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& seg
      ) const;

   /// get the distance squared to line segment
   /// returns zero if the line is tangent to the surface of the
   /// sphere and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcLineSegment& seg
      ) const;

   /// get the distance to a point
   /// returns zero if the point is on the surface of the
   /// sphere and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// get the squared distance to a point
   /// returns zero if the point is on the surface of the
   /// sphere and a negative number if it is inside.
   /// returns the closest point on the ellipse
   virtual EcReal distanceSquaredTo
      (
      const EcVector& vec,
      EcVector & closestPoint
      ) const;

   /// check the intersection with plane
   virtual EcBoolean checkIntersect
      (
      const EcPlane& plane
      ) const;

   /// check the intersection with a polygon
   EcBoolean checkIntersect
      (
      const EcPolygon& poly
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

   /// compute the number and the intersection points with a line segment
   EcBoolean findIntersect
      (
      const EcLineSegment& line,
      EcU32& numIntPoints,
      EcVectorVector& vPoints
      ) const ;

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

   /// returns the type ID of this shape
   virtual EcU32 type
      (
      ) const;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
      const EcXmlVectorVector& points
      );

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const   ;

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

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
      ) const  ;

   /// get an empty polygon
   static EcEllipsoid nullObject
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

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:
   /// Fill in the data for the alternate representation
   /// this data is provided in the data structure for speed.
   virtual void computeMatrix
      (
      );

   /// update the point on the ellipsoid closest to other ellipsoid
   /// used internally for ellipsoid-ellipsoid computation
   virtual void updateClosestPoint
      (
      const EcVector & P1ref,
      const EcVector & P2ref,
      EcReal & stepSize,
      EcVector & P1
      ) const ;

   /// the extent for an axis-aligned ellipsoid (A,B,C) at the origin
   /// as described by (x/A)^2 + (y/B)^2 + (z/C)^2 = 1
   EcXmlReal m_A;
   /// the extent for an axis-aligned ellipsoid (A,B,C) at the origin
   EcXmlReal m_B;
   /// the extent for an axis-aligned ellipsoid (A,B,C) at the origin
   EcXmlReal m_C;

   /// contains the coordinate system transform for the ellipsoid
   /// multiply pt*m_CoordXform^1 to translate to local coord. system
   EcCoordinateSystemTransformation  m_CoordXform;


   /// alternate representation
   //

   // center-matrix form, (X-C)^T A (X-C) = 1, where A is a positive
   // definite matrix

   /// positive definite (A) matrix.
   EcSpatialMatrix m_AMatrix ;


   /// positive definite (A^-1) matrix.
   EcSpatialMatrix m_InvAMatrix ;

   /// utility arrays
   mutable EcVectorVector m_vE1Points ;
   /// utility arrays
   mutable EcVectorVector m_vE2Points ;
};

/// type of a vector of ellipsoids
typedef EcXmlVectorType<EcEllipsoid> EcEllipsoidVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the sphere into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcEllipsoid operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcEllipsoid& sp
   );

#endif // ecEllipsoid_H_
