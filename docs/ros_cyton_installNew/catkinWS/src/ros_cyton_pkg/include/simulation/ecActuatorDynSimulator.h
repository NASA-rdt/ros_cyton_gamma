#ifndef ecActuatorDynSimulator_H_
#define ecActuatorDynSimulator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecActuatorDynSimulator.h
/// @class EcActuatorDynamicSimulator
/// @brief Holds a dynamic simulator for an individual manipulator.
///        This class takes as input joint torques and updates the
///        manipulator state.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <manipulator/ecPositionState.h>

#include "ecIntegratorContainer.h"

class EcManipulatorControlInput;
class EcManipulatorTorque;
class EcIndividualManipulator;
class EcManipulatorActiveState;

/// Holds a dynamic simulator for an individual manipulator.
/** This class
takes as input joint torques and updates the manipulator state.
*/
class EC_ACTIN_SIMULATION_DECL EcActuatorDynamicSimulator : public EcXmlCompoundType
{
public:
   /// default constructor
   EcActuatorDynamicSimulator
      (
      );

   /// destructor
   virtual ~EcActuatorDynamicSimulator
      (
      );

   /// copy constructor
   EcActuatorDynamicSimulator
      (
      const EcActuatorDynamicSimulator& orig
      );

   /// assignment operator
   EcActuatorDynamicSimulator& operator=
      (
      const EcActuatorDynamicSimulator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcActuatorDynamicSimulator& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the time step
   virtual EcReal timeStep
      (
      ) const;

   /// sets the time step for all integrators
   virtual void setTimeStep
      (
      EcReal timeStep
      );

   /// sets the integration order for all integrators
   virtual void setIntegrationOrder
      (
      EcU32 value
      );

   /// set the integrator to all internal integrators. This can be call instead of many call to set individual integrators.
   /// Note that the integration order and time step of the integrators will be set to those specified in this class.
   virtual void setIntegrators
      (
      const EcBaseIntegrator& value
      );

   /// get the integrator container for joint actuators
   virtual const EcIntegratorContainer& actuatorMotionIntegratorContainer
      (
      ) const;

   /// set the integrator container for joint actuators.
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setActuatorMotionIntegratorContainer
      (
      const EcIntegratorContainer& integrator
      );

   /// set the integrator for joint actuators.
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setActuatorMotionIntegrator
      (
      const EcBaseIntegrator& integrator
      );

   /// get the integrator container for power converters in actuators
   virtual const EcIntegratorContainer& powerConverterIntegratorContainer
      (
      ) const;

   /// set the integrator container for power converters in actuators
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setPowerConverterIntegratorContainer
      (
      const EcIntegratorContainer& integrator
      );

   /// set the integrator for power converters in actuators
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setPowerConverterIntegrator
      (
      const EcBaseIntegrator& integrator
      );

   /// properly size the integration states
   virtual void configureIntegrationStates
      (
      );

   /// simulate one step using the integrator
   virtual EcBoolean simulateOneStep
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorTorque& torque,
      EcManipulatorActiveState& activeState
      );

   /// simulate one step using the integrator
   virtual EcBoolean simulateOneStep
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorControlInput& controlInput,
      const EcManipulatorTorque& torque,
      EcManipulatorActiveState& activeState
      );

   /// initialize the rotating buffer
   virtual EcBoolean initialize
      (
      );

   /// gets the xml token used for writing out
   virtual const EcToken& token
      (
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
   static EcActuatorDynamicSimulator nullObject
      (
      );

protected:
   /// integrate the motion of actuators
   virtual void integrateActuatorMotion
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorTorque& torque,
      EcManipulatorActiveState& activeState
      );

   /// integrate the power converter state of actuators
   virtual void integratePowerConverterState
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorControlInput& controlInput,
      EcManipulatorActiveState& activeState
      );

protected:
   /// integrator used for integrating accelerations of joint actuators
   EcIntegratorContainer      m_ActuatorMotionIntegrator;

   /// integrator used for integrating derivatives of power converter states
   EcIntegratorContainer      m_PowerConverterIntegrator;

   // non-XML data below
   /// derivatives of power converter states for a single actuator
   EcXmlRealVector            m_SingleStateDerivatives;

   /// copy of power converter states for the whole manipulator used for integration
   EcXmlRealVector            m_PowerConverterStates;

   /// derivatives of power converter states for the whole manipulator used for integration
   EcXmlRealVector            m_PowerConverterStateDerivatives;

   /// time step for all integrators
   EcReal                     m_TimeStep;

   /// integration order for all integrators
   EcU32                      m_IntegrationOrder;
};

#endif // ecActuatorDynSimulator_H_
