#ifndef ecDynSimulatorSystem_H_
#define ecDynSimulatorSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecDynSimulatorSystem.h
/// @class EcDynamicSimulatorSystem
/// @brief Holds a dynamic simulator for a manipulator system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecIndDynSimulator.h"
#include "ecManipControlInput.h"

#include <foundCore/ecTypes.h>
#include <foundCommon/ecGeneralForce.h>
#include <manipulator/ecManipTorque.h>
#include <manipulator/ecManipSysState.h>
#include <manipulator/ecStatedSystem.h>
#include <manipulator/ecSystemActiveState.h>

// forward declarations
class EcStatedSystem;

/** Holds a dynamic simulator for a manipulator system.
*/
class EC_ACTIN_SIMULATION_DECL EcDynamicSimulatorSystem : public EcXmlCompoundType
{
public:
   /// default constructor
   EcDynamicSimulatorSystem
      (
      );

   /// destructor
   virtual ~EcDynamicSimulatorSystem
      (
      );

   /// copy constructor
   EcDynamicSimulatorSystem
      (
      const EcDynamicSimulatorSystem& orig
      );

   /// assignment operator
   EcDynamicSimulatorSystem& operator=
      (
      const EcDynamicSimulatorSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDynamicSimulatorSystem& orig
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcDynamicSimulatorSystem& orig
      );

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

   /// gets the individual dynamic simulators
   virtual const EcIndividualDynamicSimulatorVector& dynamicSimulators
      (
      ) const;

   /// sets the individual dynamic simulators
   virtual void setDynamicSimulators
      (
      const EcIndividualDynamicSimulatorVector& dynamicSimulators
      );

   /// set the dynamic simulator flag on the manipulator level
   virtual void setManipulatorDynamicallySimulate
      (
           const EcU32& manipIndex,
           const EcBoolean& value = EcTrue
      );

   /// set the dynamic simulator flag on the manipulator level
   virtual EcBoolean manipulatorDynamicallySimulate
      (
           const EcU32& manipIndex
      );

   /// gets dynamic simulator time step
   virtual const EcXmlReal& dynamicSystemTimeStep
      (
      ) const;

   /// sets dynamic simulator time step
   virtual void setDynamicSystemTimeStep
      (
      const EcXmlReal& dynamicSystemTimestep
      );

   /// pushes an individual dynamic simulator onto the vector
   virtual void pushIndividualSimulator
      (
      const EcIndividualDynamicSimulator& individual
      );

   /// dynamically simulates up to newTime with the given control torques. set the state in the stated system to the new state.
   /**
   \param[in, out] statedSystem The stated system to be simulated. The new state at the new time will be set in statedSystem upon return.
   \param[in] manipTorqueVector The control torques applied to the manipulators in the system.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \return True if successful or false otherwise.
   */
   virtual EcBoolean simulateThrough
      (
      EcStatedSystem& statedSystem,
      const EcManipulatorTorqueVector& manipTorqueVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime
      );

