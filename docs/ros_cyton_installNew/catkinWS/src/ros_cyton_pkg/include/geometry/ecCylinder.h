#ifndef ecCylinder_H_
#define ecCylinder_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecCylinder.h
/// @brief Holds a class to describe a 3D cylinder
/// @details EcCylinder
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
class EcLozenge;
class EcTetrahedron;
class EcTriangle;

/// Holds a class to describe a 3D Cylinder.
class EC_FOUNDATION_GEOMETRY_DECL EcCylinder : public EcShape
{
public:
   /// default constructor
   /// Constructs a capsule with a radius of 0.1 unit and a height of 0.1 unit
   EcCylinder
      (
      );

   /// constructor from a line segment and a radius
   EcCylinder
      (
      const EcLineSegment lineSegment,
      EcReal radius
      );

   /// destructor
   virtual ~EcCylinder
      (
      );

   /// copy constructor
   EcCylinder
      (
      const EcCylinder& orig
      );

   /// assignment operator
   EcCylinder& operator=
      (
      const EcCylinder& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCylinder& orig
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
      const EcLineSegment& line
      ) const;

   /// get the distance to a point
   /// returns zero if the point is on the surface of the
   /// Cylinder and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// get the distance to a line segment
   /**
   \param[in] line The line segment
   \param[out] thisTValue The t-value of the line segment of the cylinder of the point closest to line.
   \param[out] otherTValue The t-value of line of the point closest to the cylinder
   \param[out] closestPt The point on the cylinder closest to vec.
   */
   virtual EcReal distanceTo
      (
      const EcLineSegment& line,
      EcReal& thisTValue,
      EcReal& otherTValue,
      EcVector& closestPt
      ) const;

   /// get the distance to a point
   /**
   \param[in] vec The point
   \param[out] tValue The t-value of the line segment of the cylinder of the point closest to vec.
   \param[out] closestPt The point on the cylinder closest to vec.
   */
   virtual EcReal distanceTo
      (
      const EcVector& vec,
      EcReal& tValue,
      EcVector& closestPt
      ) const;

   /// get the distance to a triangle
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle
      ) const;

   /// get the distance to a triangle with witness points
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& closestPointOnCylinder,
      EcVector& closestPointOnTriangle
      ) const;

   /// get the distance to a rectangle with witness points
   virtual EcReal distanceTo
      (
      const EcRectangle& rect,
      EcVector& closestPointOnCylinder,
      EcVector& closestPointOnRect
      ) const;

   /// get the distance to a disk
   virtual EcReal distanceTo
      (
      const EcCircle& disk,
      EcVector& closestPointOnCylinder,
      EcVector& closestPointOnDisk
      ) const;

   /**
    * @brief Get the distance to a bounding box.
    * @param[in] box
    * @param[in] xform transformation from the box to this
    * @param[in] closestPointOnCylinder closest point on the cylinder to the box in cylinder frame
    * @param[in] closestPointOnBox closest point on the box to the cylinder in box frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcBox& box,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestPointOnCylinder,
      EcVector& closestPointOnBox
      ) const ;

   /**
    * @brief Get the distance to a tetrahedron.
    * @param[in] tetra
    * @param[in] xform
    * @param[in] closestPointOnCylinder closest point on the cylinder to the tetrahedron in cylinder frame
    * @param[in] closestPointOnTetra closest point on the tetrahedron to the cylinder in tetrahedron frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcTetrahedron& tetra,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestPointOnCylinder,
      EcVector& closestPointOnTetra
      ) const ;

   /**
    * @brief Get the distance to another cylinder.
    * @param[in] other the other cylinder
    * @param[in] xform transformation from the other to this
    * @param[in] closestPointOnThis closest point on this to the other in this frame
    * @param[in] closestPointOnOther closest point on the other to this in other frame
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcCylinder& other,
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

   /// intersect a line segment with the cylinder tube, returning the closest
   /// point on the surface of the shape along the line segment using
   /// the initial closest point provided in pointEvent.
   virtual void intersectLineSegmentWithTube
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// intersect a line segment with the cylinder caps, returning the closest
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
      const EcLineSegment& line
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

   /// expand the Cylinder to include the set of points passed in
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

   /// get the circle that represents a circular cap of the cylinder.
   /**
   \param[in] index The index of the side of interest (0 or 1).
   \return The circle with the normal pointing outward from the cylinder.
   */
   virtual EcCircle circularCap
      (
      EcU32 index
      ) const;

   /// get an empty polygon
   static EcCylinder nullObject
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

   /// intersect a line segment with a cylindrical tube, returning the closest
   /// point along the line segment using the initial closest point
   /// provided in pointEvent.  The tube is the cylinder minus the caps.
   /**
   \param[in] cylinderLineSegment The line segment defining the tube center.
   \param[in] radius The radius of the tube.
   \param[in] lineSegment The line segment used for intersection.
   \param[out] pointEvent The description of the interesection.
   */
   static void intersectCylindricalTubeWithLineSegment
      (
      const EcLineSegment& cylinderLineSegment,
      EcReal radius,
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      );

   /// Compute the distance from a point to a circular cap of the cylinder
   /**
   \param[in] vec The point
   \param[in] index The index of the endpoint of the line segment of the cylinder to signify which of the two circular caps.
   \param[out] clostPointOnCap The point on the circular cap closest to the point.
   \return The distance from that circular cap to the point
   */
   virtual EcReal distanceToCircularCap
      (
      const EcVector& vec,
      EcU32 index,
      EcVector& clostPointOnCap
      ) const;

   /// Compute the distance from a line segment to a circular cap of the cylinder
   /**
   \param[in] line The line segment
   \param[in] index The index of the endpoint of the line segment of the cylinder to signify which of the two circular caps.
   \param[out] tValue The t-value of the closest point on the line segment closest to the circular cap
   \param[out] clostPointOnCap The point on the circular cap closest to the line segment.
   \return The distance from that circular cap to the line
   */
   virtual EcReal distanceToCircularCap
      (
      const EcLineSegment& line,
      EcU32 index,
      EcReal& tValue,
      EcVector& clostPointOnCap
      ) const;

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

   /// determine whether or not a new signed distance should be taken when considering a union
   /// here, a positive distance is separation distance and a negative distance is penetration distance
   virtual EcBoolean acceptNewDirectedDistance
      (
         EcReal newDistance,
         EcReal oldDistance
      ) const;

protected:

   /// the line segment running the length of the Cylinder
   EcLineSegment m_LineSegment;

   /// the radius
   EcXmlReal m_Radius;
};

/// A vector of line segments
typedef EcXmlVectorType<EcCylinder> EcCylinderVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the Cylinder into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcCylinder operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcCylinder& m
   );

#endif // ecCylinder_H_
