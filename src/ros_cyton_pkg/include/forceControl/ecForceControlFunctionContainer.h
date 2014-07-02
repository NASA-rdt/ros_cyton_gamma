#ifndef ecForceControlFunctionContainer_H_
#define ecForceControlFunctionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceControlFunctionContainer.h
/// @class EcForceControlFunctionContainer
/// @brief The container class for force control function
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceControlFunction.h"

#include <xml/ecXmlVarElemType.h>

class EcForceControlFunction;

class EC_ACTIN_FORCECONTROL_DECL EcForceControlFunctionContainer : public EcXmlVariableElementType<EcForceControlFunction>
{
public:

   /// default constructor
   EcForceControlFunctionContainer
      (
      );

   /// destructor
   virtual ~EcForceControlFunctionContainer
      (
      );

   /// copy constructor
   EcForceControlFunctionContainer
      (
      const EcForceControlFunctionContainer& orig
      );

   /// assignment operator
   EcForceControlFunctionContainer& operator=
      (
      const EcForceControlFunctionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceControlFunctionContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   /**
       \return string token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \return cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// pass-through \see EcForceControlFunction::reset()
   virtual void reset
      (
      );

   /// pass-through \see EcForceControlFunction::computeDifferential()
   virtual EcBoolean computeDifferential
      (
      EcReal deltaTime,
      const EcXmlRealVector& measuredForce,
      const EcXmlRealVector& desiredForce,
      EcRealVector& differentail
      ) const;

};

/// an XML map of force controller containers
typedef EcXmlMapType<EcXmlString,EcForceControlFunctionContainer> EcForceControlFunctionContainerMap;

#endif // ecForceControlFunctionContainer_H_
