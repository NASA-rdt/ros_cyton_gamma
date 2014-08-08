#ifndef ec_IOParams_H_
#define ec_IOParams_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecIOParams.h
/// @brief Enumeration of types available via plugin API.
//
//------------------------------------------------------------------------------
#include <foundCore/ecTypes.h>
#include <foundCore/ecPluginParams.h>

namespace Ec
{

/// Parameters to describe the I/O commands.  They can be either a
/// Get(G), Set(S) or Set and Get(SG). The second argument corresponds
/// to the parameter type that it expects.  A subset can also be
/// specified.  For example an EcOrientation can be retrieved from
/// the ActualEndEffector instead of the entire
/// EcCoordinateSystemTransformation.
enum ParamTypeEnum
{
   ActiveState=EndOfBaseEnums,///< ( G,EcManipulatorActiveState) Utility state for computations
   ActualEndEffector,         ///< ( G,EcCoordinateSystemTransformation) true location of EE
   AntiCollision,             ///< (SG,EcBoolean) Turn on/off anti-collision in control
   AttachmentMap,             ///< (SG,EcManipulatorAttachmentMap) Set/get the attachment map
                              ///< (S ,EcManipulatorAttachmentChange) Set an attachment change
   Base,                      ///< (SG,EcCoordinateSystemTransformation) location of base
   BaseSpeedFactor,           ///< (SG,EcReal) Base speed factor
   BaseVelocity,              ///< (SG,EcGeneralVelocity) velocity of base
   CollisionExclusionMap,     ///< (SG,EcSystemCollisionExclusionMap) Dynamic or runtime collision exclusion map
   CollisionPriority,         ///< (SG,EcAntiCollisionPriorityList)
   CollisionResults,          ///< ( G,EcPropagationResultDataVector)
   CalculationTime,           ///< ( G,EcReal) Time taken to compute a timestep
   ControlDescriptor,         ///< (SG,EcU32) Control descriptor capability
   ControlMethod,             ///< (SG,EcU32) Position control method
   ControlMode,               ///< (SG,EcU32) Control mode
   ControlSystem,             ///< (SG,Ec{Position,Velocity}ControlSystem)
   CoordinatedJointAngle,     ///< (SG,EcRealVector) Coordinated joint state
   DataMap,                   ///< (SG,EcDataMap) Custom data to exchange among plugins
   DesiredEndEffector,        ///< (SG,EcManipulatorEndEffectorPlacement) desired loc of EE
   DesiredForce,              ///< (SG,EcManipulatorSensorForce)
   DesiredVelocity,           ///< (SG,EcManipulatorEndEffectorVelocity) desired EE velocity
   DhFrame,                   ///< ( G,EcCoordinateSystemTransformation) location of DH frame
   DisplaySystemDataCapture,  ///< (SG,EcDisplaySystemDataCaptureVector)
   DynamicSimulation,         ///< (SG,EcDynamicSimulatorSystem)
   EndEffectorSet,            ///< (SG,EcEndEffectorSetVector) End-effector sets for the system
                              ///< (SG,EcEndEffectorSet) End-effector set of a manipulator
                              ///< (SG,EcU32) Active end-effector set of a manipulator
   ExternalControl,           ///< (SG,EcBoolean) Externally control simulation components
   ForceControlDescriptor,    ///< (SG,EcU32) Force control descriptor capability
   ForceControlOn,            ///< (SG,EcBoolean) Turn on/off force control
   ForceControlSystem,        ///< (SG,EcForceControlSystem)
   ImageSensor,               ///< (SG,EcImageSensor)
   InitJointAngle,            ///< (SG,EcRealVector) Initial joint state
   JointAngle,                ///< (SG,EcRealVector) Joint state
   JointController,           ///< (SG,EcJointControllerSystemContainer)
   JointVelocity,             ///< (SG,EcRealVector) Joint velocity
   Manipulator,               ///< (SG,EcIndividualManipulatorVector)
   ManipulatorSystemConfiguration, ///< (SG,EcManipulatorSystemConfiguration)
   ManipulatorGraspingModule, ///< (SG,EcManipulatorGraspingModuleVector)
   ManipulatorLinkProps,      ///< (S ,EcManipulatorLink)
   MeasuredForce,             ///< (SG,EcManipulatorSensorForce)
   OutputWriterVector,        ///< (SG,EcOutputWriterVector)
   PositionControlSystem,     ///< (SG,EcPositionControlSystem)
   PrimaryFrame,              ///< ( G,EcCoordinateSystemTransformation) loc of primary frame
   ProfiledEndEffectors,      ///< (S ,EcU32Vector) end-effectors to use profiled position control
   PropagationResults,        ///< ( G,EcPropagationResultDataVector) Propagation result data for the system
                              ///< ( G,EcPropagationResultData) Propagation result data for a manipulator
   SimulationReset,           ///< (S ,EcBoolean) Reset the simulation to initial state. True if the desired EE placement is
                              ///< to be reset as well or false otherwise.
   SimulationMutex,           ///< ( G,EcSharedMutexLock,EcSharedMutexSharedLock) Sim locking
   SimulationTime,            ///< ( G,EcTime) Simulation Time in seconds
   SimRunState,               ///< (SG,SimulationRunState) State of current simulation
   SpeedFactor,               ///< (SG,EcReal) Speed factor
   State,                     ///< (SG,EcManipulatorSystemState)
   StatedSystem,              ///< ( G,EcStatedSystem)
   StaticCollisionExclusionMap, ///< (SG, EcSystemCollisionExclusionMap) the static collision exclusion map
   StopMotion,                ///< (S ,EcBoolean) Stop the motion of a robot
   SystemDataCapture,         ///< (SG,EcSystemDataCapture)
   SystemEnvironment,         ///< (SG,EcSystemEnvironment)
   SystemSimulation,          ///< (SG,EcSystemSimulation)
   ToolOffset,                ///< (SG,EcCoordinateSystemTransformation) Tool offset
   ViewerParameters,          ///< (SG,EcViewerParameters)
   WhatChanged,               ///< ( G,EcU32) Changed bit flags
   EndOfSimParams             ///< End of enums designation
};

/// Enumeration on state of the current simulation
enum SimulationRunState
{
   SimulationStopped,
   SimulationRunning,
   SimulationPaused
};

/// Bits indicating what changed in the last timestep.  Consumers can use
/// these flags to adjust behavior based on the change.  Note that if the
/// plugin is running at a different rate than the simulation, then there
/// is no guarantee that all changes will be visible.  The changed values
/// are valid only until the next simulation timestep is calculated.
enum BitFlagsEnum
{
   DesiredForceBit =           0x001, ///< DesiredForce change
   DesiredPosBit =             0x002, ///< DesiredEE change
   DesiredVelBit =             0x004, ///< DesiredVel change
   EESetBit =                  0x008, ///< EndEffectorSet change
   StateBit =                  0x010, ///< State change
   ForceControlBit =           0x020, ///< ForceControlOn change
   ForceSensorBit =            0x040, ///< MeasuredForce change
   EESetIndexBit =             0x080, ///< End-effector set index change
   ForceControlDescriptorBit = 0x100, ///< Force descriptor index change
   PositionControlSystemBit =  0x200, ///< PCS change
   ForceControlSystemBit =     0x400, ///< FCS change
   AttachmentMapBit =          0x800, ///< Change in attachment map
   ControlModeBit =           0x1000, ///< Control mode change
};
typedef EcU32 BitFlags; ///< Size of bit flags

} // namespace Ec

#endif // ec_IOParams_H_
