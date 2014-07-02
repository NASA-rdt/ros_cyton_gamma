#ifndef ecDissipativeForceProcessorContainer_H_
#define ecDissipativeForceProcessorContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDissipativeForceProcessorContainer.h
/// @class EcDissipativeForceProcessorContainer
/// @brief Defines a class for computing dissipative (non-conservative)
///        forces.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeContainer.h>
#include "ecBaseDissipativeForceProcessor.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// Defines a class for computing dissipative (non-conservative) forces
class EC_FOUNDATION_MANIPULATOR_DECL EcDissipativeForceProcessorContainer : public EcBaseExpressionTreeContainer<EcBaseDissipativeForceProcessor>
{
public:
   /// default constructor
   EcDissipativeForceProcessorContainer
      (
      );

   /// destructor
   virtual ~EcDissipativeForceProcessorContainer
      (
      );

   /// copy constructor
   EcDissipativeForceProcessorContainer
      (
      const EcDissipativeForceProcessorContainer& orig
      );

   /// assignment operator
   EcDissipativeForceProcessorContainer& operator=
      (
      const EcDissipativeForceProcessorContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDissipativeForceProcessorContainer& orig
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

   /// set the friction coefficient lookup tool
   virtual void setFrictionCoeficientLookupTool
      (
      const EcFrictionCoefficientLookupTool& frictionCoefficientLookupTool
      );

   /// get a null object
   static EcDissipativeForceProcessorContainer nullObject
      (
      );
};

#endif // ecDissipativeForceProcessorContainer_H_
