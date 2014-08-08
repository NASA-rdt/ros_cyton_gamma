#ifndef ecCapsule_H_
#define ecCapsule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCapsule.h
/// @class EcCapsule
/// @brief Holds a class to describe a 3D capsule (a distance
///        from a line segment).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLineSegment.h"
#include "ecShape.h"
#include <xml/ecXmlVector.h>

class EcAxisAlignedBoundingBox;
class EcBasePhysicalExtent;

/// Holds a class to describe a 3D capsule (a distance from a line segment).
class EC_FOUNDATION_GEOMETRY_DECL EcCapsule : public EcShape
{
public:
   /**
    * @brief Default constructor.
    * @details Constructs a capsule with radius of 0.1 units and a length of 0.2 units.
    * @return 
    */
   EcCapsule
      (
      );

   /// constructor from a line segment and a radius
   EcCapsule
      (
      const EcLineSegment lineSegment,
      EcReal radius
      );

   /// destructor
   virtual ~EcCapsule
      (
      );

   /// copy constructor
   EcCapsule
      (
      const EcCapsule& orig
      );

   /// assignment operator
   EcCapsule& operator=
      (
      const EcCapsule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCapsule& orig
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

   /**
    * @brief Get the distance to a line segment.
    * @details Returns zero if they are just touching and a negative number if they overlap.
    * @param[in] lineSeg
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcLineSegment& lineSeg
      ) const;

   /**
    * @brief Get the distance to a point.
    * @details Returns zero if the point is on the surface of the capsule
    *          and a negative number if it is inside.
    * @param[in] vec
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /**
    * @copydoc EcShape::intersectLineSegment()
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

   /// expand the capsule to include the set of points passed in
   virtual EcBoolean expandToInclude
      (
      const EcXmlVectorVector & points
      );

   /// expand the capsule to include another capsule
   virtual EcBoolean expandToInclude
      (
      const EcCapsule & otherCapsule
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
   static EcCapsule nullObject
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

   /// the line segment running the length of the capsule
   EcLineSegment m_LineSegment;

   /// the radius
   EcXmlReal m_Radius;

   /// utility vector for fitFromShape
   mutable EcXmlVectorVector m_UsedPointVec;
};

/// A vector of line segments
typedef EcXmlVectorType<EcCapsule> EcCapsuleVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the capsule into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcCapsule operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcCapsule& m
   );

#endif // ecCapsule_H_
