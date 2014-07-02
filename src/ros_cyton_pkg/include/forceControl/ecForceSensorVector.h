#ifndef ecForceSensorVector_H_
#define ecForceSensorVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceSensorVector.h
/// @class EcForceSensorVector
/// @brief Holds a description of a vector of force sensors.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceSensor.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// vector of EcForceSensor
typedef EcXmlVariableVectorType<EcForceSensor> EcBaseForceSensorVector;

/// Holds a description of a vector of force sensors.
class EC_ACTIN_FORCECONTROL_DECL EcForceSensorVector : public EcBaseForceSensorVector
{
public:
   /// default constructor
   EcForceSensorVector
      (
      );

   /// destructor
   virtual ~EcForceSensorVector
      (
      );

   /// copy constructor
   EcForceSensorVector
      (
      const EcForceSensorVector& orig
      );

   /// assignment operator
   EcForceSensorVector& operator=
      (
      const EcForceSensorVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceSensorVector& orig
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

   /// get a null object
   static EcForceSensorVector nullObject
      (
      );

   /// given a force sensor token name, return a force sensor object
   virtual EcForceSensor* forceSensorFromToken
      (
      const EcToken& token
      );
};

#endif // ecForceSensorVector_H_
