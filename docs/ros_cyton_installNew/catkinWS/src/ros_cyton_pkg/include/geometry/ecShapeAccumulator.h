#ifndef ecShapeAccumulator_H_
#define ecShapeAccumulator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeAccumulator.h
/// @class EcShapeAccumulator
/// @brief Accumulator class for managing shapes.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShapeUnion.h"

#include <boost/shared_ptr.hpp>

/// Accumulator class for managing shapes.
class EC_FOUNDATION_GEOMETRY_DECL EcShapeAccumulator
{
public:
   /// boost::shared_ptr of EcShape
   typedef boost::shared_ptr<EcShape> ShapePtr;

   /// default constructor
   EcShapeAccumulator
      (
      );

   /// destructor
   ~EcShapeAccumulator
      (
      );

   /// copy constructor
   EcShapeAccumulator
      (
      const EcShapeAccumulator& orig
      );

   /// assignment operator
   EcShapeAccumulator& operator=
      (
      const EcShapeAccumulator& rhs
      );

   /// add a shape
   void addShape
      (
      ShapePtr pShape
      );

   /// clear the accumulated shape
   void clear
      (
      );

   /// return the accumulated shape
   const EcShape& accumulatedShape
      (
      ) const;

   /// return the number of shapes that are currently accumulated
   EcU32 numShapesAccumulated
      (
      ) const;

private:
   EcU32          m_NumShapes;
   ShapePtr       m_pShape;
   EcShapeUnion   m_ShapeUnion;
};

#endif // ecShapeAccumulator_H_
