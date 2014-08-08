#ifndef ecDistanceAlgorithm_H_
#define ecDistanceAlgorithm_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecDistanceAlgorithm.h
/// @class EcDistanceAlgorithm
/// @brief Virtual base class for distance algorithm
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

// forward declaration
class EcCoordinateSystemTransformation;
class EcShape;
class EcVector;

class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcDistanceAlgorithm
{
public:
   virtual ~EcDistanceAlgorithm() {}

   /// compute the distance between two shapes
   virtual EcBoolean distance
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcReal& computedDistance
      ) const;

   /// compute the distance between two shapes
   virtual EcBoolean distance
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& witnessPoint1,
      EcVector& witnessPoint2,
      EcReal& computedDistance
      ) const = 0;

   /// compute the penetration distance and support points between two shapes
   virtual EcBoolean penetrationDistanceAndSupportPoints
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& supportPoint1,
      EcVector& supportPoint2,
      EcReal& penetrationDistance
      ) const = 0;
};

#endif // ecDistanceAlgorithm_H_
