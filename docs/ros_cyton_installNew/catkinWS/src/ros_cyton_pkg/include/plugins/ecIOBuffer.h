#ifndef ec_IOBuffer_H_
#define ec_IOBuffer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecIOBuffer.h
/// @class Ec::IOBuffer
/// @brief Buffers data between plugins and simulation.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecIOParams.h"
#include "ecPluginSignals.h"
#include <control/ecEndEffectorSet.h>
#include <control/ecManipEndEffectorPlace.h>
#include <control/ecManipEndEffectorVel.h>
#include <forceControl/ecManipSensorForce.h>
#include <foundCore/ecConnectionManagerTypes.h>
#include <simulation/ecSysSimulation.h>

namespace Ec
{

/// The purpose of ScopedSim is to provide a safe mechanism to access the
/// simulation.  It provides automatic release of the mutex when it goes out
/// of scope.  Users should enclose this variable to limit the amount of time
/// holding the lock so that other thread operations don't get stalled.
typedef boost::shared_ptr<EcSystemSimulation>       ScopedSysSim;
/// Const version of scoped handle.  These are currently setup to not lock.
typedef boost::shared_ptr<const EcSystemSimulation> CScopedSysSim;

struct EC_ACTIN_PLUGINS_DECL IOBuffer
{
   /// Provide a convenient way for plugins to get a copy of the stated system
   typedef boost::shared_ptr<EcStatedSystem> StatedSystemPtr;

   /// Default constructor
   IOBuffer
      (
      );

   /// Set global simulation variable.
   void setSystemSimulation
      (
      const EcSystemSimulation& sysSim ///< [in] Simulation to set
      );

   /// Safe access to EcSystemSimulation.
   /// @return ScopedSysSim Auto-release of handle when out of scope
   ScopedSysSim systemSimulation
      (
      );

   /// Safe access to read-only EcSystemSimulation.
   /// @return CScopedSysSim Auto-release of handle when out of scope
   CScopedSysSim& constSystemSimulation
      (
      ) const;

   /// Set the simulation timestep in seconds.
   void setSimulationTimeStep
      (
      const EcReal timeStep ///< [in] Timestep for simulation in seconds
      );

   /// Set active states for each manipulator.
   /// @return EcBoolean Success or failure of command
   EcBoolean setActiveStateVector
      (
      const EcManipulatorActiveStateVector& activeVector ///< [in] States to set
      );

   /// Retrieve vector of active states, one for each manipulator.
   /// @return EcManipulatorActiveStateVector Vector of active states
   EcManipulatorActiveStateVector activeStateVector
      (
      ) const;

   /// Set an individual active state for a single manipulator.
   /// @return EcBoolean Success or failure of command.
   EcBoolean setActiveState
      (
      const EcU32 manipulatorIndex, ///< [in] Index into manipulator list
      const EcManipulatorActiveState& actState ///< [in] State to set
      );

   /// Retrieve the active state for a single manipulator.
   EcManipulatorActiveState activeState
      (
      const EcU32 manipulatorIndex ///< [in] Index into manipulator list
      ) const;

   /// Set the vector of desired end-effector placements, per manipulator.
   void setDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& placementVector ///< [in]
      );

   /// Set the desired end-effector placements for a single manipulator.
   EcBoolean setDesiredPlacement
      (
      const EcU32 manipulatorIndex, ///< [in] Index into manipulator list
      const EcManipulatorEndEffectorPlacement& placement ///< [in] Placement to set
      );

   /// Retrieve the vector of desired end-effector placements.
   /// @return EcManipulatorEndEffectorPlacementVector Placement vector
   EcManipulatorEndEffectorPlacementVector desiredPlacementVector
      (
      ) const;

   /// Retrieve the vector of actual end-effector placements.
   /// @return EcManipulatorEndEffectorPlacementVector Placement vector
   EcManipulatorEndEffectorPlacementVector actualEndEffectorVector
      (
      ) const;

