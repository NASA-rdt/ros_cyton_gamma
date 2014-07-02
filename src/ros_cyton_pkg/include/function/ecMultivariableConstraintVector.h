#ifndef ecMultivariableConstraintVector_H_
#define ecMultivariableConstraintVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultivariableConstraintVector.h
/// @class EcMultivariableConstraintVector
/// @brief The vector of multivariable constraints
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseMultivariableConstraint.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of XML variable vector of EcBaseMultivariableConstraint to be used as a base class
typedef EcXmlVariableVectorType<EcBaseMultivariableConstraint> EcBaseMultivariableConstraintVector;

class EC_FOUNDATION_FUNCTION_DECL EcMultivariableConstraintVector :
   public EcBaseMultivariableConstraintVector
{
public:
   /// default constructor
   EcMultivariableConstraintVector
      (
      );

   /// destructor
   virtual ~EcMultivariableConstraintVector
      (
      );

   /// copy constructor
   EcMultivariableConstraintVector
      (
      const EcMultivariableConstraintVector& orig
      );

   /// assignment operator
   EcMultivariableConstraintVector& operator=
      (
      const EcMultivariableConstraintVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultivariableConstraintVector& orig
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
   static EcMultivariableConstraintVector nullObject
      (
      );
};

#endif // ecMultivariableConstraintVector_H_
