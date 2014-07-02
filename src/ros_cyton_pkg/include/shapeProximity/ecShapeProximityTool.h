#ifndef ecShapeProximityTool_H_
#define ecShapeProximityTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeProximityTool.h
/// @class EcShapeProximityTool
/// @brief Helper class to calculate distance between shapes
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <geometry/ecShape.h>

// forward declaration
class EcDistanceAlgorithm;

/**
Helper class to calculate distance between shapes
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcShapeProximityTool
{
public:

   /// default constructor
   EcShapeProximityTool
      (
      );

   /// destructor
   virtual ~EcShapeProximityTool
      (
      );

   /// function: distance
   /// compute the distance between two shapes
   EcBoolean distance
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcReal& computedDistance
      ) const;

   /// function: distance
   /// compute the distance between two shapes
   EcBoolean distance
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& witnessPoint1,
      EcVector& witnessPoint2,
      EcReal& computedDistance
      ) const;

protected:
   /// compute the distance between two non-union shapes
   virtual EcBoolean distanceNonUnion
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcReal& computedDistance
      ) const;

   /// compute the distance between two non-union shapes
   virtual EcBoolean distanceNonUnion
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& witnessPoint1,
      EcVector& witnessPoint2,
      EcReal& computedDistance
      ) const;

   /// create distance algorithms for all pairs of shapes
   virtual void createDistanceAlgorithms
      (
      );

   /// create distance algorithms for a pair of shapes
   virtual EcDistanceAlgorithm* createDistanceAlgorithm
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

#endif // ecShapeProximityTool_H_
