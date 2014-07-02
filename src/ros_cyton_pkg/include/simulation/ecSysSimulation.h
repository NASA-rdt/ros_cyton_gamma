#ifndef ecSysSimulation_H_
#define ecSysSimulation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSysSimulation.h
/// @class EcSystemSimulation
/// @brief Holds a simulation environment for a stated system and its
///        position control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecControlInputConverterContainer.h"
#include "ecDynSimulatorSystem.h"
#include "ecJointControllerSystemContainer.h"
#include "ecSimulationPosContContainer.h"
#include "ecSystemControlExecutive.h"
#include "ecViewerParameters.h"

#include <forceControl/ecForceControlSystem.h>
#include <grasping/ecManipGraspingModule.h>
#include <imageSensor/ecImageSensorVector.h>
#include <manipulator/ecStateRandomVariation.h>
#include <manipulator/ecSystemRandomVariation.h>
#include <simulationAnalysis/ecDisplaySystemDataCapture.h>
#include <simulationAnalysis/ecOutputWriterVector.h>
#include <simulationAnalysis/ecSystemDataCapture.h>
#include <visualization/ecVisualizationParameters.h>

// forward declarations
class EcVisualizableStatedSystem;

/** Holds a simulation environment for a stated system and its
 position control system.
*/
class EC_ACTIN_SIMULATION_DECL EcSystemSimulation : public EcXmlCompoundType
{
public:

   /// default constructor
   EcSystemSimulation
      (
      );

   /// destructor
   virtual ~EcSystemSimulation
      (
      );

   /// copy constructor
   EcSystemSimulation
      (
      const EcSystemSimulation& orig
      );

