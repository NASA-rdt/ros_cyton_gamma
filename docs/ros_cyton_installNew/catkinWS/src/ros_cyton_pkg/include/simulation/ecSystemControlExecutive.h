#ifndef ecSystemControlExecutive_H_
#define ecSystemControlExecutive_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemControlExecutive.h
/// @class EcSystemControlExecutive
/// @brief Holds a stated system and its position control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecSimulationPosContContainer.h"

#include <control/ecPosContSystem.h>
#include <manipulator/ecStatedSystem.h>

// forward declarations
class EcVisualizableStatedSystem;

/** Holds a stated system and its position control system.
*/
class EC_ACTIN_SIMULATION_DECL EcSystemControlExecutive : public EcXmlCompoundType
{
public:

   /// default constructor
   EcSystemControlExecutive
      (
      );

   /// destructor
   virtual ~EcSystemControlExecutive
      (
      );

   /// copy constructor
   EcSystemControlExecutive
      (
      const EcSystemControlExecutive& orig
      );

   /// assignment operator
   EcSystemControlExecutive& operator=
      (
      const EcSystemControlExecutive& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemControlExecutive& orig
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcSystemControlExecutive& orig
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

   /// gets the position control system container -- non-const version
   virtual EcSimulationPositionControlContainer& positionControlContainer
      (
      );

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

   /// gets the position control system -- non-const
   virtual EcPositionControlSystem& positionControlSystem
      (
      );

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

   /// gets the external-position-control flag
   virtual EcBoolean externalPositionControl
      (
      ) const;

   /// sets the external-position-control flag
   virtual void setExternalPositionControl
      (
      const EcBoolean externalPositionControl
      );

   /// sets the stated system and position control system
   /// This should always be used to initially configure
   /// these components.
   virtual void setStatedAndPositionControlSystem
      (
      const EcStatedSystem& statedSystem,
      const EcPositionControlSystem& positionControlSystem
      );

   /// gets the desired end-effector placements
   virtual const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      (
      ) const;

   /// sets the desired end-effector placements
   virtual void setDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      );

   /// sets an desired end-effector placement for a manipulator
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

   /// initialize from a stated system
   void setFromStatedSystem
      (
      const EcStatedSystem& statedSystem
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
   static EcSystemControlExecutive nullObject
      (
      );

   /// check for the dimensional integrity of components
   virtual EcBoolean integrityCheck
      (
      ) const;

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

   /// gets the stated system for control - non-const version
   virtual EcStatedSystem& controlStatedSystem
      (
      );

   /// sets the stated system for control. If shareStatedSystemWithControl is set to true, then this will do nothing since control will use the same stated system with simulation
   virtual void setControlStatedSystem
      (
      const EcStatedSystem& statedSystem
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

   /// set the state of the control stated system
   virtual void setControlStatedSystemState
      (
      const EcManipulatorSystemState& state
      );

   /// exchange the manipulator (and its controller) at the specified index with one from another EcSystemControlExecutive
   virtual EcBoolean exchangeManipulator
      (
      const EcU32 manipIndex,
      const EcSystemControlExecutive& other,
      const EcU32 otherManipIndex
      );

   /// @copydoc EcPositionControlSystem::setControlMode
   virtual EcBoolean setControlMode
      (
      const EcU32 manipIndex,
      const EcU32 mode
      );

protected:

   /// build a control system for an avoidance region
   virtual void buildAvoidanceRegionControlSystem
      (
      const EcIndividualManipulator& avoidanceRegion,
      EcControlExpressionDescription& contDesc,
      EcEndEffectorSet& eeSet,
      const EcBoolean& isFixedBase = EcTrue
      ) const;

   /// initializes member variables
   virtual void initializeComponents
      (
      );

protected:
   /// the stated system
   EcStatedSystem                       m_StatedSystem;

   /// the position control system
   EcSimulationPositionControlContainer m_PositionControlContainer;

   /// a flag indicating whether or not the simulation should share the stated system with control
   EcXmlBoolean                         m_ShareStatedSystemWithControl;

   /// the stated system for control
   EcStatedSystem                       m_ControlStatedSystem;

   // non-XML data below

   /// hold a copy of end effector set related to guide frame, to distinguish them
   /// from the ones created by force control or other process
   EcEndEffectorSetVector               m_GuideFrameEndEffectorSetVec;

   /// flag indicating needs to update endeffector
   EcBoolean                            m_NeedToUpdateEndEffectors;

   /// a flag indicating that external position control is being used
   EcBoolean                            m_ExternalPositionControl;
};

#endif // ecSystemControlExecutive_H_
