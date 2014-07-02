#ifndef ecScalarMultivariableOptimizer_H_
#define ecScalarMultivariableOptimizer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarMultivariableOptimizer.h
/// @class EcScalarMultivariableOptimizer
/// @brief Holds a description of a base class for optimizers.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>
#include <matrixUtilities/ecReArray.h>

class EcScalarMultivariableFunction;

/** Holds a description of a base class for optimizers.
*/
class EC_FOUNDATION_FUNCTION_DECL EcScalarMultivariableOptimizer : public EcBaseExpressionTreeElement
{
public:
   /// default constructor - should not be used
   EcScalarMultivariableOptimizer
      (
      );

   /// destructor
   virtual ~EcScalarMultivariableOptimizer
      (
      );

   /// copy constructor
   EcScalarMultivariableOptimizer
      (
      const EcScalarMultivariableOptimizer& orig
      );

   /// assignment operator
   EcScalarMultivariableOptimizer& operator=
      (
      const EcScalarMultivariableOptimizer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcScalarMultivariableOptimizer& orig
      ) const;

   /// find the function minimum
   virtual EcReal findMinimum
      (
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      EcRealVector& vValuesAtMinimum
      ) const = 0;

   /// find the function maximum
   virtual EcReal findMaximum
      (
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      EcRealVector& vValuesAtMaximum
      ) const = 0;
};

#endif // ecScalarMultivariableOptimizer_H_