   /// Set all desired placements to their actual positions and set desired
   /// velocities to zero.
   void resetPlacementVector
      (
      );

   /// set desired placement size
   EcBoolean setDesiredPlacementSize
      (
      const EcU32 manipulatorIndex,
      const EcU32 numEndEffector
      );

   /// set desired end effector pose
   EcBoolean setDesiredEndEffectorPose
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex,
      const EcEndEffectorPlacement& pose
      );

   /// get desired end effector pose
   EcBoolean getDesiredEndEffectorPose
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex,
      EcEndEffectorPlacement& pose
      ) const;

   /// get current end effector pose
   EcBoolean getCurrentEndEffectorPose
      (
      const EcU32 manipIndex,
      const EcU32 endEffectorIndex,
      EcEndEffectorPlacement& pose
      ) const;

   /// get current end effector velocity
   EcBoolean getCurrentEndEffectorVelocity
      (
      const EcU32 manipIndex,
      const EcU32 endEffectorIndex,
      EcXmlRealVector& velocity
      ) const;

   /// set desired force vector
   void setDesiredForceVector
      (
      const EcManipulatorSensorForceVector& forceVector
      );

   /// return desired force vector
   EcManipulatorSensorForceVector desiredForceVector
      (
      ) const;

   /// set desired force for a manipulator
   EcBoolean setDesiredForce
      (
      const EcU32 manipulatorIndex,
      const EcManipulatorSensorForce& force
      );

   /// return desired velocity vector
   const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      (
      ) const;

   /// set desired velocity vector
   void setDesiredVelocityVector
      (
      const EcManipulatorEndEffectorVelocityVector& velocityVector
      );

   /// set desired velocity for one manipulator
   EcBoolean setDesiredVelocity
      (
      const EcU32 manipulatorIndex,
      const EcManipulatorEndEffectorVelocity& velocity
      );

   /// set desired velocity for one end effector
   EcBoolean setDesiredVelocity
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex,
      const EcXmlRealVector& velocity
      );

   /// return end effector set vector
   EcEndEffectorSetVector endEffectorSetVector
      (
      ) const;

   /// set end effector set vector
   void setEndEffectorSetVector
      (
      const EcEndEffectorSetVector& eeSetVec
      );

   /// set end effector set
   EcBoolean setEndEffectorSet
      (
      const EcEndEffectorSet& eeSet,
      const EcU32 manIndex
      );

   /// set active position control method
   EcBoolean setActivePositionControlMethod
      (
      const EcU32 manIndex,
      const EcU32 value
      );

   /// add manipulator
   EcU32 addManipulator
      (
      const EcIndividualManipulator& manip,
      const EcPositionState& posState = EcPositionState()
      );

   /// delete manipulator
   EcBoolean deleteManipulator
      (
      const EcU32 manIndex
      );

   /// set state
   EcBoolean setState
      (
      const EcManipulatorSystemState& state
      );

   /// return state
   EcManipulatorSystemState state
      (
      ) const;

   /// set position state for on manipulator
   EcBoolean setState
      (
      const EcU32 manIndex,
      const EcPositionState& posState,
      const EcBoolean baseOnly = EcFalse
      );

   /// set joint positions
   EcBoolean setJointPositions
      (
      const EcU32 manIndex,
      const EcRealVector& jointPos
      );

   /// set velocity state for one manipulator
   EcBoolean setState
      (
      const EcU32 manIndex,
      const EcVelocityState& velState,
      const EcBoolean baseOnly = EcFalse
      );

   /// set initial state
   EcBoolean setInitialState
      (
      const EcU32 manIndex,
      const EcPositionState& velState
      );

   /// set position control container
   EcBoolean setPositionControlContainer
      (
      const EcSimulationPositionControlContainer& posCont
      );

   /// get position control container
   EcBoolean getPositionControlContainer
      (
      EcSimulationPositionControlContainer& value
      ) const;

   /// set position control system
   EcBoolean setPositionControlSystem
      (
      const EcPositionControlSystem& posSys
      );

   /// get position control system
   EcBoolean getPositionControlSystem
      (
      EcPositionControlSystem& value
      ) const;

   /// set force control system
   EcBoolean setForceControlSystem
      (
      const EcForceControlSystem& forceSys
      );

   /// get forced control system
   EcBoolean getForceControlSystem
      (
      EcForceControlSystem& value
      ) const;

   /// return active end effector sets
   const EcU32Vector& activeEndEffectorSets
      (
      ) const;

   /// set active end effector set
   EcBoolean setActiveEndEffectorSet
      (
      const EcU32 manIndex,
      const EcU32 eeSetIndex
      );

   /// set active control descriptor
   EcBoolean setActiveControlDescriptor
      (
      const EcU32 manIndex,
      const EcU32 descriptorIndex
      );

   /// return active force control descriptors
   const EcU32Vector activeForceControlDescriptors
      (
      ) const;

   /// set active force control descriptor
   EcBoolean setActiveForceControlDescriptor
      (
      const EcU32 manIndex,
      const EcU32 descriptorIndex
      );

   /// set measured force (sensor reading) for a particular sensor
   EcBoolean setMeasuredForce
      (
      const EcU32 manIndex,
      const EcU32 subIndex,
      const EcRealVector& sensorReadings
      );

   /// set measured force (sensor readings) for all the sensors in the manipulator
   EcBoolean setMeasuredForce
      (
      const EcU32 manIndex,
      const EcManipulatorSensorForce& sensorReadings
      );

   /// get measured force vector
   EcManipulatorSensorForceVector measuredForceVector
      (
      ) const;

   /// set flag for is force control on
   void setIsForceControlOn
      (
      const EcBoolean value
      );

   /// return flag for is force control on
   EcBoolean isForceControlOn
      (
      ) const;

   /// get update
   void updateFromInput
      (
      );

   /// set output data
   void setOutputData
      (
      const EcReal time
      );

   /// set external control
   void setExternalControl
      (
      const EcBoolean isOn
      );

   /// get external control
   EcBoolean externalControl
      (
      ) const;

   /// Set simulation run state (start, stop, pause).
   void setSimulationState
      (
      const SimulationRunState state,     ///< [in] State to change to
      const EcBoolean emitSignal = EcTrue ///< [in] Whether to emit signal to listeners
      );

   /// Retrieve simulation run state (start, stop, pause).
   /// @return SimulationRunState Current run state
   SimulationRunState simulationState
      (
      ) const;

   /// create a copy of stated system.
   /// @return The index of the created copy
   EcU32 createStatedSystemCopy
      (
      );

   /// return the shared pointer to a copy of the stated system specified by
   /// index. If index is invalid, the returned pointer is null.
   StatedSystemPtr statedSystemPtr
      (
      EcU32 index
      );

   /// Returns the state bits that have changed in the last timestep.
   const EcU32 changedFlags
      (
      ) const;

   /// set the custom data in form of data map
   void setDataMap
      (
      const EcDataMap& dataMap
      );

   /// Get the custom data in form of data map
   EcDataMap dataMap
      (
      ) const;

   /// get the attachment map
   EcBoolean getAttachmentMap
      (
      EcManipulatorAttachmentMap&  value
      ) const;

   /// set the attachment map
   EcBoolean setAttachmentMap
      (
      const EcManipulatorAttachmentMap& attachmentMap
      );

   /// set an attachment change which is used to attach/detach manipulator onto/from another
   EcBoolean setAttachmentChange
      (
      const EcManipulatorAttachmentChange& attachmentChange
      );

   /// get the dynamic collision exclusion map
   EcBoolean setCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// get the dynamic collision exclusion map
   EcBoolean getCollisionExclusionMap
      (
      EcSystemCollisionExclusionMap&  value
      ) const;

   /// set the static collision exclusion map
   EcBoolean setStaticCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// get the static collision exclusion map
   EcBoolean getStaticCollisionExclusionMap
      (
      EcSystemCollisionExclusionMap&  value
      ) const;

   /// return simulation mutex
   inline EcSharedMutex& simulationMutex
      (
      ) const { return m_SimMutex; }

   /// set calculation time
   void setCalculationTime
      (
      const EcReal time
      );

   /// return calculation time
   EcReal calculationTime
      (
      ) const;

   /// disconnect signals
   void disconnectSignals
      (
      );

   /// set max speed factor
   EcBoolean setBaseSpeedFactor
      (
      const EcU32 manIndex,
      const EcReal value
      );

   /// set speed factor
   EcBoolean setSpeedFactor
      (
      const EcU32 manIndex,
      const EcReal value
      );

   /// set profiled end effectors
   EcBoolean setProfiledEndEffectors
      (
      const EcU32 manIndex,
      const EcU32Vector& indices
      );

   /// set tool offset
   EcBoolean setToolOffset
      (
      const EcU32 manIndex,
      const EcU32 offsetIndex,
      const EcCoordinateSystemTransformation& value
      );

   /// reset the simulation to initial state and configuration
   /// \param resetDesiredPlacement True if you want to reset desired EE placement as well.
   void resetSimulation
      (
      EcBoolean resetDesiredPlacement = EcTrue
      );

   /// stop the motion of a manipulator
   EcBoolean stopMotion
      (
      const EcU32 manIndex
      );

   /// return the control modes for all manipulators
   const EcU32Vector& controlModes
      (
      ) const;

   /// set the control mode of a given manipulator
   EcBoolean setControlMode
      (
      const EcU32 manIndex,
      const EcU32 value
      );
