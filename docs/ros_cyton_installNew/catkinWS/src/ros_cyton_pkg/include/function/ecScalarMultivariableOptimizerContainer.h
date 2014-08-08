#ifndef ecScalarMultivariableOptimizerContainer_H_
#define ecScalarMultivariableOptimizerContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarMultivariableOptimizerContainer.h
/// @class EcScalarMultivariableOptimizerContainer
/// @brief Holds an optimizer container.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeContainer.h>
#include "ecScalarMultivariableOptimizer.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcScalarMultivariableFunction;

/** Holds an optimizer container.
*/
class EC_FOUNDATION_FUNCTION_DECL EcScalarMultivariableOptimizerContainer : public EcBaseExpressionTreeContainer<EcScalarMultivariableOptimizer>
{
public:
   /// default constructor
   EcScalarMultivariableOptimizerContainer
      (
      );

   /// destructor
   virtual ~EcScalarMultivariableOptimizerContainer
      (
      );

   /// copy constructor
   EcScalarMultivariableOptimizerContainer
      (
      const EcScalarMultivariableOptimizerContainer& orig
      );

   /// assignment operator
   EcScalarMultivariableOptimizerContainer& operator=
      (
      const EcScalarMultivariableOptimizerContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcScalarMultivariableOptimizerContainer& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// find the function minimum
   virtual EcReal findMinimum
      (
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      EcRealVector& vValuesAtMinimum
      ) const;

   /// find the function maximum
   virtual EcReal findMaximum
      (
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      EcRealVector& vValuesAtMaximum
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcScalarMultivariableOptimizerContainer nullObject
      (
      );
};

#endif // ecScalarMultivariableOptimizerContainer_H_
