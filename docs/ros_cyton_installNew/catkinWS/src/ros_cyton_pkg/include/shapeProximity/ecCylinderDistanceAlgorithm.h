#ifndef ecCylinderDistanceAlgorithm_H_
#define ecCylinderDistanceAlgorithm_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecCylinderDistanceAlgorithm.h
/// @class EcCylinderDistanceAlgorithm
/// @brief class for distance algorithm involving cylinder
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecDistanceAlgorithm.h"

#include <geometry/ecGjk.h>

class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcCylinderDistanceAlgorithm : public EcDistanceAlgorithm
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

protected:
   /// GJK used to compute deep penetration cases
   mutable EcGJK  m_GjkProcessor;
};

#endif // ecCylinderDistanceAlgorithm_H_
