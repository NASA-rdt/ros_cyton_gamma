#ifndef ecCircle_H_
#define ecCircle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecCircle.h
/// @class EcCircle
/// @brief A class that describes a circle (disk) in 3D using a
///        plane and a radius
/// @details Holds a description of a circle (disk) in 3D. A circle is basically
///          a plane with a radius. The base point of the plane is the center of
///          the circle. The normal vector of the plane is also the normal vector
///          of the circle.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLineSegment.h"
#include "ecPlane.h"
#include <xml/ecXmlBasicType.h>

// forward declarations.
class EcShapePointEvent;

/// Holds a description of a circle (disk) in 3D.
class EC_FOUNDATION_GEOMETRY_DECL EcCircle : public EcXmlCompoundType
{
public:
   /// default constructor
   EcCircle
      (
      );

   /// constructor from a plane and a radius
   EcCircle
      (
      const EcPlane& plane,
      EcReal radius
      );

   /// destructor
   virtual ~EcCircle
      (
      );

   /// copy constructor
   EcCircle
      (
      const EcCircle& orig
      );

   /// assignment operator
   EcCircle& operator=
      (
      const EcCircle& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCircle& orig
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

   /// get the plane on which the circle resides
   virtual const EcPlane& plane
      (
      ) const;

   /// set the plane
   virtual void setPlane
      (
      const EcPlane& value
      );

   /// get the radius
   virtual EcReal radius
      (
      ) const;

   /// set the radius
   virtual void setRadius
      (
      EcReal value
      );

   /// get the center of the circle (which is the base point of the plane)
   virtual const EcVector& center
      (
      ) const;

   /// set the center
   virtual void setCenter
      (
      const EcVector& center
      );

   /// get the normal vector
   virtual const EcVector& normal
      (
      ) const;

   /// set the normal
   virtual void setNormal
      (
      const EcVector& normal
      );

   /// transform by a coordinate system transformation
   void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// calculate the area of the circle
   EcReal area
      (
      ) const;

   /// check the intersection with another disk
   EcBoolean checkDiskIntersect
      (
      const EcCircle& disk
      ) const;

   /// project the disk along its plane to another plane
   EcLineSegment projectAlongDiskToPlane
      (
      const EcPlane& other
      ) const;

   /**
    * @brief Get the distance from the disk defined by the circle to a line segment.
    * @param[in] seg the line segment
    * @return zero if the line intersects the disk (circle + interior) or positive value otherwise
    */
   virtual EcReal lineSegmentDistanceToThisDisk
      (
      const EcLineSegment& seg
      ) const;

   /**
    * @brief Get the distance from the circle to a line segment.
    * @param[in] seg the line segment
    * @return EcReal zero if the line intersects the circle or a positive value otherwise
    */
   virtual EcReal lineSegmentDistanceToThisCircle
      (
      const EcLineSegment& seg
      ) const;

   /**
    * @brief Get the distance from the disk defined by the circle to a line segment.
    * @details 
    * @param[in] seg the line segment
    * @param[out] tValue the t-Value of point on the line segment closest to the disk
    * @param[out] closestPt the point on the circle closest to the line segment
    * @return EcReal zero if the line intersects the circle or positive value otherwise
    */
   virtual EcReal lineSegmentDistanceToThisDisk
      (
      const EcLineSegment& seg,
      EcReal& tValue,
      EcVector& closestPt
      ) const;

   /**
    * @brief Get the distance from the circle to a line segment.
    * @param[in] seg the line segment
    * @param[out] tValue the t-Value of point on the line segment closest to the circle
    * @param[out] closestPt the point on the circle closest to the line segment
    * @return EcReal zero if the line intersects the circle or positive value otherwise
    */
   virtual EcReal lineSegmentDistanceToThisCircle
      (
      const EcLineSegment& seg,
      EcReal& tValue,
      EcVector& closestPt
      ) const;

   /**
    * @brief Get the intersection point between the disk and the line segment.
    * @details 
    * @param[in] seg the line segment
    * @param[out] tValue the t-Value of point on the line segment intersecting the disk
    * @return EcBoolean true if intersection occurred, false otherwise
    */
   virtual EcBoolean diskIntersectLineSegment
      (
      const EcLineSegment& seg,
      EcReal& tValue
      ) const;

   /// get the distance from the disk defined by the circle to a point
   /// returns zero if the point is inside the circle or positive value otherwise
   virtual EcReal pointDistanceToThisDisk
      (
      const EcVector& pt
      ) const;

   /// get the distance from the circle to a point
   /// returns zero if the point is on the circle or positive value otherwise
   virtual EcReal pointDistanceToThisCircle
      (
      const EcVector& pt
      ) const;

   /**
    * @brief Get the distance from the disk defined by the circle to a point.
    * @param[in] pt the point
    * @param[out] closestPt the point on the disk closest to the point
    * @return EcReal zero if the point intersects the disk or positive value otherwise
    */
   virtual EcReal pointDistanceToThisDisk
      (
      const EcVector& pt,
      EcVector& closestPt
      ) const;

   /**
    * @brief Get the distance from the circle to a point.
    * @details 
    * @param[in] pt the point
    * @param[out] closestPt the point on the circle closest to the point
    * @return EcReal zero if the point intersects the circle or positive value otherwise
    */
   virtual EcReal pointDistanceToThisCircle
      (
      const EcVector& pt,
      EcVector& closestPt
      ) const;

   /// get the distance from this disk to another disk using an iterative method
   /**
   \param[in] other the other circle
   \return distance
   */
   virtual EcReal diskDistanceToThisDiskIter
      (
      const EcCircle& other
      ) const;

   /// get the distance from this disk to another disk plus return the witness points using an iterative method.
   /**
   \param[in] other the other circle
   \param[out] closestPointThis The witness point for this circle
   \param[out] closestPointOther The witness point for the other circle
   \return distance between the two witness points
   */
   virtual EcReal diskDistanceToThisDiskIter
      (
      const EcCircle& other,
      EcVector& closestPointThis,
      EcVector& closestPointOther
      ) const;

   /// get the distance from this disk to another disk using an algebraic method
   /**
   \param[in] other the other circle
   \return distance
   */
   virtual EcReal diskDistanceToThisDisk
      (
      const EcCircle& other
      ) const;

   /// get the distance from this disk to another disk plus return the witness points using an algebraic method.
   /**
   \param[in] other the other circle
   \param[out] closestPointThis The witness point for this circle
   \param[out] closestPointOther The witness point for the other circle
   \return distance between the two witness points
   */
   virtual EcReal diskDistanceToThisDisk
      (
      const EcCircle& other,
      EcVector& closestPointThis,
      EcVector& closestPointOther
      ) const;


   /// find the projection of a point onto the circle's plane
   /**
   \return True if the projected point is inside the circle or false otherwise
   */
   virtual EcBoolean calculateProjectionPoint
      (
      const EcVector& point,
      EcVector& projectionOfPoint
      ) const;

   /// find the point on the line of the line segment at which it intersects the plane containing the circle.
   /**
   \param[in] line The line segment
   \param[out] insideCircle True if the line segment intersects the plane inside the circle or false otherwise.
   \param[out] tValue The t-Value on the line segment at the intersection point.
   \param[out] intersectionPt The point at which the line segment intersects the plane.
   \return True if the line intersects the plane or false if the line is parallel to the plane.
   */
   virtual EcBoolean lineIntersectionWithPlane
      (
      const EcLineSegment& line,
      EcBoolean& insideCircle,
      EcReal& tValue,
      EcVector& intersectionPt
      ) const;

   /// find the point on the line segment at which it intersects the disk.
   virtual EcBoolean lineIntersectionWithDisk
      (
      const EcLineSegment& lineSeg,
      EcReal& tValue,
      EcVector& intersectionPt
      ) const;

   /// intersect a line segment with the circle
   /**
   \return the closest point on the surface of the shape along the line segment using the initial closest point provided in pointEvent.
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// compute the point on the edge of the circle given a direction from the center
   /**
   \param[in] direction A unit vector in the direction from the center or a zero vector.
   \param[out] point The point on the circular edge. If this is a zero vector, then the center is returned.
   */
   virtual void pointOnEdge
      (
      const EcVector& direction,
      EcVector& point
      ) const;

   /// check for intersection with a torus defined by this circle
   /**
   \param[in] tubeRadius The radius of the tube of the torus
   \param[in] seg The line segment
   \param[out] tValue The t-Value of point on the line segment closest to the disk
   \return true if intersection ocurred
   */
   virtual EcBoolean torusIntersectLineSegment
      (
      EcReal tubeRadius,
      const EcLineSegment& seg,
      EcReal& tValue
      ) const;

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
   static EcCircle nullObject
      (
      );

   /// fitting from points
   virtual EcBoolean fitting
      (
      const EcVectorVector& points
      );


protected:
   /// utility method for diskDistanceToThisDisk(const EcCircle&, EcVector&, EcVector&) const
   EcBoolean diskDistanceToThisDiskCaseAB
      (
      const EcCircle& other,
      EcReal& dist,
      EcVector& closestPointThis,
      EcVector& closestPointOther
      ) const;

   /// utility method for diskDistanceToThisDisk(const EcCircle&, EcVector&, EcVector&) const
   EcBoolean diskDistanceToThisDiskCaseD
      (
      const EcCircle& other,
      const EcVector& normalcross,
      EcReal& dist,
      EcVector& closestPointThis,
      EcVector& closestPointOther
      ) const;

   /// the plane
   EcPlane     m_Plane;
   /// the radius
   EcXmlReal   m_Radius;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the circle in an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcCircle operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcCircle& circle
   );

/// expresses the circle in a rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcCircle operator *
   (
   const EcOrientation& orient,
   const EcCircle& circle
   );

#endif // ecCircle_H_