   /// assignment operator
   EcSystemSimulation& operator=
      (
      const EcSystemSimulation& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemSimulation& orig
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcSystemSimulation& orig
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

   /// gets the system control executive
   virtual const EcSystemControlExecutive& systemControlExecutive
      (
      ) const;

   /// sets the system control executive
   virtual void setSystemControlExecutive
      (
      const EcSystemControlExecutive& value
      );

   /// gets the stated system
   virtual const EcStatedSystem& statedSystem
      (
      ) const;

   /// gets the stated system - non-const version
   virtual EcStatedSystem& statedSystem
	   (
	   );

   /// sets the stated system
   virtual void setStatedSystem
      (
      const EcStatedSystem& statedSystem
      );

   /// get the up gravity vector
   virtual const EcVector& upGravity
      (
      ) const;

   /// set the up-gravity vector
   virtual void setUpGravity
      (
      const EcVector& upGravity
      );

   /// gets the position control system container
   virtual const EcSimulationPositionControlContainer& positionControlContainer
      (
      ) const;

   /// sets the position control system container. This will internally set the stated system of the position control container to controlStatedSystem().
   virtual void setPositionControlContainer
      (
      const EcSimulationPositionControlContainer& positionControlContainer
      );

   /// sets the position control system container. This will internally set the stated system of the position control container to that of the position control system in positionControlContainer (the argument).
   virtual void setPositionControlContainerWithState
      (
      const EcSimulationPositionControlContainer& positionControlContainer
      );

   /// gets the position control system
   virtual const EcPositionControlSystem& positionControlSystem
      (
      ) const;

   /// sets the position control system. This will internally set the stated system of the position control system to controlStatedSystem().
   virtual void setPositionControlSystem
      (
      const EcPositionControlSystem& positionControlSystem
      );

   /// sets the position control system. This will internally set the stated system of the position control system to that of positionControlSystem (the argument).
   virtual void setPositionControlSystemWithState
      (
      const EcPositionControlSystem& positionControlSystem
      );

   /// gets the position control state.
   virtual const EcManipulatorSystemState& positionControlState
      (
      ) const;

   /// sets the position control state.
   virtual void setPositionControlState
      (
      const EcManipulatorSystemState& positionControlState
      );

   /// gets the external-position-control flag
   virtual EcBoolean externalPositionControl
      (
      ) const;

   /// sets the external-position-control flag
   virtual void setExternalPositionControl
      (
      const EcBoolean value
      );

   /// sets the external control torque flags
   void setExternalControlTorqueFlags
      (
      const EcBooleanVectorVector& flags
      );

   /// sets the external control torques
   void setExternalControlTorques
      (
      const EcManipulatorTorqueVector& controlTorqueVector
      );

   /// initialize the entire simulation from a position control system
   virtual EcBoolean setFromPositionControlSystem
      (
      const EcPositionControlSystem& positionControlSystem,
      const EcVisualizationParameters& visualizationParameters
      );

   /// sets the stated system and position control system
   /// This should always be used to initially configure
   /// these components.
   virtual void setStatedAndPositionControlSystem
      (
      const EcStatedSystem& statedSystem,
      const EcPositionControlSystem& positionControlSystem
      );

   /// gets the joint controller system container
   virtual const EcJointControllerSystemContainer& jointControllerSystemContainer
      (
      ) const;

   /// sets the joint controller system container
   virtual void setJointControllerSystemContainer
      (
      const EcJointControllerSystemContainer& jointControllerSystemContainer
      );

   /// gets the dynamic simulator system
   virtual const EcDynamicSimulatorSystem& dynamicSimulatorSystem
      (
      ) const;

   /// sets the dynamic simulator system
   virtual void setDynamicSimulatorSystem
      (
      const EcDynamicSimulatorSystem& dynamicSimulatorSystem
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

   /// gets the time step
   virtual EcReal timeStep
      (
      ) const;

   /// sets the time step
   virtual void setTimeStep
      (
      const EcReal timeStep
      );

   /// gets the maximum number of iterations
   virtual EcU32 maxIterations
      (
      ) const;

   /// sets the maximum number of iterations
   virtual void setMaxIterations
      (
      const EcU32 maxIterations
      );

   /// gets the flag specifying dynamic simulation
   virtual EcBoolean dynamicallySimulate
      (
      ) const;

   /// sets the flag specifying dynamic simulation
   virtual void setDynamicallySimulate
      (
      const EcBoolean dynamicallySimulate=EcTrue
      );

   /// gets the visualization parameters
   virtual const EcVisualizationParameters& visualizationParameters
      (
      ) const;

   /// sets the visualization parameters
   virtual void setVisualizationParameters
      (
      const EcVisualizationParameters& visualizationParameters
      );

   /// gets the random number seet
   virtual EcU32 randomNumberSeed
      (
      ) const;

   /// sets the random number seet
   virtual void setRandomNumberSeed
      (
      const EcU32 randomNumberSeed
      );

   /// gets the viewer parameters
   virtual const EcViewerParameters& viewerParameters
      (
      ) const;

   /// sets the viewer parameters
   virtual void setViewerParameters
      (
      const EcViewerParameters& viewerParameters
      );

   /// get the last applied torques
   virtual const EcManipulatorTorqueVector& lastAppliedTorques
      (
      ) const;

   /// get the last computed control inputs
   virtual const EcManipulatorControlInputVector& lastComputedControlInputs
      (
      ) const;

   /// gets the desired end-effector placements
   virtual const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      (
      ) const;

   /// sets the desired end-effector placements
   virtual void setDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      );

   /// sets a desired end-effector placement for a manipulator
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& desiredPlacement,
      const EcU32 manipulatorIndex
      );