private:

   /// update from input
   void updateFromInputNoLock
      (
      );

   /// update all the data from the system simulation
   void updateFromSystemSimulation
      (
      );

   /// update the state from change in attachment map if simulation is not running
   void updateStateFromAttachment
      (
      const EcManipulatorAttachmentMap& attachmentMap
      );

   // NOTE: If multiple locks are required, they should always be acquired in the same order
   //       i.e. Acquire locks in the order presented here: inputLock, simLock, outputLock, slaveLock

   // Input variables protected by the input data mutex
   mutable EcMutex                          m_InputDataMutex;           ///< input data mutex
   EcU32                                    m_StateBits;                ///< State change that hasn't been processed yet
   EcU32Vector                              m_EndEffectorSets;          ///< end effector sets
   EcU32Vector                              m_ForceControlDescriptor;   ///< force control descriptor
   EcManipulatorEndEffectorPlacementVector  m_DesiredPlacementVector;   ///< desired placement vector
   EcManipulatorEndEffectorVelocityVector   m_DesiredVelocityVector;    ///< desired velocity vector
   EcManipulatorSensorForceVector           m_DesiredForceVector;       ///< desired force vector
   EcManipulatorSensorForceVector           m_MeasuredForceVector;      ///< measured force vector
   EcEndEffectorSetVector                   m_EndEffectorSetVector;     ///< end effector set vector
   EcBoolean                                m_IsForceControlOn;         ///< flag for force control
   EcBoolean                                m_IsExternalControl;        ///< flag for external control
   SimulationRunState                       m_SimulationState;          ///< simulation state
   EcReal                                   m_SimulationTimeStep;       ///< simulation time step
   EcBooleanVector                          m_NotSetStateFlags;         ///< boolean vector for not set states
   std::set<EcInt32>                        m_BaseOnlyStateFlags;       ///< Manip indices that only want base
   EcDataMap                                m_DataMap;                  ///< for customer data exchange among plugins
   EcU32Vector                              m_ControlModes;             ///< Control modes (position or velocity)

   // Simulation variables protected by the simulation mutex
   mutable EcSharedMutex                    m_SimMutex;                 ///< Protects changes during simulation updates.
   EcSystemSimulation                       m_SystemSimulation;         ///< system simulation

   // Output variables protected by the output data mutex
   mutable EcSharedMutex                    m_OutputDataMutex;          ///< output data mutex
   BitFlags                                 m_ChangedBits;              ///< Holds cumulative state changes
   BitFlags                                 m_PreviousStateBits;        ///< Stored so plugins can access during update
   EcManipulatorEndEffectorPlacementVector  m_ActualEndEffector;        ///< actual end effectors
   mutable EcSystemActiveState              m_ActiveState;              ///< Utility active state to perform needed operations
   EcReal                                   m_CalculationTime;          ///< calculation time

   // Input and output variables protected by the input and output data mutex
   EcManipulatorSystemState                 m_State;                    ///< input state

   // the state used in double buffer to prevent locking
   EcManipulatorSystemState                 m_OutputState;              ///< output state

   // Slave stated system variables protected by the slave system mutex
   mutable EcMutex                          m_SlaveStatedSystemMutex;   ///< slave stated system mutex
   std::vector< StatedSystemPtr >           m_SlaveStatedSystemPtrs;    ///< slave stated system pointers
   static CScopedSysSim                     s_CScopedSysSim;            ///< static system simulation

   EcBooleanVector                          m_vControlStopStates;       ///< vector of control stop states

   EcManipulatorSystemConfiguration         m_InitConfiguration;        ///< cache of initial configuration, used in resetSimulation

   EcManipulatorAttachmentMap               m_AttachmentMap;            ///< manipulator attachment map

   EcU32Vector                              m_DepManipIndices;          ///< dependent manipulator indices
   EcCoordinateSystemTransformationVector   m_DepManipLocations;        ///< dependent manipulator location

