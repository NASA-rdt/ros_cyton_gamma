#ifndef ecDistanceCalculationTool_H_
#define ecDistanceCalculationTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecDistanceCalculationTool.h
/// @class EcDistanceCalculationTool
/// @brief Tool to compute distance between shapes
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <geometry/ecGjk.h>
#include <geometry/ecShapeStateCacheKey.h>

class EcShapeUnion;

/**
\class EcDistanceCalculationTool

This class is a tool to compute distance between shapes.
It may be moved to geometry in the future.
*/
class EC_ACTIN_GRASPING_DECL EcDistanceCalculationTool
{
public:

   /// calculates the distance between two general shapes
   /// @param[in] shapeA The first of two shapes to find the distance between
   /// @param[in] shapeB The second of two shapes to find the distance between
   /// @param[in] xform A transformation describing the pose of shapeB
   /// @param[out] witnessPointA A point on shapeA demonstrating the minimum distnce
   /// @param[out] witnessPointB A point on shapeB demonstrating the minimum distnce
   /// @param[out] shapeAId The integer ID for the component shape of ShapeA giving minimum distance
   /// @param[out] shapeBId The integer ID for the component shape of ShapeB giving minimum distance
   virtual EcReal distance
      (
      const EcShape& shapeA,
      const EcShape& shapeB,
      const EcCoordinateSystemTransformation& xform,
      EcVector& witnessPointA,
      EcVector& witnessPointB,
      EcU32& shapeAId,
      EcU32& shapeBId
      ) const;

protected:
   /// calculates the distance between two shapes neither of which is a union
   /// @param[in] shapeA The first of two shapes to find the distance between
   /// @param[in] shapeB The second of two shapes to find the distance between
   /// @param[in] xform A transformation describing the pose of shapeB
   /// @param[out] witnessPointA A point on shapeA demonstrating the minimum distnce
   /// @param[out] witnessPointB A point on shapeB demonstrating the minimum distnce
   /// @param[out] shapeAId The integer ID for the component shape of ShapeA giving minimum distance
   /// @param[out] shapeBId The integer ID for the component shape of ShapeB giving minimum distance
   virtual EcReal distanceNonUnion
      (
      const EcShape& shapeA,
      const EcShape& shapeB,
      const EcCoordinateSystemTransformation& xform,
      EcVector& witnessPointA,
      EcVector& witnessPointB,
      EcU32& shapeAId,
      EcU32& shapeBId
      ) const;

   /// calculates the distance between two shapes the first of which is a union
   /// @param[in] shapeA The first of two shapes to find the distance between
   /// @param[in] shapeB The second of two shapes to find the distance between
   /// @param[in] xform A transformation describing the pose of shapeB
   /// @param[out] witnessPointA A point on shapeA demonstrating the minimum distnce
   /// @param[out] witnessPointB A point on shapeB demonstrating the minimum distnce
   /// @param[out] shapeAId The integer ID for the component shape of ShapeA giving minimum distance
   /// @param[out] shapeBId The integer ID for the component shape of ShapeB giving minimum distance
   virtual EcReal distanceUnion
      (
      const EcShapeUnion& shapeA,
      const EcShape& shapeB,
      const EcCoordinateSystemTransformation& xform,
      EcVector& witnessPointA,
      EcVector& witnessPointB,
      EcU32& shapeAId,
      EcU32& shapeBId
      ) const;

   /// calculates the distance between two shapes the second of which is a union
   /// @param[in] shapeA The first of two shapes to find the distance between
   /// @param[in] shapeB The second of two shapes to find the distance between
   /// @param[in] xform A transformation describing the pose of shapeB
   /// @param[out] witnessPointA A point on shapeA demonstrating the minimum distnce
   /// @param[out] witnessPointB A point on shapeB demonstrating the minimum distnce
   /// @param[out] shapeAId The integer ID for the component shape of ShapeA giving minimum distance
   /// @param[out] shapeBId The integer ID for the component shape of ShapeB giving minimum distance
   virtual EcReal distanceUnion
      (
      const EcShape& shapeA,
      const EcShapeUnion& shapeB,
      const EcCoordinateSystemTransformation& xform,
      EcVector& witnessPointA,
      EcVector& witnessPointB,
      EcU32& shapeAId,
      EcU32& shapeBId
      ) const;

   /// calculates the distance between two union shapes
   /// @param[in] shapeA The first of two shapes to find the distance between
   /// @param[in] shapeB The second of two shapes to find the distance between
   /// @param[in] xform A transformation describing the pose of shapeB
   /// @param[out] witnessPointA A point on shapeA demonstrating the minimum distnce
   /// @param[out] witnessPointB A point on shapeB demonstrating the minimum distnce
   /// @param[out] shapeAId The integer ID for the component shape of ShapeA giving minimum distance
   /// @param[out] shapeBId The integer ID for the component shape of ShapeB giving minimum distance
   virtual EcReal distanceUnion
      (
      const EcShapeUnion& shapeA,
      const EcShapeUnion& shapeB,
      const EcCoordinateSystemTransformation& xform,
      EcVector& witnessPointA,
      EcVector& witnessPointB,
      EcU32& shapeAId,
      EcU32& shapeBId
      ) const;

   /// a helper GJK processor
   mutable EcGJK  m_GjkProcessor;
};

#endif // ecDistanceCalculationTool_H_
