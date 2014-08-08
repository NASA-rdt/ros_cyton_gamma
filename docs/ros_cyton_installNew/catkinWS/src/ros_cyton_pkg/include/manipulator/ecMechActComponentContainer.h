#ifndef ecMechActComponentContainer_H_
#define ecMechActComponentContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecMechActComponentContainer.h
/// @class EcMechanicalActuatorComponentContainer
/// @brief Holds a container for mechanical component of a joint actuator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include "ecMechActComponent.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/**
Holds a container for mechanical component of a joint actuator.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcMechanicalActuatorComponentContainer : public EcXmlVariableElementType<EcMechanicalActuatorComponent>
{
public:
   /// default constructor
   EcMechanicalActuatorComponentContainer
      (
      );

   /// destructor
   virtual ~EcMechanicalActuatorComponentContainer
      (
      );

   /// copy constructor
   EcMechanicalActuatorComponentContainer
      (
      const EcMechanicalActuatorComponentContainer& orig
      );

   /// assignment operator
   EcMechanicalActuatorComponentContainer& operator=
      (
      const EcMechanicalActuatorComponentContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMechanicalActuatorComponentContainer& orig
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

   /// calculate the total output torque of this actuator's mechanical component. This is just a pass-through to the element of this container. If there's no element, then it just returns the input torque.
   /**
   \param[in] inputTorque The input controlled torque
   \param[in] linkTorque The torque from the manipulator link attached to this actuator.
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal outputTorque
      (
      EcReal inputTorque,
      EcReal linkTorque,
      EcManipulatorActiveState& activeState
      ) const;

   /// calculate the linear local torque of this actuator's mechanical component. This is just a pass-through to the element of this container. If there's no element, then it just returns 0.
   /**
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal linearTorque
      (
      EcManipulatorActiveState& activeState
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
   static EcMechanicalActuatorComponentContainer nullObject
      (
      );
};

#endif // ecMechActComponentContainer_H_
