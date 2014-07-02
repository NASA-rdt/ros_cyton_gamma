#ifndef ecScalarMultivariableFunction_H_
#define ecScalarMultivariableFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarMultivariableFunction.h
/// @class EcScalarMultivariableFunction
/// @brief Provides a base class for scalar functions of multiple
///        variables.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

/// Provides a base class for scalar functions of multiple variables.
class EC_FOUNDATION_FUNCTION_DECL EcScalarMultivariableFunction
{
public:
   /// default constructor
   EcScalarMultivariableFunction
      (
      );

   /// destructor
   virtual ~EcScalarMultivariableFunction
      (
      );

   /// copy constructor
   EcScalarMultivariableFunction
      (
      const EcScalarMultivariableFunction& orig
      );

   /// assignment operator
   EcScalarMultivariableFunction& operator=
      (
      const EcScalarMultivariableFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcScalarMultivariableFunction& orig
      ) const;

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcRealVector& vDomainValue
      ) const = 0;

   /// evaluate multiple function values
   virtual void evaluateMultiple
      (
      const EcRealVectorVector& vDomainValues,
      EcRealVector& vEvaluations
      ) const;

   /// get the domain dimensions
   virtual EcU32 domainDim
      (
      ) const = 0;
};

#endif // ecScalarMultivariableFunction_H_
