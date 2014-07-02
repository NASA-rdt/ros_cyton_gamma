#ifndef ecJointActuatorContainer_H_
#define ecJointActuatorContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointActuatorContainer.h
/// @class EcJointActuatorContainer
/// @brief Holds a container for joint actuator description.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include "ecBaseJointActuator.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// Holds a container for joint actuator description.
/**
\todo This is here only for backward-compatibility. It will be removed in version 3.0.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcJointActuatorContainer : public EcXmlVariableElementType<EcBaseJointActuator>
{
public:
   /// default constructor
   EcJointActuatorContainer
      (
      );

   /// destructor
   virtual ~EcJointActuatorContainer
      (
      );

   /// copy constructor
   EcJointActuatorContainer
      (
      const EcJointActuatorContainer& orig
      );

   /// assignment operator
   EcJointActuatorContainer& operator=
      (
      const EcJointActuatorContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointActuatorContainer& orig
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
   static EcJointActuatorContainer nullObject
      (
      );
};

#endif // ecJointActuatorContainer_H_
