#ifndef ecConvexDistanceAlgorithm_H_
#define ecConvexDistanceAlgorithm_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecConvexDistanceAlgorithm.h
/// @class EcConvexDistanceAlgorithm
/// @brief class for distance algorithm involving convex shapes
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecDistanceAlgorithm.h"

#include <geometry/ecGjk.h>

class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcConvexDistanceAlgorithm : public EcDistanceAlgorithm
{
public:

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

   /// get proximity vector
   inline const EcVector& proximityVector
      (
      ) const
   {
      return m_ProximityVector;
   }

   /// set proximity vector
   inline void setProximityVector
      (
      const EcVector& value
      )
   {
      m_ProximityVector=value;
   }

protected:
   /// GJK used to compute deep penetration cases
   mutable EcGJK     m_GjkProcessor;
   /// proximity vector
   mutable EcVector  m_ProximityVector;
};

#endif // ecConvexDistanceAlgorithm_H_
