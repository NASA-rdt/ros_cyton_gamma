#ifndef ecIntegratorContainer_H_
#define ecIntegratorContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecIntegratorContainer.h
/// @class EcIntegratorContainer
/// @brief Holds a container for a numerical integrator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include "ecBaseIntegrator.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// Holds a container for a numerical integrator.
class EC_ACTIN_SIMULATION_DECL EcIntegratorContainer : public EcXmlVariableElementType<EcBaseIntegrator>
{
public:
   /// default constructor
   EcIntegratorContainer
      (
      );

   /// destructor
   virtual ~EcIntegratorContainer
      (
      );

   /// copy constructor
   EcIntegratorContainer
      (
      const EcIntegratorContainer& orig
      );

   /// assignment operator
   EcIntegratorContainer& operator=
      (
      const EcIntegratorContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIntegratorContainer& orig
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
   static EcIntegratorContainer nullObject
      (
      );
};

#endif // ecIntegratorContainer_H_