   /// sets an individual desired end-effector placement
   virtual void setDesiredPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcCoordinateSystemTransformation& desiredPlacement
      );

   /// sets the relative link data
   virtual void setEndEffectorRelativeLinkData
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the desired end-effector velocities
   virtual const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      (
      ) const;

   /// get the manipulator index from base link label
   virtual EcBoolean lookupManipulatorIndexFromLabel
           (
           const EcString& label,
           EcU32& manipIndex
           ) const;

   /// sets the desired end-effector velocities
   virtual void setDesiredVelocityVector
      (
      const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      );

   /// add desired placement to the end of desired placement in
   virtual void addDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      );

   /// gets the actual end-effector placements
   virtual const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      (
      ) const;

   /// sets the actual end-effector placements
   virtual void setActualPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      );

   /// sets the active control description of a manipulator by index
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the control descriptions will be set.
   \param[in] controlDescriptionIndex The index of the active control description to be set.
   \return True if successful or false if either manipulatorIndex or activeControlDescriptionIndex is out of range.
   */
   virtual EcBoolean setActiveControlDescription
      (
      const EcU32 manipulatorIndex,
      const EcU32 controlDescriptionIndex
      );

   /// gets the index of the active control description of the specified manipulator
   /**
   \param[in] manipulatorIndex The index of the manipulator in query.
   \return The index of the active control description of the specified manipulator.
   */
   virtual EcU32 activeControlDescriptionIndex
      (
      const EcU32 manipulatorIndex
      ) const;

   /// gets control expression description
   virtual const EcControlExpressionDescription& controlExpressionDescription
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets control expression description
   virtual void setControlExpressionDescription
      (
      const EcControlExpressionDescription& controlExpressionDescription,
      const EcU32 manipulatorIndex
      );

   /// gets an end effector
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets an end effector
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcU32 manipulatorIndex
      );

   /// resets time to zero while keepting the current state
   virtual void resetTime
      (
      );

   /// initialize the entire simulation from a visualizable stated system
   virtual void setFromVisualizableStatedSystem
      (
      const EcVisualizableStatedSystem& visStatedSystem
      );

   /// get the corresponding visualizable stated system
   virtual void getVisualizableStatedSystem
      (
      EcVisualizableStatedSystem& visStatedSystem
      ) const;

   /// gets manipulator grasping module vector
   virtual const EcManipulatorGraspingModuleVector& manipulatorGraspingModules
      (
      ) const;

   /// sets manipulator grasping module vector
   virtual void setManipulatorGraspingModules
      (
      const EcManipulatorGraspingModuleVector& manipulatorGraspingModules
      );

   /// get func for force control system
   const EcForceControlSystem& forceControlSystem
      (
      ) const;

   /// set func for force control system
   void setForceControlSystem
      (
      const EcForceControlSystem& forceControlSystem
      );

   /// sets the active force control description of a manipulator by index
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the force control description will be set.
   \param[in] activeControlDescriptionIndex The index of the active control description to be set.
   \return True if successful or false if either manipulatorIndex or activeControlDescriptionIndex is out of range.
   */
   virtual EcBoolean setActiveForceControlDescription
      (
      const EcU32 manipulatorIndex,
      const EcU32 activeControlDescriptionIndex
      );

   /// turn on/off a group of force controllers for a given manipulator
   virtual EcBoolean enableForceControllers
      (
      const EcU32 manipulatorIndex,
      const EcU32Vector& controllerIndices,
      const EcBoolean isOn
      );

   /// set the desired forces for force control
   virtual void setDesiredForceVector
      (
      const EcManipulatorSensorForceVector& desiredForceVec
      );

   /// set the measured forces for force control
   virtual void setMeasuredForceVector
      (
      const EcManipulatorSensorForceVector& measuredForceVec
      );

   /// get the initial state. This is the state to which the simulation will reset when the simulation time is reset.
   virtual const EcManipulatorSystemState& initialState
      (
      ) const;

   /// set the initial state
   virtual void setInitialState
      (
      const EcManipulatorSystemState& state
      );

   /// calculate a new manipulator state
   virtual EcBoolean calculateState
      (
      const EcReal time,
      EcManipulatorSystemState& state
      );

   /// find and convert explicit manipulator link descriptions to references
   /// where possible
   virtual EcBoolean findAndConvertToReferences
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
   static EcSystemSimulation nullObject
      (
      );

   /// gets the is force control on
   virtual EcBoolean isForceControlOn
      (
      ) const;

   /// set is force control on
   void setIsForceControlOn
      (
      const EcBoolean isForceControlOn
      );

   /// gets Guide Frame EndEffector Set Vector
   virtual const EcEndEffectorSetVector& guideFrameEndEffectorSetVec
      (
      ) const;

   /// set Guide Frame EndEffector Set Vector
   void setGuideFrameEndEffectorSetVec
      (
      const EcEndEffectorSetVector& guideFrameEndEffectorSetVec
      );

   /// sets the state of the system. It also initializes everything.
   virtual void setState
      (
      const EcManipulatorSystemState& state
      );

   /// sets the current state of the system without re-initializing
   virtual void setCurrentState
      (
      const EcManipulatorSystemState& state
      );

   /// feed back the externally sensed position state to the position controller
   /**
   \param[in] state The sensed state to be fed back.
   \param[in] timeStep The time step of how frequently this method is called.
   \param[in] notSetFlags The flags indicating which manipulator states will not be fed back. If this vector
   is empty, then all the states will be fed back.
   \param[in] baseOnly If true only the sensed bases will be fed back.
   */
   void setSensedState
      (
      const EcManipulatorSystemState& state,
      const EcReal timeStep,
      const EcBooleanVector& notSetFlags = EcBooleanVector(),
      const EcBoolean baseOnly = EcFalse
      );

   /// feed back the externally sensed position state of a given manipulator to the position controller
   /**
   \param[in] manipIndex The index of the manipulator for which the sensed state will be fed back
   \param[in] posState The sensed position state to be fed back.
   \param[in] timeStep The time step of how frequently this method is called.
   \param[in] baseOnly If true only the sensed base will be fed back.
   */
   virtual void setSensedState
      (
      const EcU32 manipIndex,
      const EcPositionState& posState,
      const EcReal timeStep,
      const EcBoolean baseOnly = EcFalse
      );

   /// return the system data capture for storage.
   virtual const EcSystemDataCapture& storageSystemDataCapture
      (
      ) const;

   /// set the system data capture for storage
   virtual void setStorageSystemDataCapture
      (
      const EcSystemDataCapture& systemDataCapture
      );

   /// capture the data for storage
   virtual void captureStorageData
      (
      ) const;

   /// return the vector of system data captures for display.
   virtual const EcDisplaySystemDataCaptureVector& displaySystemDataCaptureVector
      (
      ) const;

   /// set the vector of system data captures for display
   virtual void setDisplaySystemDataCaptureVector
      (
      const EcDisplaySystemDataCaptureVector& value
      );

   /// capture the data for display
   virtual void captureDisplayData
      (
      ) const;

   /// return a vector of writers that write the simulation outputs to different file formats
   virtual const EcOutputWriterVector& outputWriterVector
      (
      ) const;

   /// set a vector of writers that write the simulation outputs to different file formats
   virtual void setOutputWriterVector
      (
      const EcOutputWriterVector& outputWriterVector
      );

   /// return the vector of image sensors
   virtual const EcImageSensorVector& imageSensorVector
      (
      ) const;

   /// set the vector of image sensors
   virtual void setImageSensorVector
      (
      const EcImageSensorVector& imageSensorVector
      );

   /// get the propagation results from the control system
   virtual const EcPropagationResultDataVector& propagationResultDataVector
      (
      ) const;

   /// generate a collision report for the state as it currently stands
   virtual EcBoolean generateCollisionReport
      (
      EcPropagationResultDataVector& collisions
      ) const;

   /// gets the flag indicating whether or not the simulation should share the stated system with control
   virtual EcBoolean shareStatedSystemWithControl
      (
      ) const;

   /// sets the flag indicating whether or not the simulation should share the stated system with control
   virtual void setShareStatedSystemWithControl
      (
      const EcBoolean value
      );

   /// gets the stated system for control.
   virtual const EcStatedSystem& controlStatedSystem
      (
      ) const;

   /// sets the stated system for control. If shareStatedSystemWithControl is set to true, then this will do nothing since control will use the same stated system with simulation
   virtual void setControlStatedSystem
      (
      const EcStatedSystem& statedSystem
      );

   /// gets the flag indicating whether or not noise is on in the simulation. If it's on, then noise will be introduced to the control torque, the actual position measurements, and the actual velocity measurements.
   virtual EcBoolean noiseInSimulationFlag
      (
      ) const;

   /// sets the noise in simulation flag
   virtual void setNoiseInSimulationFlag
      (
      const EcBoolean value
      );

   /// gets the one sigma values for joint torques for all manipulators
   virtual const EcXmlRealVectorVector& jointTorqueOneSigmas
      (
      ) const;

   /// sets the one sigma values for joint torques for all manipulators
   virtual void setJointTorqueOneSigmas
      (
      const EcXmlRealVectorVector& values
      );

   /// sets the one sigma values for joint position sensors for all manipulators
   virtual void setJointPositionOneSigmas
      (
      const EcXmlRealVectorVector& values
      );

   /// sets the one sigma values for joint velocity sensors for all manipulators
   virtual void setJointVelocityOneSigmas
      (
      const EcXmlRealVectorVector& values
      );

   /// gets the system random variation. This is primarily used in Monte Carlo studies.
   virtual const EcSystemRandomVariation& systemRandomVariation
      (
      ) const;

   /// sets the system random variation
   virtual void setSystemRandomVariation
      (
      const EcSystemRandomVariation& value
      );

   /// gets the state random variation. This is primarily used in Monte Carlo studies.
   virtual const EcStateRandomVariation& stateRandomVariation
      (
      ) const;

   /// sets the state random variation
   virtual void setStateRandomVariation
      (
      const EcStateRandomVariation& value
      );

   /// gets the container that converts the control torques to control inputs
   virtual const EcControlInputConverterContainer& controlInputConverterContainer
      (
      ) const;

   /// gets the container that converts the control torques to control inputs
   virtual void setControlInputConverterContainer
      (
      const EcControlInputConverterContainer& value
      );

   /// a flag indicating whether to use control torques in dynamic simulation. If false, control torques will be converted to control inputs and the control inputs will be used in simulation
   virtual EcBoolean useControlTorquesInDynamicSimulation
      (
      ) const;

   /// sets whether to use control torques in dynamic simulation
   virtual void setUseControlTorquesInDynamicSimulation
      (
      const EcBoolean value
      );

   /// returns true if the system has recently been modified. This is useful for rendering since it needs to grab internal pointers of the system and if it has been modified, those pointers will be invalid. Rendering can check it and if the system has just been modified, it can grab new pointers.
   virtual EcBoolean isSystemModified
      (
      ) const;

   /// sets isSystemModified to false. Rendering should call this after it's done grabbing new pointers to the system internals.
   virtual void resetIsSystemModified
      (
      );

   /// set the self collisin map for manipulator manipID
   virtual EcBoolean setSelfCollisionMap
      (
      const EcManipulatorSelfCollisionLinkMap& map,
      const EcU32 manipID
      );

   /// pass through to set the timestep in the dynamic simulator system
   virtual void setDynamicSystemTimeStep
      (
      const EcReal timestep
      );

   /// pass through to get the timestep in the dynamic simulator system
   virtual EcReal dynamicSystemTimeStep
      (
      ) const;

   /// delete a manipulator and corresponding data (e.g. position and velocity states, end-effectors, etc.)
   /**
   \param[in] manipLabel The string label of the manipulator to be deleted.
   \return The index of the deleted manipulator if the manipulator was found and successfully deleted. If the manipulator was not found, then this returns -1.
   */
   virtual EcInt32 deleteManipulator
      (
      const EcString& manipLabel
      );

   /// delete a manipulator and corresponding data (e.g. position and velocity states, end-effectors, etc.)
   /// \param[in] manIndex The manipulator index to delete.
   /// \return EcBoolean Success or failure of the command.
   virtual EcBoolean deleteManipulator
      (
      const EcU32 manIndex
      );

   /// add a manipulator and corresponding data (e.g. position and velocity states, end-effectors, etc.)
   /**
   \return The index of the newly added manipulator.
   */
   virtual EcU32 addManipulator
      (
      const EcIndividualManipulator& manip,
      const EcPositionState& position
      );

   /// insert an avoidance region into the system
   virtual EcBoolean addAvoidanceRegion
      (
      const EcShape& shape,
      const EcString& regionName,
      const EcCoordinateSystemTransformation& position,
      const EcDataMap& color = EcDataMap::boundingColor()
      );

   /// get the index of the active control method
   virtual EcU32 activePositionControlMethodIndex
      (
      const EcU32 manipIndex
      ) const;

   /// set the active control method
   virtual EcBoolean setActivePositionControlMethod
      (
      const EcU32 manipIndex,
      const EcU32 methodIndex
      );

   /// get the index of the active end-effector set
   virtual EcU32 activeEndEffectorSetIndex
      (
      const EcU32 manipIndex
      ) const;

   /// set the active control method
   virtual EcBoolean setActiveEndEffectorSet
      (
      const EcU32 manipIndex,
      const EcU32 eeSetIndex
      );

   /// exchange the manipulator (and its controller) at the specified index with one from another simulation
   virtual EcBoolean exchangeManipulator
      (
      const EcU32 manipIndex,
      const EcSystemSimulation& other,
      const EcU32 otherManipIndex
      );

   /// \copydoc EcPositionControlSystem::setSpeedFactor()
   virtual EcBoolean setSpeedFactor
      (
      const EcU32 manipIndex,
      const EcReal speedFactor
      );

   /// \copydoc EcPositionControlSystem::setProfiledPositionEndEffectors()
   virtual EcBoolean setProfiledPositionEndEffectors
      (
      const EcU32 manipIndex,
      const EcU32Vector& indices
      );

   /// set the manipulator attachment map
   virtual void setAttachmentMap
      (
      const EcManipulatorAttachmentMap& value
      );

   /// set the dynamic collision exclusion map
   virtual void setDynamicCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// set the static collision exclusion map
   virtual void setStaticCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// @copydoc EcPositionControlSystem::setControlMode
   virtual EcBoolean setControlMode
      (
      const EcU32 manipIndex,
      const EcU32 mode
      );