/// connection manager signal pointer
#define SIG_PTR(x) ConnectionManagerTypes::Signal<x::Type>::PtrType
   // List of signals that this class currently emits
   SIG_PTR(SignalAttachmentChangeTraits) m_AttachmentChangeSignalPtr;
   SIG_PTR(SignalAttachmentMapChangeTraits) m_AttachmentMapChangeSignalPtr;
   SIG_PTR(SignalCollisionMapChangeTraits) m_CollisionMapChangeSignalPtr;
   SIG_PTR(SignalControlDescriptionChangeTraits) m_ControlDescriptionChangeSignalPtr;
   SIG_PTR(SignalControlMethodChangeTraits) m_ControlMethodChangeSignalPtr;
   SIG_PTR(SignalControlStopStateChangeTraits) m_ControlStopStateChangeSignalPtr;
   SIG_PTR(SignalControlSystemChangeTraits) m_ControlSystemChangeSignalPtr;
   SIG_PTR(SignalCoordinatedMoveTraits) m_CoordinatedMoveSignalPtr;
   SIG_PTR(SignalEndEffectorSetTraits) m_EndEffectorSetSignalPtr;
   SIG_PTR(SignalManipulatorAddTraits) m_ManipulatorAddSignalPtr;
   SIG_PTR(SignalManipulatorDeleteTraits) m_ManipulatorDeleteSignalPtr;
   SIG_PTR(SignalSimulationChangeTraits) m_SimulationChangeSignalPtr;
   SIG_PTR(SignalSimulationEnableTraits) m_SimulationEnableSignalPtr;
   SIG_PTR(SignalSimulationPauseTraits) m_SimulationPauseSignalPtr;
   SIG_PTR(SignalSimulationStartTraits) m_SimulationStartSignalPtr;
   SIG_PTR(SignalSimulationStateTraits) m_SimulationStateSignalPtr;
   SIG_PTR(SignalSimulationStopTraits) m_SimulationStopSignalPtr;
   SIG_PTR(SignalSimulationTimeStepTraits) m_SimulationTimeStepSignalPtr;
#undef SIG_PTR
};

} // namespace Ec

#endif // ec_IOBuffer_H_
