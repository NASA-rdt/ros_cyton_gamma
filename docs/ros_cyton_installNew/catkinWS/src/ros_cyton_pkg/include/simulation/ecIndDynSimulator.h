#ifndef ecIndDynSimulator_H_
#define ecIndDynSimulator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecIndDynSimulator.h
/// @class EcIndividualDynamicSimulator
/// @brief Holds a dynamic simulator for an individual manipulator.
///        This class takes as input joint torques and updates the
///        manipulator state.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <manipulator/ecPositionState.h>
#include <manipulator/ecVelocityState.h>
#include <manipulator/ecAccelerationState.h>
#include <manipulator/ecCrbiAccelerationTool.h>
#include <manipulator/ecArbiAccelerationTool.h>

#include "ecActuatorDynSimulator.h"
#include "ecIntegratorContainer.h"

class EcIndividualManipulator;
class EcManipulatorControlInput;
class EcManipulatorTorque;
class EcStatedSystem;

/// Holds a dynamic simulator for an individual manipulator.
/** This class takes as input joint torques and updates the manipulator state.
*/
class EC_ACTIN_SIMULATION_DECL EcIndividualDynamicSimulator : public EcXmlCompoundType
{
public:
   /// simulation type enumeration
   enum {AUTOMATIC, CRBI, CRBI_PAUL, ARBI};

   /// integration method enumeration
   //enum {RUNGE_KUTTA, ADAMS_BASHFORTH, ADAMS_BASHFORTH_MOULTON};

   /// default constructor
   EcIndividualDynamicSimulator
      (
      );

   /// destructor
   virtual ~EcIndividualDynamicSimulator
      (
      );

   /// copy constructor
   EcIndividualDynamicSimulator
      (
      const EcIndividualDynamicSimulator& orig
      );

   /// assignment operator
   EcIndividualDynamicSimulator& operator=
      (
      const EcIndividualDynamicSimulator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIndividualDynamicSimulator& orig
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

   /// gets the field of view
   virtual EcU32 simulationType
      (
      ) const;

   /// sets the field of view
   virtual void setSimulationType
      (
      EcU32 simulationType
      );

   /// gets the time step
   virtual EcReal timeStep
      (
      ) const;

   /// sets the time step
   virtual void setTimeStep
      (
      EcReal timeStep
      );

    /// gets the limiting growth factor for numerical stability management
   virtual EcReal limitingGrowthFactor
      (
      ) const;

   /// sets the limiting growth factor for numerical stability management
   virtual void setLimitingGrowthFactor
      (
      EcReal limitingGrowthFactor
      );

   /// gets the time between evaluation
   virtual EcReal timeBetweenMassMatrixEvaluations
      (
      ) const;

   /// sets the time between evaluation
   virtual void setTimeBetweenMassMatrixEvaluations
      (
      EcReal timeBetweenMassMatrixEvaluations
      );

   /// gets the on/off flag
   virtual EcBoolean isOn
      (
      ) const;

   /// sets the on/off flag
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets the integration order
   virtual EcU32 integrationOrder
      (
      ) const;

   /// sets the integration order
   virtual void setIntegrationOrder
      (
      EcU32 integrationOrder
      );

   /// gets the bound
   virtual EcReal stateVariableBound
      (
      ) const;

   /// sets the bound
   virtual void setStateVariableBound
      (
      EcReal stateVariableBound
      );

   /// gets the time
   virtual EcReal time
      (
      ) const;

   /// sets the time
   virtual void setTime
      (
      EcReal time
      );

   /// gets the active state for this manipulator
   virtual const EcManipulatorActiveState& manipulatorActiveState
      (
      ) const;

   /// gets the last acceleration state
   virtual const EcAccelerationState& lastAccelerationState
      (
      ) const;

   /// simulate through newTime
   virtual EcBoolean simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState,
      EcVelocityState& velocityState,
      EcReal currentTime,
      const EcManipulatorTorque& torque,
      const EcManipulatorExternalForce& manipExtForce,
      EcReal newTime
      );

   /// simulate through newTime
   virtual EcBoolean simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState,
      EcVelocityState& velocityState,
      EcReal currentTime,
      const EcManipulatorControlInput& controlInput,
      const EcManipulatorExternalForce& manipExtForce,
      EcReal newTime
      );

   /// initialize the rotating buffer
   virtual EcBoolean initialize
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState
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
   static EcIndividualDynamicSimulator nullObject
      (
      );

   /// create an object with default values
   static EcIndividualDynamicSimulator defaultObject
      (
      );

   /// properly size the integration states
   virtual void configureIntegrationStates
      (
      );

   /// set the integrator to all internal integrators. This can be call instead of many call to set individual integrators.
   /// Note that the integration order and time step of the integrators will be set to those specified in this class.
   virtual void setIntegrators
      (
       const EcBaseIntegrator& integrator
      );

   /// get the integrator container for manipulator joints
   virtual const EcIntegratorContainer& manipulatorJointIntegratorContainer
      (
      ) const;

   /// set the integrator container for manipulator joints.
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setManipulatorJointIntegratorContainer
      (
      const EcIntegratorContainer& integrator
      );

   /// set the integrator for manipulator joints
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setManipulatorJointIntegrator
      (
      const EcBaseIntegrator& integrator
      );

   /// get the integrator container for manipulator base
   virtual const EcIntegratorContainer& manipulatorBaseIntegratorContainer
      (
      ) const;

   /// set the integrator container for manipulator base
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setManipulatorBaseIntegratorContainer
      (
      const EcIntegratorContainer& integrator
      );

   /// set the integrator for manipulator base
   /// Note that the integration order and time step of the integrator will be set to those specified in this class.
   virtual void setManipulatorBaseIntegrator
      (
      const EcBaseIntegrator& integrator
      );

   /// gets the actuator dynamic simulator
   virtual const EcActuatorDynamicSimulator& actuatorDynamicSimulator
      (
      ) const;

   /// sets the actuator dynamic simulator
   virtual void setActuatorDynamicSimulator
      (
      const EcActuatorDynamicSimulator& value
      );

   ///  gets the default time step
   static const EcReal defaultTimeStep
      (
      );

