#ifndef ecRectangle_H_
#define ecRectangle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecRectangle.h
/// @class EcRectangle
/// @brief Hold a class to describe a rectangle in R3.  The rectangle
///        is described by two
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

// forward declarations
class EcCoordinateSystemTransformation;
class EcGeomTriangle;
class EcLineSegment;
class EcCircle;

/** Holds a class to describe a 3D parallelogram (including rhombus, rectangle, and square).
*/
class EC_FOUNDATION_GEOMETRY_DECL EcRectangle : public EcXmlCompoundType
{
public:
   /// default constructor
   EcRectangle
      (
      );

   /// constructor from an end point and two edges
   EcRectangle
      (
      const EcVector& origin,
      const EcVector& edge0,
      const EcVector& edge1
      );

   /// destructor
   virtual ~EcRectangle
      (
      );

   /// copy constructor
   EcRectangle
      (
      const EcRectangle& orig
      );

   /// assignment operator
   EcRectangle& operator=
      (
      const EcRectangle& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRectangle& orig
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

   /// constructor from three points
   /// the fourth point in the rectangle is the vector sum of
   /// point1 and point2 (rhombus)
   virtual void setFromPoints
      (
      const EcVector& point0,
      const EcVector& point1,
      const EcVector& point2
      );

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

   /// get origin of the triangle
   virtual EcVector origin
      (
      ) const;

   /// set origin of the triangle
   virtual void setOrigin
      (
      const EcVector& origin
      );

   /// get center
   virtual EcVector center
      (
      ) const;

   /// check to see if the projection of point onto the plane of the rectangle lies within the rectangle
   virtual EcBoolean checkProjectionInside
      (
      const EcVector& point
      ) const;

   /// compute the vertices of the rectangle
   const EcVector* computeVertices
      (
      ) const;

   /// get the distance to another rectangle
   virtual EcReal distanceTo
      (
      const EcRectangle& other
      ) const;

   /// get the distance squared to another rectangle
   virtual EcReal distanceSquaredTo
      (
      const EcRectangle& other
      ) const;

   /// get the distance squared to another rectangle,  This version
   /// also returns the parameters for determining the closest point
   /// on each rectangle used for the distance
   virtual EcReal distanceSquaredTo
      (
      const EcRectangle& other,
      EcReal& thisRectClosestPtS,
      EcReal& thisRectClosestPtT,
      EcReal& otherRectClosestPtS,
      EcReal& otherRectClosestPtT
      ) const;

   /// get the distance to another line segment
   virtual EcReal distanceTo
      (
      const EcLineSegment& other
      ) const;

   /// get the distance squared to another line segment
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& other
      ) const;

   /// get the distance squared to another line segment,
   /// return the (r,s,t) value describing the position of the closest
   /// point on the rectangle (s,t) and the line segment (r)
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& seg,
      EcReal & RValue,
      EcReal & SValue,
      EcReal & TValue
      ) const;

   /// get the distance to a point
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// get the distance squared to another point
   virtual EcReal distanceSquaredTo
      (
      const EcVector& other
      ) const;

   /// get the distance squared to another point
   virtual EcReal distanceSquaredTo
      (
      const EcVector& other,
      EcReal & SParam,
      EcReal & TParam
      ) const;

   /// compute the distance from a rectangle to a circle
   virtual EcReal distanceTo
      (
      const EcCircle& circle
      ) const;

   /// compute the distance from a rectangle to a circle with return points
   virtual EcReal distanceTo
      (
      const EcCircle& circle,
      EcVector& closestPointOnRectangle,
      EcVector& closestPointOnCircle
      ) const;

   /// check for intersect with another rectangle
   virtual EcBoolean checkIntersect
      (
      const EcGeomTriangle& other
      ) const  ;

   /// project the rectangle onto a line
   virtual void projectRectangle
      (
      const EcVector& line,
      EcReal& min,
      EcReal& max
      ) const;

   /// transform by a coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// compute the point on the rectangle based on s-param and t-param
   virtual void computePointOnRectangle
      (
      EcReal sParam,
      EcReal tParam,
      EcVector& point
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
   static EcRectangle nullObject
      (
      );

protected:
   /// the origin of the rectangle
   EcXmlVector m_Origin;

   /// edge0
   EcXmlVector m_Edge0;

   /// edge1
   EcXmlVector m_Edge1;

   /// utility collection of vertices
   mutable EcVector    m_vVertices[4];
};

/// A vector of line segments
typedef EcXmlVectorType<EcRectangle> EcRectangleVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the line segment in an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcRectangle operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcRectangle& m
   );

#endif // ecRectangle_H_