   /// dynamically simulates up to newTime with the given control torques.
   /**
   \param[in] statedSystem The stated system to be simulated.
   \param[in] manipTorqueVector The control torques applied to the manipulators in the system.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \param[out] status True if successful or false otherwise.
   \return The new state at newTime.
   */
   virtual const EcManipulatorSystemState&  simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorTorqueVector& manipTorqueVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime,
      EcBoolean& status
      );

   /// dynamically simulates up to newTime with the given control inputs. set the state in the stated system to the new state.
   /**
   \param[in, out] statedSystem The stated system to be simulated. The new state at the new time will be set in statedSystem upon return.
   \param[in] manipControlInputVector The control inputs applied to the manipulators in the system.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \return True if successful or false otherwise.
   */
   virtual EcBoolean simulateThrough
      (
      EcStatedSystem& statedSystem,
      const EcManipulatorControlInputVector& manipControlInputVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime
      );

   /// dynamically simulates up to newTime with the given control inputs.
   /**
   \param[in] statedSystem The stated system to be simulated.
   \param[in] manipControlInputVector The control inputs applied to the manipulators in the system.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \param[out] status True if successful or false otherwise.
   \return The new state at newTime.
   */
   virtual const EcManipulatorSystemState&  simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorControlInputVector& manipControlInputVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime,
      EcBoolean& status
      );

   /// dynamically simulates up to newTime with the given control torques and external forces. set the state in the stated system to the new state.
   /**
   \param[in, out] statedSystem The stated system to be simulated. The new state at the new time will be set in statedSystem upon return.
   \param[in] manipTorqueVector The control torques applied to the manipulators in the system.
   \param[in] manipForceVector The external forces applied to the manipulators. These forces will be added to the link interaction forces. These external forces could be artificial.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \return True if successful or false otherwise.
   */
   virtual EcBoolean simulateThrough
      (
      EcStatedSystem& statedSystem,
      const EcManipulatorTorqueVector& manipTorqueVector,
      const EcManipulatorExternalForceVector& manipForceVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime
      );

   /// dynamically simulates up to newTime with the given control torques and external forces.
   /**
   \param[in] statedSystem The stated system to be simulated.
   \param[in] manipTorqueVector The control torques applied to the manipulators in the system.
   \param[in] manipForceVector The external forces applied to the manipulators. These forces will be added to the link interaction forces. These external forces could be artificial.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \param[out] status True if successful or false otherwise.
   \return The new state at newTime.
   */
   virtual const EcManipulatorSystemState&  simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorTorqueVector& manipTorqueVector,
      const EcManipulatorExternalForceVector& manipForceVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime,
      EcBoolean& status
      );

   /// dynamically simulates up to newTime with the given control inputs and external forces. set the state in the stated system to the new state.
   /**
   \param[in, out] statedSystem The stated system to be simulated. The new state at the new time will be set in statedSystem upon return.
   \param[in] manipControlInputVector The control inputs applied to the manipulators in the system.
   \param[in] manipForceVector The external forces applied to the manipulators. These forces will be added to the link interaction forces. These external forces could be artificial.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \return True if successful or false otherwise.
   */
   virtual EcBoolean simulateThrough
      (
      EcStatedSystem& statedSystem,
      const EcManipulatorControlInputVector& manipControlInputVector,
      const EcManipulatorExternalForceVector& manipForceVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime
      );

   /// dynamically simulates up to newTime with the given control inputs and external forces.
   /**
   \param[in] statedSystem The stated system to be simulated.
   \param[in] manipControlInputVector The control inputs applied to the manipulators in the system.
   \param[in] manipForceVector The external forces applied to the manipulators. These forces will be added to the link interaction forces. These external forces could be artificial.
   \param[in] defaultState If the dynamic simulator is off, the default state will be used.
   \param[in] newTime The new time.
   \param[out] status True if successful or false otherwise.
   \return The new state at newTime.
   */
   virtual const EcManipulatorSystemState&  simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorControlInputVector& manipControlInputVector,
      const EcManipulatorExternalForceVector& manipForceVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime,
      EcBoolean& status
      );

   /// initialize the simulator with a stated system
   virtual void initialize
      (
      const EcStatedSystem& statedSystem
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
   static EcDynamicSimulatorSystem nullObject
      (
      );

   /// create an object with default values
   static EcDynamicSimulatorSystem defaultObject
      (
      );

   /// properly size the integration states
   virtual void configureIntegrationStates
      (
      );

   /// gets the system active state
   virtual const EcSystemActiveState& systemActiveState
      (
      ) const;


   /// gets the system active state (non-const)
   virtual EcSystemActiveState& systemActiveState
      (
      );

   /// sets the system active state
   virtual void setSystemActiveState
      (
      const EcSystemActiveState& systemActiveState
      );


protected:
   /// initiate simulating forward through newTime
   virtual EcU32 initSimulateThrough
      (
      const EcStatedSystem& statedSystem,
      EcU32 vectorSize
      );

   /// add the given external force vector to the general force vector of the provided system active state.
   virtual void addExternalForceVector
      (
      const EcManipulatorExternalForceVector& manipForceVector,
      EcSystemActiveState& activeState
      ) const;

protected:
   /// the dynamic simulators for the individual manipulators
   EcIndividualDynamicSimulatorVector       m_DynamicSimulators;

   /// the timestep for the dynamic simulator system
   EcXmlReal                                m_DynamicSystemTimestep;

   /// a utility state
   mutable EcManipulatorSystemState         m_UtilityState;

   /// a second utility state
   mutable EcManipulatorSystemState         m_UtilityState2;

   /// a utility stated system
   mutable EcStatedSystem                   m_UtilityStatedSystem;

   /// active state vector
   EcSystemActiveState                      m_SystemActiveState;

   /// general force vector vector
   mutable EcManipulatorExternalForceVector m_ManipExtForceVec;

   /// empty general force vector vector
   mutable EcManipulatorExternalForceVector m_EmptyManipExtForceVec;

private:
   // template utility class for simulateThrough method
   template<class InputType>
   const EcManipulatorSystemState&  simulateThrough
      (
      const EcStatedSystem& statedSystem,
      const InputType& inputVector,
      const EcManipulatorTorqueVector& manipTorqueVector,
      const EcManipulatorExternalForceVector& manipForceVector,
      const EcManipulatorSystemState& defaultState,
      EcReal newTime,
      EcBoolean& status
      );
};

#endif // ecDynSimulatorSystem_H_
