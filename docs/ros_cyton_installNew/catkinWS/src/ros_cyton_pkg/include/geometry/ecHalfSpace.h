#ifndef ecHalfSpace_H_
#define ecHalfSpace_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecHalfSpace.h
/// @class EcHalfSpace
/// @brief Defines a half-space. A half-space is all the space on
///        the side of a plane, in the direction of the normal vector
///        Represent it as a point and a normal
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShape.h"
#include "ecPlane.h"
#include <xml/ecXmlVector.h>

// forward declarations
class EcAxisAlignedBoundingBox;
class EcCoordinateSystemTransformation;

/** Holds a class to describe a half-space
*/
class EC_FOUNDATION_GEOMETRY_DECL EcHalfSpace : public EcShape
{
public:
   /// default constructor
   EcHalfSpace
      (
      );

   /// destructor
   virtual ~EcHalfSpace
      (
      );

   /// copy constructor
   EcHalfSpace
      (
      const EcHalfSpace& orig
      );

   /// assignment operator
   EcHalfSpace& operator=
      (
      const EcHalfSpace& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcHalfSpace& orig
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

   /// return the  plane
   virtual const EcPlane& plane
      (
      ) const;

   /// set the plane
   virtual void setPlane
      (
         const EcPlane& plane
      );

   /// return size of cube rendering
   virtual EcReal cubeRenderSize
      (
      ) const;

   /// set the cube render size
   virtual void setCubeRenderSize
      (
         EcReal size
      );

   /// return the  parallel vector
   virtual const EcVector& parallel
      (
      ) const;

   /// set the parallel vector
   virtual void setParallel
      (
         const EcVector& parallel
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
   /// returns zero if they are just touching and a
   /// negative number if they overlap.
   virtual EcReal distanceTo
      (
      const EcLineSegment& line
      ) const;

   /// get the distance to a point and the closest points
   /// returns zero if they are just touching and a
   /// negative number if they overlap.
   virtual EcReal distanceTo
      (
      const EcLineSegment& line,
      EcVector& closestOnPlane,
      EcVector& closestOnLine
      ) const;

   /// get the distance to a point
   /// returns zero if the point is on the surface of the
   /// capsule and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// get the distance to a point and the closest point
   /// returns zero if the point is on the surface of the
   /// capsule and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec,
      EcVector& closest
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
   static EcHalfSpace nullObject
      (
      );

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const;

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

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
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
      ) const ;

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

   /// init parallel vector
   virtual void initParallel
      (
      );

protected:

   /// plane that defines half space
   EcPlane   m_Plane;

   /// render size of cube
   EcXmlReal m_CubeRenderSize;

   /// parallel vector (non-XML)
   EcVector m_Parallel;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the capsule into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcHalfSpace operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcHalfSpace& m
   );

#endif // ecHalfSpace_H_