protected:

   /// initializes member variables
   virtual void initializeComponents
      (
      );

   /// initializes member variables related to control
   virtual void initializeControlComponents
      (
      );

   /// dynamically simulate one step forward.
   virtual EcBoolean dynamicallySimulateOneStep
      (
      const EcReal timeStep
      );

   /// limit control torques to the physical limits
   virtual void limitControlTorques
      (
      EcManipulatorTorqueVector& manipTorqueVector
      ) const;


   /// calculate force control placement and set the position
   virtual EcBoolean calcForcePlacement
      (
      const EcReal time
      );

   /// update the position control state using the dynamic simulation
   virtual void updatePositionControlState
      (
      const EcReal timeStep
      );

   /// add noise to control torques
   virtual void addNoiseToControlTorques
      (
      EcManipulatorTorqueVector& manipTorqueVector,
      const EcXmlRealVectorVector& oneSigmasVector
      ) const;

   /// register the component creators of some classes that have not been registered (most likely because registering those component creators may cause cyclic dependency) to the reader stream so the components can be read in properly.
   virtual void registerComponentCreators
      (
      EcXmlReader& stream
      );

   /// add necessary components
   virtual void addComponents
      (
      );

   /// delete components for a manipulator
   virtual void deleteComponents
      (
      const EcU32 manipIndex
      );

