#ifndef ecShapeCollisionTool_H_
#define ecShapeCollisionTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeCollisionTool.h
/// @class EcShapeCollisionTool
/// @brief Helper class for computing collision data between shapes
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecProximityKey.h"

#include <geometry/ecShape.h>


// forward declaration
class EcDistanceAlgorithm;
class EcSystemShapeCollisionCache;

/** Helper class for computing collision data between shapes
*/

class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcShapeCollisionTool
{
public:

   /// default constructor
   EcShapeCollisionTool
      (
      );

   /// destructor
   virtual ~EcShapeCollisionTool
      (
      );

   /// copy constructor
   EcShapeCollisionTool
      (
      const EcShapeCollisionTool& orig
      );

   /// assignment operator
   EcShapeCollisionTool& operator=
      (
      const EcShapeCollisionTool& orig
      );

   /// compute the penetration distance and support points between two shapes
   virtual EcBoolean penetrationDistanceAndSupportPoints
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& supportPoint1,
      EcVector& supportPoint2,
      EcReal& penetrationDistance
      ) const;

   /// compute the collision data between two shapes and store it in the cache
   EcBoolean computeCollisionData
      (
      const EcLinkKey& link1,
      const EcLinkKey& link2,
      const EcShape& shape1,
      const EcShape& shape2,
      EcBoolean shape1Consolidated,
      EcBoolean shape2Consolidated,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcSystemShapeCollisionCache& collisionCache,
      EcShapeProximityKeyVector& intersectingShapes,
      EcReal& penetrationDistance
      ) const;

protected:
   /// compute the penetration distance and support points between two non-union shapes
   EcBoolean penetrationDistanceNonUnion
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& supportPoint1,
      EcVector& supportPoint2,
      EcReal& penetrationDistance
      ) const;

   /// compute the collision data between two non-union shapes and store it in the cache
   EcBoolean computeCollisionDataNonUnion
      (
      const EcLinkKey& link1,
      const EcLinkKey& link2,
      const EcShape& shape1,
      const EcShape& shape2,
      EcBoolean shape1Consolidated,
      EcBoolean shape2Consolidated,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcSystemShapeCollisionCache& collisionCache,
      EcShapeProximityKeyVector& intersectingShapes,
      EcReal& penetrationDistance
      ) const;

   /// create distance algorithms for all pairs of shapes
   void createDistanceAlgorithms
      (
      );

   /// create distance algorithms for a pair of shapes
   EcDistanceAlgorithm* createDistanceAlgorithm
      (
      EcU32 shapeType1,
      EcU32 shapeType2
      );

   enum
   {
      MAX_SHAPE_TYPES = EcShape::UNION
   };

   /// the distance algorithms
   EcDistanceAlgorithm* m_DistanceAlgorithms[MAX_SHAPE_TYPES][MAX_SHAPE_TYPES];
};

#endif // ecShapeCollisionTool_H_