protected:

   /// registers enumeration strings for the simulation type
   virtual void   registerEnumerations( void );

   /// simulate one step using the integrator
   virtual EcBoolean simulateOneStep
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState,
      EcVelocityState& velocityState,
      EcReal currentTime,
      const EcManipulatorTorque& torque,
      const EcManipulatorExternalForce& manipExtForce
      );

   /// simulate one step using the integrator
   virtual EcBoolean simulateOneStep
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState,
      EcVelocityState& velocityState,
      EcReal currentTime,
      const EcManipulatorControlInput& controlInput,
      const EcManipulatorExternalForce& manipExtForce
      );

   /// calculate the torque from the control input
   virtual EcBoolean calculateTorque
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorControlInput& controlInput,
      EcManipulatorActiveState& activeState,
      EcManipulatorTorque& torque
      );

   /// get the current acceleration
   virtual EcBoolean calculateAcceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      const EcManipulatorTorque& torque,
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState& activeState,
      EcAccelerationState& accelerationState
      );

   /// check the stability of the numerical integration
   /// returns true if stable and false if not
   virtual EcBoolean checkStability
      (
      );

   /// bound the position and velocity states
   virtual void boundPositionAndVelocityStates
      (
      EcPositionState& positionState,
      EcVelocityState& velocityState
      );

protected:
   /// the simulation type
   EcXmlEnumU32               m_SimulationType;

   /// the time step particular to this manipulator
   EcXmlReal                  m_TimeStep;

   /// the limiting growth factor for stability
   EcXmlReal                  m_LimitingGrowthFactor;

   /// the integration order
   EcXmlU32                   m_IntegrationOrder;

   /// a magnitude bound on all variables to prevent overflow
   EcXmlReal                  m_StateVariableBound;

   /// the minimum time between evaluation for speedup
   EcXmlReal                  m_TimeBetweenMassMatrixEvaluations;

   /// whether or not this dynamic simulator is executed
   EcXmlBoolean               m_IsOn;

   /// integrator used for integrating accelerations of manipulator joints
   EcIntegratorContainer      m_ManipulatorJointIntegrator;

   /// integrator used for integrating accelerations of manipulator base
   EcIntegratorContainer      m_ManipulatorBaseIntegrator;

   /// dynamic simulator for actuators
   EcActuatorDynamicSimulator m_ActuatorSimulator;

   /// integrator used for integrating accelerations of joint actuators
   /// deprecated. Only here for backward compatibility.
   /// TODO: Removed in version 3.0
   EcIntegratorContainer      m_ActuatorIntegrator;

   // non-XML data below

   /// the time of the last stored state
   EcReal                     m_Time;

   /// the last time the mass matrix was evaluated for CRBI.
   EcReal                     m_LastMassMatrixEvaluationTime;

   /// indicates that integration state has just been initialized
   EcBoolean                  m_IntegrationInitialized;

   /// a tool for calculating acceleration using the composite-rigid-body
   /// algorithm.
   EcCrbiAccelerationTool     m_CrbiAccelerationTool;

   /// a tool for calculating acceleration using the articulated-rigid-body
   /// algorithm.
   EcArbiAccelerationTool     m_ArbiAccelerationTool;

   /// an active state for this manipulator
   EcManipulatorActiveState   m_ActiveState;

   /// the previously active state for the this manipulator
   EcManipulatorActiveState   m_PreviousActiveState;

   /// a utility position state
   EcPositionState            m_UtilityPositionState;

   /// a utility velocity state
   EcVelocityState            m_UtilityVelocityState;

   /// a utility acceleration state for manipulator acceleration calculation
   EcAccelerationState        m_UtilityAccelerationState;

   /// a utility acceleration state to hold zero joint acceleratios
   EcAccelerationState        m_UtilityZeroAccelerationState;

   /// the threshold for automatic switching to the articulated-rigid-body
   /// algorithm
   static const EcU32         m_theArbiThreshold;

   /// the default times step for dynamic simulation
   static const EcReal        m_theDefaultTimeStep;

private:
   // template utility class for simulateThrough method
   template<class InputType>
   EcBoolean simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState,
      EcVelocityState& velocityState,
      EcReal currentTime,
      const InputType& input,
      const EcManipulatorExternalForce& manipExtForce,
      EcReal newTime
      );

};

/// an XML vector of links
typedef EcXmlVectorType<EcIndividualDynamicSimulator> EcIndividualDynamicSimulatorVector;

#endif // ecIndDynSimulator_H_