protected:

   /// the system control executive
   EcSystemControlExecutive                     m_SystemControlExecutive;

   /// the force control system
   EcForceControlSystem                         m_ForceControlSystem;

   /// the joint controller system
   EcJointControllerSystemContainer             m_JointControllerSystemContainer;

   /// the dynamic simulator
   EcDynamicSimulatorSystem                     m_DynamicSimulatorSystem;

   /// the time step for dynamic simulation
   EcXmlReal                                    m_TimeStep;

   /// the maximum number of iterations per call
   EcXmlU32                                     m_MaxIterations;

   /// a flag indicating whether or not to dynamically simulate
   EcXmlBoolean                                 m_DynamicallySimulate;

   /// visualization parameters
   EcVisualizationParameters                    m_VisualizationParameters;

   /// viewer parameters
   EcViewerParameters                           m_ViewerParameters;

   /// grasping container
   EcManipulatorGraspingModuleVector            m_ManipulatorGraspingModules;

   /// a random number seed
   EcXmlU32                                     m_RandomNumberSeed;

   /// an object used to capture and store system data
   EcSystemDataCapture                          m_StorageSystemDataCapture;

   /// to configure multiple data capture objects for display (plotting)
   EcDisplaySystemDataCaptureVector             m_vDisplaySystemDataCapture;

   /// write the simulation outputs to different file formats
   EcOutputWriterVector                         m_vOutputWriters;

   /// a vector of image sensors
   EcImageSensorVector                          m_vImageSensors;

   /// the flag indicating whether or not noise is on in the simulation
   EcXmlBoolean                        m_NoiseInSimulationFlag;

   /// the one sigma values for joint torque noise
   EcXmlRealVectorVector               m_vJointTorqueOneSigmas;

   /// the system random variation
   EcSystemRandomVariation    m_SystemRandomVariation;

   /// the state random variation
   EcStateRandomVariation     m_StateRandomVariation;

   /// container that converts control torques to control inputs
   EcControlInputConverterContainer    m_ControlInputConverterContainer;

   /// a flag indicating whether to use control torques in dynamic simulation
   EcXmlBoolean               m_UseControlTorques;

   // the following XML data for backward compatibilty
   /// the stated system
   EcStatedSystem                               m_StatedSystem;

   /// the position control system
   EcSimulationPositionControlContainer         m_PositionControlContainer;

   /// the stated system for control
   EcStatedSystem                      m_ControlStatedSystem;

   /// a flag indicating whether or not the simulation should share the stated system with control
   EcXmlBoolean                        m_ShareStatedSystemWithControl;

   // non-XML data below

   /// holds the latest result from the position control system
   EcManipulatorSystemState                     m_PositionControlState;

   /// holds the applied torques on the manipulator
   EcManipulatorTorqueVector                    m_ManipulatorTorques;

   /// holds the control inputs
   EcManipulatorControlInputVector              m_ManipulatorControlInputs;

   /// holds the initial state of the system
   EcManipulatorSystemState                     m_InitialSystemState;

   /// holds the initial dynamic simulator system
   EcDynamicSimulatorSystem                     m_InitialDynamicSimulatorSystem;

   /// flag indicating needs to update endeffector
   EcBoolean                                    m_NeedToUpdateEndEffectors;

   /// a variable to hold the dynamic simulation time
   EcReal                                       m_DynamicSimulationTime;

   /// holds the external control torques on the manipulator
   EcManipulatorTorqueVector                    m_ExternalControlTorques;

   /// a utility vector for boolean flags
   mutable EcBooleanVector                      m_UtilityEmptyBooleanVector;
};

#endif // ecSysSimulation_H_
