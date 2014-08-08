#ifndef ecAxisAlignedBoundingBoxTool_H_
#define ecAxisAlignedBoundingBoxTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecAxisAlignedBoundingBoxTool.h
/// @class EcAxisAlignedBoundingBoxTool
/// @brief Helper class to create axis-aligned bounding box
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <geometry/ecBox.h>
#include <geometry/ecCapsule.h>
#include <geometry/ecCircularLozenge.h>
#include <geometry/ecCone.h>
#include <geometry/ecCylinder.h>
#include <geometry/ecEllipsoid.h>
#include <geometry/ecHalfSpace.h>
#include <geometry/ecLozenge.h>
#include <geometry/ecSphere.h>
#include <geometry/ecTetrahedron.h>
#include <geometry/ecTriangularLozenge.h>

// forward declaration
class EcShapeUnion;

/**
Helper class to create axis-aligned bounding box
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcAxisAlignedBoundingBoxTool
{
public:

   /// default constructor
   EcAxisAlignedBoundingBoxTool
      (
      );

   /// destructor
   ~EcAxisAlignedBoundingBoxTool
      (
      );

   /// compute axis aligned bounding box in system
   void axisAlignedBoundingBoxInSystem
      (
      const EcCoordinateSystemTransformation& shapePrimaryFrameInSystem,
      const EcShape& shape,
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:

   /// compute axis aligned bounding box in system
   void aabbFromShape
      (
      const EcCoordinateSystemTransformation& shapePrimaryFrameInSystem,
      const EcShape& shape,
      EcAxisAlignedBoundingBox& aabb
      ) const;

   /// compute axis aligned bounding box in union
   void aabbFromUnion
      (
      const EcCoordinateSystemTransformation& shapePrimaryFrameInSystem,
      const EcShape& shape,
      EcAxisAlignedBoundingBox& aabb
      ) const;

   /// compute axis aligned bounding box for non-union shape
   void aabbFromNonUnion
      (
      const EcCoordinateSystemTransformation& shapePrimaryFrameInSystem,
      const EcShape& shape,
      EcAxisAlignedBoundingBox& aabb
      ) const;

   /// check whether the shape type is supported
   EcBoolean isSupported
      (
      EcU32 type
      ) const;

   // The following utility variables are added to optimize for speed.
   // Note that within the code, copies of the shapes are not done by
   // copying the full object but by copying only relevant data for the
   // AABB calculations.  Copying of the shape's base class is costly.
   // For example, surface properties are not needed for the AABBs.

   /// mutable member variables
   mutable EcBox               m_LocalBox;
   /// mutable member variables
   mutable EcCapsule           m_LocalCapsule;
   /// mutable member variables
   mutable EcCircularLozenge   m_LocalCircularLozenge;
   /// mutable member variables
   mutable EcCone              m_LocalCone;
   /// mutable member variables
   mutable EcCylinder          m_LocalCylinder;
   /// mutable member variables
   mutable EcEllipsoid         m_LocalEllipsoid;
   /// mutable member variables
   mutable EcHalfSpace         m_LocalHalfSpace;
   /// mutable member variables
   mutable EcLozenge           m_LocalLozenge;
   /// mutable member variables
   mutable EcSphere            m_LocalSphere;
   /// mutable member variables
   mutable EcTetrahedron       m_LocalTetrahedron;
   /// mutable member variables
   mutable EcTriangularLozenge m_LocalTriangularLozenge;
};

#endif // ecAxisAlignedBoundingBoxTool_H_
