#ifndef ecCone_H_
#define ecCone_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecCone.h
/// @class EcCone
/// @brief Holds a class to describe a 3D Cone
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecCircle.h"
#include "ecLineSegment.h"
#include "ecPolygon.h"
#include "ecShape.h"
#include <xml/ecXmlVector.h>

class EcAxisAlignedBoundingBox;
class EcBasePhysicalExtent;
class EcBox;
class EcCylinder;
class EcGeomTriangle;
class EcLozenge;
class EcTetrahedron;

/// Holds a class to describe a 3D Cone.
class EC_FOUNDATION_GEOMETRY_DECL EcCone : public EcShape
{
public:
   /// default constructor
   /// Creates a cone with a base radius of 0.1 units and a height of 0.1 unit
   EcCone
      (
      );

   /// constructor from a line segment and 2 radius
   EcCone
      (
      const EcLineSegment& lineSegment,
      const EcReal& radius0,
      const EcReal& radius1
      );

   /// destructor
   virtual ~EcCone
      (
      );

   /// copy constructor
   EcCone
      (
      const EcCone& orig
      );

   /// assignment operator
   EcCone& operator=
      (
      const EcCone& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCone& orig
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

   /// get line segment
   virtual const EcLineSegment& lineSegment
      (
      ) const;

   /// set line segment
   virtual void setLineSegment
      (
      const EcLineSegment& lineSegment
      );

   /// get radius0
   virtual const EcReal& radius0
      (
      ) const;

   /// set radius0
   virtual void setRadius0
      (
      const EcReal& radius
      );

   /// get radius0
   virtual const EcReal& radius1
      (
      ) const;

   /// set radius
   virtual void setRadius1
      (
      const EcReal& radius
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

   /// get the distance to a point
   /**
   This method returns zero if the point is inside the cone and the returned value of closestPt is undefined.
   \param[in] vec The point
   \param[out] closestPt The point on the cylinder closest to vec.
   \return The distance to the point. Zero if the point is inside the cone.
   */
   virtual EcReal distanceTo
      (
      const EcVector& vec,
      EcVector& closestPt
      ) const;

   /// get the distance to a point
   /**
   This method returns zero if the line intersects or touches the cone.
   \param[in] vec The point
   \return The distance to the point. Zero if the line intersects or touches the cone.
   */
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /**
    * @brief Get the distance to a line segment and the closest points.
    * @details The algorithm is based on numerical optimization.
    *          It solves the sufficient and necessary KKT conditions to find the minmium distance.
    * @param[in] lineSeg the line segment
    * @param[out] tVal t-value of the closest point on the line segment
    * @param[out] closestPt closest point on the cone to the line segment
    * @return EcReal The distance to the line segment. Zero if the line intersects or touches or is inside the cone.
    */
   virtual EcReal distanceTo
      (
      const EcLineSegment& lineSeg,
      EcReal& tVal,
      EcVector& closestPt
      ) const;

   /**
    * @brief Get the distance to a line segment
    * @see distanceTo(const EcLineSegment&, EcReal&, EcVector&) const
    * @param[in] lineSeg the line segment
    * @return EcReal The distance to the line segment. Zero if the line intersects or touches or is inside the cone.
    */
   virtual EcReal distanceTo
      (
      const EcLineSegment& lineSeg
      ) const;

   /**
    * @brief Get the distance to a rectangle with closest points.
    * @param[in] rect rectangle
    * @param[out] closestOnCone closest point on the cone
    * @param[out] closestOnRect closest point on the rectangle
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcRectangle& rect,
      EcVector& closestOnCone,
      EcVector& closestOnRect
      ) const;

   /**
    * @brief Get the distance to a triangle with closest points.
    * @param[in] triangle triangle
    * @param[in] closestOnCone closest point on the cone
    * @param[in] closestOnTriangle closest point on the triangle
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& closestOnCone,
      EcVector& closestOnTriangle
      ) const;

   /// get the distance to a disk with closest points
   virtual EcReal distanceTo
      (
      const EcCircle& disk,
      EcVector& closestOnCone,
      EcVector& closestOnDisk
      ) const;

   /**
    * @brief Get the distance to a bounding box.
    * @param[in] box an obb
    * @param[in] xform transformation from the box to this
    * @param[out] closestPointOnCone closest point on the cone to the box in cone frame
    * @param[out] closestPointOnBox closest point on the box to the cone in box frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcBox& box,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestPointOnCone,
      EcVector& closestPointOnBox
      ) const ;

   /**
    * @brief Get the distance to a tetrahedron.
    * @param[in] tetra a tetrahedron
    * @param[in] xform transformation from the box to this
    * @param[out] closestPointOnCone closest point on the cone to the tetrahedron in cone frame
    * @param[out] closestPointOnTetra closest point on the tetrahedron to the cone in tetrahedron frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcTetrahedron& tetra,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestPointOnCone,
      EcVector& closestPointOnTetra
      ) const ;

   /**
    * @brief Get the distance to a cylinder.
    * @param[in] cyld the cylinder
    * @param[in] xform transformation from the cylinder to this
    * @param[out] closestPointOnCone closest point on the cone to the cylinder in cone frame
    * @param[out] closestPointOnCyld closest point on the cylinder to the cone in cylinder frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcCylinder& cyld,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestPointOnCone,
      EcVector& closestPointOnCyld
      ) const ;

   /**
    * @brief Get the distance to another cone.
    * @param[in] other the other cone
    * @param[in] xform transformation from the cylinder to this
    * @param[out] closestPointOnThis closest point on this cone to the other in this frame
    * @param[out] closestPointOnOther closest point on the other cone to this in the other frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcCone& other,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestPointOnThis,
      EcVector& closestPointOnOther
      ) const ;

   /**
   \copydoc EcShape::intersectLineSegment()
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// intersect a line segment with the conical body, returning the closest
   /// point on the surface of the shape along the line segment using
   /// the initial closest point provided in pointEvent.
   virtual void intersectLineSegmentWithBody
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// intersect a line segment with the frustum caps, returning the closest
   /// point on the surface of the shape along the line segment using
   /// the initial closest point provided in pointEvent.
   virtual void intersectLineSegmentWithCaps
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

   /// check the intersection of a line segment with the cone body
   virtual EcBoolean checkIntersectWithBody
      (
      const EcLineSegment& lineSeg,
      EcReal& tVal,
      EcVector& ptCone
      ) const;

   /// check the intersection of a circle with the cone body
   virtual EcBoolean checkIntersectWithBody
      (
      const EcCircle& circle,
      EcVector& pt
      ) const;

   /// calculate the volume
   virtual EcReal volume
      (
      ) const;

   /// flip the internal representation by swapping endpoints
   /// and swapping radii.
   virtual void swapInternals
      (
      );

   /// get the tip that would be formed if the frustum were extended into a cone
   /// returns true for success
   virtual EcBoolean getTip
      (
      EcVector& tip
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

   /// expand the Cone to include the set of points passed in
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

   /// compute the line segment on the lateral surface of this cone that is closest to a point
   /**
   \param[in] point The given point.
   \param[out] line The line segment on the lateral surface.
   \return True if successful or false if the point is on the line segment (centerline) of the cone.
   */
   virtual EcBoolean computeLineSegmentOnLateralSurface
      (
      const EcVector& point,
      EcLineSegment& line
      ) const;

   /// compute the line segment on the lateral surface of this cone that is closest to a point. Same as the above method except it also checks whether the point is inside this cone.
   /**
   \param[in] point The given point.
   \param[out] line The line segment on the lateral surface.
   \param[out] insideCone True if the given point is inside this cone or false otherwise
   \return True if successful or false if the point is on the line segment (centerline) of the cone.
   */
   virtual EcBoolean computeLineSegmentOnLateralSurface
      (
      const EcVector& point,
      EcLineSegment& line,
      EcBoolean& insideCone
      ) const;

   /// get the circle that represents a circular cap of the cone.
   /**
   \param[in] index The index of the side of interest (0 or 1).
   \return The circle with the normal pointing outward from the cone.
   */
   virtual EcCircle circularCap
      (
      EcU32 index
      ) const;

   /// get an empty polygon
   static EcCone nullObject
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
   /// compute PD between cone and lozenge. see computePenetrationDistanceAndSupportPoints for general shape for the meanings of all arguments.
   virtual EcBoolean computePenetrationDistanceAndSupportPoints
      (
        const EcLozenge& lozenge,
        const EcCoordinateSystemTransformation& xform,
        EcVector & supportPointA,
        EcVector & supportPointB,
        EcReal& distance,
        EcVector& proxVec,
        EcBoolean& useGJK
      ) const;

   /// compute PD between cone and OBB. see computePenetrationDistanceAndSupportPoints for general shape for the meanings of all arguments.
   virtual EcBoolean computePenetrationDistanceAndSupportPoints
      (
        const EcBox& box,
        const EcCoordinateSystemTransformation& xform,
        EcVector & supportPointA,
        EcVector & supportPointB,
        EcReal& distance,
        EcVector& proxVec,
        EcBoolean& useGJK
      ) const;

   /// utility method for distanceTo(const EcLineSegment&, EcReal&, EcVector&) const
   EcBoolean distanceToLineSegmentCase12
      (
      const EcLineSegment& lineSeg,
      const EcVector& SP,
      EcReal& dist,
      EcReal& tVal,
      EcVector& closestPt
      ) const;

   /// utility method for distanceTo(const EcLineSegment&, EcReal&, EcVector&) const
   EcBoolean distanceToLineSegmentCase34
      (
      const EcLineSegment& lineSeg,
      const EcVector& SP,
      const EcReal& tVal0,
      const EcReal& tVal1,
      EcReal& dist,
      EcReal& tVal,
      EcVector& closestPt
      ) const;

   /// utility method for distanceTo(const EcLineSegment&, EcReal&, EcVector&) const
   EcBoolean distanceToLineSegmentCase5
      (
      const EcLineSegment& lineSeg,
      const EcVector& SP,
      EcReal& dist,
      EcReal& tVal,
      EcVector& closestPt
      ) const;

   /// utility method for distanceTo(const EcCircle&, EcVector&, EcVector&) const
   EcBoolean distanceToDiskCase12
      (
      const EcCircle& disk,
      const EcVector& ptDiskToCap0,
      const EcVector& ptDiskToCap1,
      EcReal& dist,
      EcVector& closestOnCone,
      EcVector& closestOnDisk
      ) const;

   /// the line segment running the length of the Cone
   EcLineSegment m_LineSegment;

   /// the radius on the end point 0 side
   EcXmlReal m_Radius0;

   /// the radius on the end point 1 side
   EcXmlReal m_Radius1;

   /// convenience variables
   mutable EcReal m_tanTheta;
   /// convenience variables
   mutable EcLineSegment m_SphereLineSegment;
   /// convenience variables
   mutable EcReal m_SphereRadius0;
   /// convenience variables
   mutable EcReal m_SphereRadius1;

};

/// A vector of line segments
typedef EcXmlVectorType<EcCone> EcConeVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the Cone into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcCone operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcCone& m
   );

#endif // ecCone_H_
