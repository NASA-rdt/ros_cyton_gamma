#ifndef ecSphere_H_
#define ecSphere_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSphere.h
/// @class EcSphere
/// @brief Holds a class to describe a 3D sphere.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShape.h"
#include <xml/ecXmlVector.h>

class EcAxisAlignedBoundingBox;

/// Holds a class to describe a 3D sphere.
class EC_FOUNDATION_GEOMETRY_DECL EcSphere : public EcShape
{
public:
   /// default constructor
   EcSphere
      (
      );

   /// constructor from a line segment and a radius
   EcSphere
      (
      const EcVector center,
      EcReal radius,
      EcInt32 detailLevel=3
      );

   /// destructor
   virtual ~EcSphere
      (
      );

   /// copy constructor
   EcSphere
      (
      const EcSphere& orig
      );

   /// assignment operator
   EcSphere& operator=
      (
      const EcSphere& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSphere& orig
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

   /// get center
   virtual const EcVector& center
      (
      ) const;

   /// set line segment
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

   /// get the distance to line segment
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

   /// check the intersection with line segment
   virtual EcBoolean checkIntersect
      (
      const EcLineSegment& line
      ) const;

   /**
   \copydoc EcShape::intersectLineSegment()
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const;

   /// returns true if this sphere contains the other sphere
   virtual EcBoolean contains
      (
      const EcSphere& other
      ) const;

   /// returns true if this sphere contains the point
   virtual EcBoolean contains
      (
      const EcVector& pt
      ) const;

   /// expand this sphere to include another one.  The result
   /// is the smallest-radius sphere that includes both this and
   /// the other sphere
   virtual void expandSelfToInclude
      (
      const EcSphere& other
      );

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

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const;

   /// get an empty polygon
   static EcSphere nullObject
      (
      );

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
      const EcShape& shape
      );

   /// get support point index given a vector
   virtual EcVector supportPoint
      (
      const EcVector& v
      ) const;


   /// the creator function for this object
   static EcXmlObject* creator
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// intersect a line segment with the sphere, returning the closest
   /// point along the line segment using the initial closest point
   /// provided in pointEvent.
   /**
   \param[in] center The center of the sphere.
   \param[in] radius The radius of the sphere.
   \param[in] lineSegment The line segment used for intersection.
   \param[out] pointEvent The description of the interesection.
   */
   static void intersectSphereWithLineSegment
      (
      const EcVector& center,
      EcReal radius,
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
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
   /// the center of the sphere
   EcXmlVector m_Center;

   /// the radius
   EcXmlReal   m_Radius;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

class EcCoordinateSystemTransformation;

/// expresses the sphere into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcSphere operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcSphere& sp
   );

#endif // ecSphere_H_
