#ifndef ecGeomTriangle_H_
#define ecGeomTriangle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGeomTriangle.h
/// @class EcGeomTriangle
/// @brief Holds a class to describe a 3D triangle
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include "ecShapePointEvent.h"
#include <xml/ecXmlVector.h>

// forward declarations
class EcCoordinateSystemTransformation;
class EcLineSegment;
class EcRectangle;
class EcCircle;
class EcSpatialMatrix ;

/** Holds a class to describe a 3D triangle.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcGeomTriangle : public EcXmlCompoundType
{
public:
   /// default constructor
   /// Constructs a triangle with its two edges having the co-ordinates as (0,0,0.1), (0.1, 0.1, 0.1)
   EcGeomTriangle
      (
      );

   /// constructor from endpoints
   EcGeomTriangle
      (
      const EcVector& pt0,
      const EcVector& pt1,
      const EcVector& pt2
      );

   /// destructor
   virtual ~EcGeomTriangle
      (
      );

   /// copy constructor
   EcGeomTriangle
      (
      const EcGeomTriangle& orig
      );

   /// assignment operator
   EcGeomTriangle& operator=
      (
      const EcGeomTriangle& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeomTriangle& orig
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

   /// get edge 0
   virtual const EcVector& edge0
      (
      ) const;

   /// set edge 0
   virtual void setEdge0
      (
      const EcVector& edge0
      );

   /// get edge 1
   virtual const EcVector& edge1
      (
      ) const;

   /// set edge 1
   virtual void setEdge1
      (
      const EcVector& edge1
      );

   /// set both edges at once
   virtual void setEdges
      (
      const EcVector& edge0,
      const EcVector& edge1
      );

   /// set all three points
   virtual void setPoints
      (
      const EcVector& pt0,
      const EcVector& pt1,
      const EcVector& pt2
      );

   /// get origin of the triangle
   virtual const EcVector& origin
      (
      ) const;

   /// set origin of the triangle
   virtual void setOrigin
      (
      const EcVector& origin
      );

   /// transform the triangle by the given coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// compute the point on the triangle based on s-param and t-param
   virtual void computePointOnTriangle
      (
      EcReal sParam,
      EcReal tParam,
      EcVector& point
      ) const;

   /// calculate the interior base angle (between edge0 and edge1)
   virtual EcReal baseAngle
      (
      ) const;

   /// calculate the interior angle for edge 0
   virtual EcReal edge0Angle
      (
      ) const;

   /// calculate the interior angle for edge 1
   virtual EcReal edge1Angle
      (
      ) const;

   /// calculate the area of the triangle
   virtual EcReal area
      (
      ) const;

   /// calculate the perimeter of the triangle
   virtual EcReal perimeter
      (
      ) const;

   /// calculate the (unit magnitude) normal to the triangle
   /// if the points are collinear, this returns the zero vector
   virtual EcVector normal
      (
      ) const;

   /// intersect a line segment with the triangle, returning the
   /// closest point on the surface of the shape along the line
   /// segment using the initial closest point provided in
   /// pointEvent.
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// check the intersection with a line
   virtual EcBoolean lineSegmentCheckIntersect
      (
      const EcLineSegment & lineSegment
      ) const;

   /// check to see if the projection of point onto the plane of the triangle lies within the triangle
   virtual EcBoolean checkProjectionInside
      (
      const EcVector& point
      ) const;

   /// get the distance to a point
   virtual EcReal pointDistanceTo
      (
      const EcVector& vec
      ) const;

   /// get the distance to a point and return the closest point
   /**
   \param[in] vec The point
   \param[out] closestPt The point on the filled triangle closest to the point
   \return zero if the point intersects the disk or positive value otherwise
   */
   virtual EcReal pointDistanceTo
      (
      const EcVector& vec,
      EcVector& closestPt
      ) const;

   /// get the distance squared to a point (faster by sqrt than getting the distance)
   virtual EcReal distanceSquaredTo
      (
      const EcVector& vec
      ) const;

   /// get the distance squared to a point
   virtual EcReal distanceSquaredTo
      (
      const EcVector& vec,
      EcReal & tValue,
      EcReal & sValue
      ) const;

   /// get the distance to another triangle
   virtual EcReal triangleDistanceTo
      (
      const EcGeomTriangle& other
      ) const;

   /// get the distance to another triangle plus return the witness points
   virtual EcReal triangleDistanceTo
      (
      const EcGeomTriangle& other,
      EcVector& closestPointThis,
      EcVector& closestPointOther
      ) const;

   /// get the distance squared to another triangle
   virtual EcReal distanceSquaredTo
      (
      const EcGeomTriangle& other
      ) const;

   /// get the distance squared to another triangle, returns parametric
   /// location of closest point
   virtual EcReal distanceSquaredTo
      (
      const EcGeomTriangle& other,
      EcReal &thisSVal,
      EcReal &thisTVal,
      EcReal &otherSVal,
      EcReal &otherTVal
      ) const;

   /// get the distance to another triangle plus return the witness points
   virtual EcReal rectangleDistanceTo
      (
      const EcRectangle& rect,
      EcVector& closestPointOnTriangle,
      EcVector& closestPointOnRectangle
      ) const;

   /// compute the distance squared to a rectangle
   /// (parallelogram).  This version returns the
   /// parametric values need to arrive at the closest point
   /// of intersection between the two objects
   virtual EcReal distanceSquaredTo
      (
      const EcRectangle& rect,
      EcReal& triP0,
      EcReal& triP1,
      EcReal& rctP0,
      EcReal& rctP1
      ) const;

   /// compute the distance from a triangle to a rectangle
   virtual EcReal rectangleDistanceTo
      (
      const EcRectangle& rect
      ) const;

   /// compute the distance squared from a triangle to a rectangle
   virtual EcReal distanceSquaredTo
      (
      const EcRectangle& rect
      ) const;

   /// compute the distance from a triangle to a circle
   virtual EcReal circleDistanceTo
      (
      const EcCircle& circle
      ) const;

   /// compute the distance from a triangle to a closed circle with return points
   virtual EcReal circleDistanceTo
      (
      const EcCircle& circle,
      EcVector& closestPointOnTriangle,
      EcVector& closestPointOnCircle
      ) const;

   /// compute the distance from an open triangle to an open circle with return points
   virtual EcReal openCircleDistanceTo
      (
      const EcCircle& circle,
      EcVector& closestPointOnTriangle,
      EcVector& closestPointOnCircle
      ) const;

   /// compute the directed distance from an open triangle to an open circle with return points
   /// the distance if positive implies no interlocking.  If negative, triangle-circle interlocking
   /// is implied.  The return value is the minimum magnitude distance to reach contact.
   virtual EcReal directedDistanceToOpenCircle
      (
      const EcCircle& circle,
      EcVector& closestPointOnTriangle,
      EcVector& closestPointOnCircle
      ) const;

   /// compute the directed distance from a closed triangle to an open circle with return points.
   /// The distance if positive implies no penetration of the circle into the solidTriangle.  If negative, penetration
   /// is implied.  The return value magnitude is the minimum distance to make (positive) or break (negative) contact.
   virtual EcReal directedDistanceClosedTriangleToOpenCircle
      (
      const EcCircle& circle,
      EcVector& closestPointOnTriangle,
      EcVector& closestPointOnCircle
      ) const;

   /// check to see if this triangle is interlinked with the circle
   virtual EcBoolean isInterlinked
      (
      const EcCircle& circle
      ) const;

   /// get the distance squared to the line segment, this version
   /// also return the parametric parameters (s,t) for the triangle
   /// and r for the line segment that defines the closest point
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& seg,
      EcReal& segRVal,
      EcReal& triSVal,
      EcReal& triTVal
      ) const;

   /// get the distance to a line segment, returning the r value
   /// for the line segment and the witness point on the triangle.
   virtual EcReal lineSegmentDistanceTo
      (
      const EcLineSegment& seg,
      EcReal& segRVal,
      EcVector& closestPointOnTriangle
      ) const;

   /// get the distance to a line segment
   virtual EcReal lineSegmentDistanceTo
      (
      const EcLineSegment& other
      ) const;

   /// get the distance squared to a line segment
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& other
      ) const;

   /// project the triangle onto a line segment
   virtual void projectTriangle
      (
      const EcVector& line,
      EcReal& min,
      EcReal& max
      ) const;

   /// check the intersection with another triangle
   virtual EcBoolean triangleCheckIntersect
      (
      const EcGeomTriangle& other
      ) const ;

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
   static EcGeomTriangle nullObject
      (
      );

protected:
   /// the origin of the triangle
   EcXmlVector m_Origin;

   /// edge0
   EcXmlVector m_Edge0;

   /// edge1
   EcXmlVector m_Edge1;

   /// non-xml data
   EcBoolean m_IsCollinear;
};

/// A vector of triangles
typedef EcXmlVectorType<EcGeomTriangle> EcGeomTriangleVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the line segment in an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcGeomTriangle operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcGeomTriangle& m
   );

#endif // ecGeomTriangle_H_
