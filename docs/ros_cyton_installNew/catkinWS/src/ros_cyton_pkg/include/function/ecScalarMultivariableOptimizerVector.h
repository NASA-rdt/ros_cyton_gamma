#ifndef ecScalarMultivariableOptimizerVector_H_
#define ecScalarMultivariableOptimizerVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarMultivariableOptimizerVector.h
/// @class EcScalarMultivariableOptimizerVector
/// @brief Holds a description of a vector of image transform objects.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>
#include "ecScalarMultivariableOptimizer.h"

/// type definition of EcXmlVariableVectorType<EcScalarMultivariableOptimizer> to be used as a base class
typedef EcXmlVariableVectorType<EcScalarMultivariableOptimizer> EcBaseScalarMultivariableOptimizerVector;

/** Holds a description of a vector of image transform objects.
*/
class EC_FOUNDATION_FUNCTION_DECL EcScalarMultivariableOptimizerVector : public EcBaseScalarMultivariableOptimizerVector
{
public:
   /// default constructor
   EcScalarMultivariableOptimizerVector
      (
      );

   /// destructor
   virtual ~EcScalarMultivariableOptimizerVector
      (
      );

   /// copy constructor
   EcScalarMultivariableOptimizerVector
      (
      const EcScalarMultivariableOptimizerVector& orig
      );

   /// assignment operator
   EcScalarMultivariableOptimizerVector& operator=
      (
      const EcScalarMultivariableOptimizerVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcScalarMultivariableOptimizerVector& orig
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

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
   static EcScalarMultivariableOptimizerVector nullObject
      (
      );
};

#endif // ecScalarMultivariableOptimizerVector_H_
