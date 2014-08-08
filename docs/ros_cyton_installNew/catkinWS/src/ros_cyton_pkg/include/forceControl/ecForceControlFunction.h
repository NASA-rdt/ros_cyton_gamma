#ifndef ecForceControlFunction_H_
#define ecForceControlFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceControlFunction.h
/// @class EcForceControlFunction
/// @brief The base class for force control function
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

class EC_ACTIN_FORCECONTROL_DECL EcForceControlFunction : public EcXmlCompoundType
{
public:

   /// default constructor
   EcForceControlFunction
      (
      );

   /// destructor
   virtual ~EcForceControlFunction
      (
      );

   /// copy constructor
   EcForceControlFunction
      (
      const EcForceControlFunction& orig
      );

   /// assignment operator
   EcForceControlFunction& operator=
      (
      const EcForceControlFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceControlFunction& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// reset to initial state
   virtual void reset
      (
      )=0;

   /// compute the end-effector differential based on force info
   virtual EcBoolean computeDifferential
      (
      EcReal deltaTime,
      const EcXmlRealVector& measuredForce,
      const EcXmlRealVector& desiredForce,
      EcRealVector& differential
      ) const=0;
};

#endif // ecForceControlFunction_H_
