#ifndef ecPlane_H_
#define ecPlane_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlane.h
/// @class EcPlane
/// @brief A class that describes a plane using a normal vector
///        and a point
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

/// forward references
class EcCircle;
class EcCoordinateSystemTransformation;
class EcGeomTriangle;
class EcLineSegment;
class EcOrientation;
class EcRectangle;
class EcVector;
class EcLeastSquareTool;

/// Holds a description of a plane
class EC_FOUNDATION_GEOMETRY_DECL EcPlane : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPlane
      (
      );

    /// constructor from a point and a normal vector
    EcPlane
      (
      const EcVector& basePoint,
      const EcVector& normalVector
      );

   /// destructor
   virtual ~EcPlane
      (
      );

   /// copy constructor
   EcPlane
      (
      const EcPlane& orig
      );

   /// assignment operator
   EcPlane& operator=
      (
      const EcPlane& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlane& orig
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

   /// get the base point
   virtual const EcVector& basePoint
      (
      ) const;

   /// set the base point
   virtual void setBasePoint
      (
      const EcVector& basePoint
      );

   /// get the normal vector
   virtual const EcVector& normal
      (
      ) const;

   /// set the normal vector
   virtual void setNormalVector
      (
      const EcVector& normalVector
      );

   /// calculate the intersection with a line segment
   /// if intersection occurs, the t-value for the intersection point
   /// is returned.
   /**
   \param[in] seg The line segment
   \param[out] tValue The t-Value of point on the line segment intersecting the plane
   \return true if intersection ocurred, false otherwise
   */
   virtual EcBoolean intersectLineSegment
      (
      const EcLineSegment& seg,
      EcReal& tValue
      ) const;

   /// get the distance to a line segment
   /// returns zero if the line intersects the plane, a positive distance
   /// if the line is on the side of the plane in the direction of the
   /// normal vector and a negative distance if the line segment lies
   /// on the side of the plane in the opposite direction of the normal
   /// vector
   virtual EcReal distanceTo
      (
      const EcLineSegment& seg
      ) const;

   /// get the distance to a line segment
   /// returns zero if the line intersects the plane, a positive distance
   /// if the line is on the side of the plane in the direction of the
   /// normal vector and a negative distance if the line segment lies
   /// on the side of the plane in the opposite direction of the normal
   /// vector
   /**
   \param[in] seg The segment.
   \param[out] closestPtOnSegment The point on the segment closest to plane.
   \param[out] closestPt The point on the plane closest to line segment.
   \return The distance to the line segment.
   */
   virtual EcReal distanceTo
      (
      const EcLineSegment& seg,
      EcVector& closestPtOnSegment,
      EcVector& closestPt
      ) const;

   /// get the distance to a point
   /// returns zero if the point is in the plane, a positive distance if
   /// if it is on the side of the plane in the direction of the
   /// normal vector and a negative distance if the point lies
   /// on the side of the plane in the opposite direction of the normal
   /// vector
   virtual EcReal distanceTo
      (
      const EcVector& pt
      ) const;

   /// get the distance to a rectangle
   /// returns zero if the point is in the plane, a positive distance if
   /// if it is on the side of the plane in the direction of the
   /// normal vector and a negative distance if the point lies
   /// on the side of the plane in the opposite direction of the normal
   /// vector
   virtual EcReal distanceTo
      (
      const EcRectangle& pt
      ) const;

   /// return the distance to a rectangle
   EcReal distanceTo
      (
      const EcRectangle& rect,
      EcVector& closestOnPlane,
      EcVector& closestOnRect
      ) const ;

   /// returns the distance to a triangle
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& tri
      ) const;

   /// get the distance to a triangle
   /**
   This method returns zero if the triangle touches the plane and negative if the triangle penetrates or is behind the plane.
   \param[in] triangle The triangle.
   \param[out] closestPtOnTriangle The point on the triangle closest to plane.
   \param[out] closestPt The point on the plane closest to triangle.
   \return The distance to the triangle.
   */
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& closestPtOnTriangle,
      EcVector& closestPt
      ) const;

   /// get the directed distance to a triangle
   /**
   This method returns the positive distance is the entire triangle is on the normal side of the plane.
   It returns the negative penetration distance if the triangle pierces the plane or is opposide the
   normal.
   \param[in] triangle The triangle.
   \return The directed distance to the triangle.
   */
   virtual EcReal directedDistanceTo
      (
      const EcGeomTriangle& triangle
      ) const;

   /// get the directed distance to a triangle
   /**
   This method returns the positive distance is the entire triangle is on the normal side of the plane.
   It returns the negative penetration distance if the triangle pierces the plane or is opposide the
   normal.
   \param[in] triangle The triangle.
   \param[out] witnessPtOnTriangle The point on the triangle closest to plane if return value is positive
               or most penetrating if the return value is negative.
   \param[out] witnessPtOnPlane The point on the plane closest to triangle (positive case) or closest to the
               most penetrating point (negative case).
   \return The directed distance to the triangle.
   */
   virtual EcReal directedDistanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& witnessPtOnTriangle,
      EcVector& witnessPtOnPlane
      ) const;

   /// get the distance to a circle
   /**
   This method returns zero if the circle touches the plane and negative if the circle penetrates or is behind the plane.
   \param[in] circle The circle.
   \return The distance to the circle.
   */
   virtual EcReal distanceTo
      (
      const EcCircle& circle
      ) const;

   /// get the distance to a circle plus data regarding witness points
   /**
   This method returns zero if the circle touches the plane and negative if the circle penetrates or is behind the plane.
   \param[in] circle The circle.
   \param[out] direction The direction to the point on the circle closest to plane (closest point = center + direction*radius).
   \param[out] closestPt The point on the plane closest to circle.
   \return The distance to the circle.
   */
   virtual EcReal distanceTo
      (
      const EcCircle& circle,
      EcVector& direction,
      EcVector& closestPt
      ) const;

   /// check intersection of a plane and a triangle
   virtual EcBoolean checkIntersect
      (
      const EcGeomTriangle& tri
      ) const;

   /// find the projection of a point onto the plane
   virtual void calculateProjectionPoint
      (
      const EcVector& point,
      EcVector& projectionOfPoint
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

   /// get an empty polygon
   static EcPlane nullObject
      (
      );

   /// Least square fitting from points
   virtual EcBoolean LSQFitting
      (
      const EcVectorVector& points
      );

protected:
   /// the base point of the plane
   EcXmlVector  m_BasePoint;

   /// the normal vector of the plane
   EcXmlVector  m_NormalVector;

 };

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the plane in an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcPlane operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcPlane& pl
   );

/// expresses the plane in a rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcPlane operator *
   (
   const EcOrientation& orient,
   const EcPlane& pl
   );

/// type of a vector of planes
typedef EcXmlVectorType<EcPlane> EcPlaneVector;

#endif // ecPlane_H_
