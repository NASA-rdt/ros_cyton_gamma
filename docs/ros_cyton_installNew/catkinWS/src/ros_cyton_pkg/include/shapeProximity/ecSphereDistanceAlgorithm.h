#ifndef ecSphereDistanceAlgorithm_H_
#define ecSphereDistanceAlgorithm_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSphereDistanceAlgorithm.h
/// @class EcSphereDistanceAlgorithm
/// @brief class for distance algorithm involving sphere
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecDistanceAlgorithm.h"

class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcSphereDistanceAlgorithm : public EcDistanceAlgorithm
{
public:

   /// return the shape pairs supported for distance calculation by this algorithm
   static const std::vector<EcU32U32Pair>& supportedShapePairs
      (
      );

   /// return the shape pairs supported for penetration distance calculation by this algorithm
   static const std::vector<EcU32U32Pair>& supportedPenetrationShapePairs
      (
      );

   /// \copydoc EcDistanceAlgorithm::distance()
   virtual EcBoolean distance
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& witnessPoint1,
      EcVector& witnessPoint2,
      EcReal& computedDistance
      ) const;

   /// \copydoc EcDistanceAlgorithm::penetrationDistanceAndSupportPoints()
   virtual EcBoolean penetrationDistanceAndSupportPoints
      (
      const EcShape& shape1,
      const EcShape& shape2,
      const EcCoordinateSystemTransformation& shape2InShape1,
      EcVector& supportPoint1,
      EcVector& supportPoint2,
      EcReal& penetrationDistance
      ) const;

};

#endif // ecSphereDistanceAlgorithm_H_
