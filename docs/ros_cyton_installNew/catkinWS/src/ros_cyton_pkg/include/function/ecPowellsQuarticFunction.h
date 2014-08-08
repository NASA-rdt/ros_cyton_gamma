#ifndef ecPowellsQuarticFunction_H_
#define ecPowellsQuarticFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPowellsQuarticFunction.h
/// @class EcPowellsQuarticFunction
/// @brief Provides an example function for testing.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecScalarMultivariableFunction.h"

/// Provides an example function for testing.
/** From "An Iterative Method
    for Finding Stationary Value of a Function of Several Variables,"
    The Computer Journal, vol. 5, p. 147, 1962.
*/
class EC_FOUNDATION_FUNCTION_DECL EcPowellsQuarticFunction : public EcScalarMultivariableFunction
{
public:
   /// default constructor
   EcPowellsQuarticFunction
      (
      );

   /// destructor
   virtual ~EcPowellsQuarticFunction
      (
      );

   /// copy constructor
   EcPowellsQuarticFunction
      (
      const EcPowellsQuarticFunction& orig
      );

   /// assignment operator
   EcPowellsQuarticFunction& operator=
      (
      const EcPowellsQuarticFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPowellsQuarticFunction& orig
      ) const;

   /// get multiplier
   virtual EcReal multiplier
      (
      ) const;

   /// set multiplier
   virtual void setMultiplier
      (
      EcReal multiplier
      );

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcRealVector& vDomainValue
      ) const;

   /// get the domain dimensions
   virtual EcU32 domainDim
      (
      ) const;

protected:
   /// a multiplier for the function
   EcReal                      m_Multiplier;
};

#endif // ecPowellsQuarticFunction_H_
