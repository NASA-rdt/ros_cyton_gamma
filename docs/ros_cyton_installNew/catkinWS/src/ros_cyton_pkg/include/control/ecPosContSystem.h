#ifndef ecPosContSystem_H_
#define ecPosContSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPosContSystem.h
/// @class EcPositionControlSystem
/// @brief Holds a description of a position control system
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecAntiCollisionPriorityList.h"
#include "ecEndEffectorTool.h"
#include "ecIndVelContDesc.h"
#include "ecManipEndEffectorAcc.h"
#include "ecManipEndEffectorVel.h"
#include "ecPositionControllerVector.h"
#include "ecPositionControlOutputFilterVector.h"
#include "ecSupplementalControlState.h"
#include "ecVelContSystem.h"

#include <xml/ecXmlCompType.h>

/// Holds a description of a position control system, which at the most basic is a vector of
/// position controllers, each of which controls a manipulator in the system.
class EC_ACTIN_CONTROL_DECL EcPositionControlSystem : public EcXmlCompoundType
{
public:
   enum {
      POSITIONCONTROLRESULT   =EcPositionController::POSITIONCONTROLRESULT,
      DESIREDVELOCITYBASED    =EcPositionController::DESIREDVELOCITYBASED,
      ZERO                    =EcPositionController::ZERO,
      FINITEDIFFERENCERESULT  =EcPositionController::FINITEDIFFERENCERESULT
   };

   enum {
      POSITION_CONTROL =EcPositionController::POSITION_CONTROL,
      VELOCITY_CONTROL =EcPositionController::VELOCITY_CONTROL,
      PROFILED_POSITION=EcPositionController::PROFILED_POSITION
   };

   /// default constructor
   EcPositionControlSystem
      (
      );

   /// destructor
   virtual ~EcPositionControlSystem
      (
      );

   /// copy constructor
   EcPositionControlSystem
      (
      const EcPositionControlSystem& orig
      );

   /// assignment operator
   EcPositionControlSystem& operator=
      (
      const EcPositionControlSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlSystem& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   /**
       \param other XML object to test against
       \return equality test result
   */
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \return cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// adds control description of input container to
   /// current control description
   /**
       \param orig container to merge with
       \return error flag
   */
   virtual EcBoolean mergeWith
      (
      const EcPositionControlSystem& orig
      );

   /// gets the vector of position controllers
   virtual const EcPositionControllerVector& positionControllers
      (
      ) const;

   /// gets the vector of position controllers
   virtual void setPositionControllers
      (
      const EcPositionControllerVector& controllers
      );

   /// exchange the position controller at the index
   virtual EcBoolean exchangePositionController
      (
      EcU32 index,
      const EcPositionController& posController
      );

   /// add a position controller
   virtual void addPositionController
      (
      const EcPositionController& posController
      );

   /// delete position controller
   virtual EcBoolean deletePositionController
      (
      EcU32 index
      );

   /// sets the velocity control system. Depracated.
   virtual void setVelocityControlSystem
      (
      const EcVelocityControlSystem& velocityControlSystem
      );

   /// gets the stated system
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// sets the stated system
   virtual void setStatedSystem
      (
      const EcStatedSystem* statedSystem
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

   /// get the current time
   virtual EcReal time
      (
      ) const;

   /// set the current time
   virtual void setTime
      (
      EcReal time
      );

   /// set the current state
   virtual void setCurrentState
      (
      const EcManipulatorSystemState& state
      );

   /// gets the maximum number of iterations in a cycle
   virtual EcU32 maxIterations
      (
      ) const;

   /// sets the maximum number of iterations in a cycle
   virtual void setMaxIterations
      (
      EcU32 maxIterations
      );

   /// gets the maximum final propagation size in steps
   virtual EcU32 maxFinalPropagationSize
      (
      ) const;

   /// sets the maximum final propagation size in steps
   virtual void setMaxFinalPropagationSize
      (
      EcU32 maxFinalPropagationSize
      );

   /// gets a flag indicating whether or not the position control system is on
   virtual EcBoolean isOn
      (
      ) const;

   /// sets a flag indicating whether or not the position control system is on
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets the collision avoidance mode
   virtual EcU32 collisionAvoidanceMode
      (
      ) const;

   /// sets the collision avoidance mode
   virtual void setCollisionAvoidanceMode
      (
      EcU32 collisionAvoidanceMode
      );

   /// gets the collision breakdown threshold
   /**
       \return  collision breakdown threshold
   */
   virtual const EcReal collisionBreakdownThreshold
      (
      ) const;

   /// sets the collision breakdown threshold
   virtual void setCollisionBreakdownThreshold
      (
      const EcReal collisionBreakdownThreshold
      );

   /// gets the precision level
   virtual EcU32 bvhPrecisionLevel
      (
      ) const;

   /// sets the  precision level
   virtual void setBvhPrecisionLevel
      (
      EcU32 level
      );

   /// gets the data-map pointer for a specified manipulator
   const EcDataMap* dataMapPointer
      (
      EcU32 manipulatorIndex
      ) const;

   /// sets the data-map pointer for a specified manipulator
   void setDataMapPointer
      (
      EcU32 manipulatorIndex,
      const EcDataMap* pDataMap
      );

   /// gets the system active state
   virtual EcSystemActiveState& systemActiveState
      (
      ) const;

   /// gets the active state of a manipulator
   virtual EcManipulatorActiveState& activeState
      (
      EcU32 manipIndex
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

   /// sets an individual desired end-effector placement
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& desiredPlacement,
      const EcU32 manipulatorIndex
      );

   /// gets an individual desired end-effector placement.  Returns
   /// identity if the indices are not valid.
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \return commanded placement for one end effector
   */
   virtual const EcEndEffectorPlacement& desiredPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// sets an individual desired end-effector placement (returns True for success)
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \param placementInRelative commanded placement for one end-effector in the primary frame of the end-effector's relative link. If the end-effector is not relative, then it's the placement in the system coordinates.
       \return error flag
   */
   virtual EcBoolean setDesiredPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcEndEffectorPlacement& placementInRelative
      );

   /// add desired placement
   virtual void addDesiredPlacement
      (
      const EcU32 manipulatorIndex,
      const EcManipulatorEndEffectorPlacement& placement
      );

   /// gets the relative link data.  Returns identity if the indices
   /// are not valid.
   /**
       \param manipulatorIndex index for selecting the manipulator
       \param endEffectorIndex index for selecting the end effector
       \return relative link data for end effector
   */
   virtual const EcEndEffectorRelativeLinkData& endEffectorRelativeLinkData
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// sets the relative link data
   /**
       \param manipulatorIndex index for selecting the manipulator
       \param endEffectorIndex index for selecting the end effector
       \param relData relative link data for end effector
       \return error flag
   */
   virtual EcBoolean setEndEffectorRelativeLinkData
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the desired end-effector velocities
   /**
       \return commanded velocity vector
   */
   virtual const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      (
      ) const;

   /// sets the desired end-effector velocities
   /**
       \param desiredVelocityVector commanded velocity vector
   */
   virtual void setDesiredVelocityVector
      (
      const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      );

   /// sets an individual desired end-effector velocity
   virtual void setDesiredVelocity
      (
      const EcManipulatorEndEffectorVelocity& desiredVelocity,
      const EcU32 manipulatorIndex
      );

   /// sets an individual desired end-effector velocity (returns True for success)
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \param velocity commanded velocity for one end effector
       \return error flag
   */
   virtual EcBoolean setDesiredVelocity
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcXmlRealVector& velocity
      );

   /// zeros the desired velocity vector
   virtual void zeroDesiredVelocityVector
      (
      );

   /// set the passed value to a zero desired velocity vector
   virtual void setToZeroDesiredVelocityVector
      (
      EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      ) const;

   /// gets an individual actual end-effector placement
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \return end effector placement
   */
   virtual const EcEndEffectorPlacement& actualPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// gets the actual end-effector placements
   /**
       \return current placement vector
   */
   virtual const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      (
      ) const;

   /// sets the actual end-effector placements
   /**
       \param actualPlacementVector current placement vector
   */
   virtual void setActualPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      );

   /// adds a control control description and an effector set with default parameters
   /**
   \param[in] manipulator The manipulator for which the control description and end effector will be added.
   \param[in] manipulatorIndex The index of the manipulator to which the control description and end effector will be added.
   \return True if successful.
   */
   virtual EcBoolean addDefaultControlDescriptionAndEndEffectorSet
      (
      const EcIndividualManipulator& manipulator,
      const EcU32 manipulatorIndex
      );


   /// sets the active control description of a manipulator by index
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the active control description will be set.
   \param[in] index The index of the active control description to be set.
   \return True if successful or false if either manipulatorIndex or v is out of range.
   */
   virtual EcBoolean setActiveControlDescription
      (
      const EcU32 manipulatorIndex,
      const EcU32 index
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
   /**
       \param manipulatorIndex index for selecting manipulator
       \return control expression description for one manipulator
   */
   virtual const EcControlExpressionDescription& controlExpressionDescription
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets control expression description
   /**
       \param controlExpressionDescription control expression description for one manipulator
       \param manipulatorIndex index for selecting manipulator
   */
   virtual void setControlExpressionDescription
      (
      const EcControlExpressionDescription& controlExpressionDescription,
      const EcU32 manipulatorIndex
      );

   /// sets the active end-effector set of a manipulator by index
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the active end-effector set will be set.
   \param[in] index The index of the active end-effector set to be set.
   \return True if successful or false if either manipulatorIndex or index is out of range.
   */
   virtual EcBoolean setActiveEndEffectorSet
      (
      const EcU32& manipulatorIndex,
      const EcU32& index
      );

   /// gets the index of the active end-effector set of the specified manipulator
   /**
   \param[in] manipulatorIndex The index of the manipulator in query.
   \return The index of the active end-effector set of the specified manipulator.
   */
   virtual EcU32 activeEndEffectorSetIndex
      (
      const EcU32& manipulatorIndex
      ) const;

   /// gets end effector set
   /**
       \param manipulatorIndex index for selecting manipulator
       \return end effector data for one manipulator
   */
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets an end effector set
   /**
       \param endEffectorSet end effector data for one manipulator
       \param manipulatorIndex index for selecting manipulator
   */
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcU32 manipulatorIndex
      );

   /// calculate a new manipulator state
   /**
       \param time current time
       \param state state for rendering
       \return error flag
   */
   virtual EcBoolean calculateState
      (
      EcReal time,
      EcManipulatorSystemState& state
      );

   /// feed back the externally sensed position state to the position controller
   /**
   \param[in] state The sensed state to be fed back.
   \param[in] timeStep The time step of how frequently this method is called.
   \param[in] notSetFlags The flags indicating which manipulator states will not be fed back. If this vector
   is empty, then all the states will be fed back.
   \param[in] baseOnly If true only the sensed bases will be fed back.
   */
   virtual void setSensedState
      (
      const EcManipulatorSystemState& state,
      EcReal timeStep,
      const EcBooleanVector& notSetFlags = EcBooleanVector(),
      EcBoolean baseOnly = EcFalse
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
      EcU32 manipIndex,
      const EcPositionState& posState,
      EcReal timeStep,
      EcBoolean baseOnly = EcFalse
      );

   /// calculate the placement of an end-effector in the manipulator specified by a given index
   /**
   \param[in] manipIndex The index of the manipulator.
   \param[in] endEffectorIndex The index of the end-effector whose placement is to be calculated.
   \param[in, out] activeState The active state of the manipulator. Some elements of the active state may be modified.
   \param[out] placementInSys Upon return, the placement of the end-effector in the system coordinates.
   \return False if the index is out of range or true otherwise.
   */
   virtual EcBoolean calcEndEffectorPlacement
      (
      EcU32 manipIndex,
      EcU32 endEffectorIndex,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placementInSys
      ) const;

   /// calculate the placements of all end-effectors in the manipulator specified by a given index
   /**
   \param[in] manipIndex The index of the manipulator.
   \param[in, out] activeState The active state of the manipulator. Some elements of the active state may be modified.
   \param[out] placementsInSys Upon return, the placements of all end-effectors in the manipulator in the system coordinates.
   */
   virtual EcBoolean calcAllEndEffectorPlacements
      (
      EcU32 manipIndex,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacementVector& placementsInSys
      ) const;

   /// calculate the placements of all end-effectors in all manipulators
   /**
   \param[in, out] activeState The active state of the manipulator. Some elements of the active state may be modified.
   \param[out] placementsInSys Upon return, the placements of all end-effectors in the manipulator in the system coordinates.
   */
   virtual void calcAllEndEffectorPlacements
      (
      EcManipulatorActiveStateVector&  activeState,
      EcEndEffectorPlacementVectorVector& placementsInSys
      ) const;

   /// read this object from an XML stream
   /**
       \param stream XML reader stream
       \return error flag
   */
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /**
       \param stream XML writer stream
       \return error flag
   */
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /**
       \return uninitialized position control system
   */
   static EcPositionControlSystem nullObject
      (
      );

   /// return a token
   /**
       \return token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   /**
       \return token that describes the XML object
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
       \return XML object created during XML loading
   */
   static EcXmlObject* creator
      (
      );

   /// check for the dimensional integrity of components
   /**
       \return error flag
   */
   virtual EcBoolean integrityCheck
      (
      ) const;

   /// get the result of collision for display
   virtual const EcPropagationResultDataVector& propagationResultDataVector
      (
      ) const;

   /// get the output fitlers. The output filter process the state computed by the velocity control system
   /// just before it is returned by calculateState method.
   virtual const EcPositionControlOutputFilterVector& outputFitlers
      (
      ) const;

   /// set the output filters
   virtual void setOutputFilters
      (
      const EcPositionControlOutputFilterVector& value
      );

   /// get the last state returned from the most recent call to calculateState() method.
   virtual const EcManipulatorSystemState& lastCalculatedState
      (
      ) const;

   /// set the collision stopping threshold
   virtual void setCollisionStoppingThreshold
	   (
	   const EcReal value
	   );

   /// get the collision stopping threshold
   virtual const EcReal collisionStoppingThreshold
      (
      )const;

   /// get the initial state
   virtual const EcManipulatorSystemState& initialState
      (
      ) const;

   /// set the initial state
   virtual void setInitialState
      (
      const EcManipulatorSystemState& state
      );

   /// get the index of the active control method
   virtual EcU32 activeControlMethodIndex
      (
      EcU32 manipIndex
      ) const;

   /// set the active control method
   virtual EcBoolean setActiveControlMethod
      (
      EcU32 manipIndex,
      EcU32 methodIndex
      );

   /// gets the flag indicating whether to ignore the position control time step
   virtual EcBoolean ignoreTimeStep
      (
      ) const;

   /// sets the flag indicating whether to ignore the position control time step. By default, this is false.
   /// Set it to true if calculateState is being called externally at a sufficiently fast cycle rate.
   virtual void setIgnoreTimeStep
      (
      EcBoolean value
      );

   /// sets the speed factor of the controller for the manipulator specified by manipIndex.
   /// Returns false if manipIndex is invalid or true otherwise.
   virtual EcBoolean setSpeedFactor
      (
      EcU32 manipIndex,
      EcReal speedFactor
      );

   /// sets some end-effectors to follow profiled trajectory for the manipulator specified by manipIndex.
   /// If indices is not empty, it will temporarily turn on ignore time step so that profiled trajetory following works correctly.
   /// Returns false if manipIndex is invalid or true otherwise.
   /// See EcPositionController::setProfiledPositionEndEffectors for details.
   virtual EcBoolean setProfiledPositionEndEffectors
      (
      EcU32 manipIndex,
      const EcU32Vector& indices
      );

   /// set the tool offset for a given tool index for a given manipulator.
   /// Returns false if manipIndex or toolIndex is invalid or true otherwise.
   virtual EcBoolean setToolOffset
      (
      EcU32 manipIndex,
      EcU32 toolIndex,
      const EcCoordinateSystemTransformation& value
      );

   /// get the priority list used for anti-collision
   virtual const EcAntiCollisionPriorityList& collisionPriorityList
      (
      ) const;

   /// set the priority list used for anti-collision
   virtual void setCollisionPriorityList
      (
      const EcAntiCollisionPriorityList& value
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

   /// set anti-collision on/off
   virtual EcBoolean setIsAntiCollisionOn
      (
      EcU32 manipIndex,
      EcBoolean on
      );

   /// sets the control mode of a manipulator by index
   /**
   \param[in] manipIndex The index of the manipulator to which the control mode will be set.
   \param[in] mode The control mode to be set.
   \return True if successful or false if manipulatorIndex is out of range.
   \sa EcPositionController::setControlMode
   */
   virtual EcBoolean setControlMode
      (
      EcU32 manipIndex,
      EcU32 mode
      );

protected:

   /// connects member variables
   virtual void connectComponents
      (
      );

   /// initialize XML components for reading and writing system states and desired end-effector states
   virtual EcBoolean initializeStates
      (
      );

   /// move forward in time by one timeStep amount
   virtual void moveForwardOneTimeStep
      (
      );

   /// calculate velocity state
   virtual void calculateVelocityState
      (
      );

   /// calculate the new placement vector from the new system state
   virtual void calculateNewPlacements
      (
      );

   /// invalidates the active states and sets new position and velocity values
   /// This should be called whenever the state changes.
   virtual void resetActiveStates
      (
      );

protected:
   /// the position controller vector
   EcPositionControllerVector                   m_vPositionControllers;

   /// the velocity control system
   EcVelocityControlSystem                      m_VelocityControlSystem;

   /// the time step for position control
   EcXmlReal                                    m_TimeStep;

   /// the maximum number of iterations in a cycle
   EcXmlU32                                     m_MaxIterations;

   /// the maximum propagation size in time steps
   EcXmlU32                                     m_MaxFinalPropagationSize;

   /// a flag indicating whether or not the position control system is operating
   EcXmlBoolean                                 m_IsOn;

   /// the collision avoidance mode
   EcXmlEnumU32                                 m_CollisionAvoidanceMode;

   /// the threshold specifying when a material will break down and allow
   /// an object to pass through.  Typically this value is set to 1, meaning
   /// the system will stop at all link collisions.
   EcXmlReal                                    m_CollisionBreakdownThreshold;

   /// the level in the bounding volume hierarchy  to use for collision detection
   EcXmlU32                                     m_BVHPrecision;

   /// Collision stopping threshold.  Distance from a collision where the control system should stop
   /// The default for this is 0
   EcXmlReal                                    m_CollisionStoppingThreshold;

   /// the output fitlers. Process the state computed by the velocity control system just before the
   /// state is returned by calculateState method
   EcPositionControlOutputFilterVector          m_OutputFilters;

   /// Flag indicating whether to ignore the position control time step
   EcXmlBoolean                                 m_IgnoreTimeStep;

   /// the anti-collision priority list (only used in position controllers that support anti-collision)
   EcAntiCollisionPriorityList                  m_PriorityList;

   /// deprecated. Only kept here for backward-compatibility purposes
   EcXmlEnumU32                                 m_VelocityStateReturnMode;

   /// deprecated. Only kept here for backward-compatibility purposes
   EcXmlEnumU32                                 m_ControlMode;

   /// deprecated. Only kept here for backward-compatibility purposes
   EcXmlReal                                    m_DefaultFeedbackAssimilationRate;

   /// deprecated. Only kept here for backward-compatibility purposes
   EcStringStoppingCriterionVectorMap           m_StoppingCriteriaMap;

   /// deprecated. Only kept here for backward-compatibility purposes
   EcXmlBoolean                                 m_UseTwoPasses;

   // nonXML data below
   /// the stated system
   EcStatedSystem*                              m_pStatedSystem;

   /// the system active state
   mutable EcSystemActiveState                  m_SystemActiveState;

   /// the input desired end-effector placements
   EcManipulatorEndEffectorPlacementVector      m_DesiredPlacementVector;

   /// the input desired end-effector velocities
   EcManipulatorEndEffectorVelocityVector       m_DesiredVelocityVector;

   /// the input desired end-effector accelerations
   EcManipulatorEndEffectorAccelerationVector   m_DesiredAccelerationVector;

   /// the desired end-effector velocities calculated for velocity control
   EcManipulatorEndEffectorVelocityVector       m_VelocityControlVelocityVector;

   /// the desired end-effector accelerations calculated for acceleration control
   EcManipulatorEndEffectorAccelerationVector   m_AccelerationControlAccelerationVector;

   /// the initial system state
   EcManipulatorSystemState                     m_InitialSystemState;

   /// the new actual end-effector placement
   EcManipulatorEndEffectorPlacementVector      m_ActualPlacementVector;

   /// a vector of propagation diagnostics
   EcPropagationResultDataVector                m_PropagationResultDataVector;

   /// a utility state
   mutable EcManipulatorSystemState             m_UtilityState1;

   /// a utility state
   mutable EcManipulatorSystemState             m_UtilityState2;

   /// the control state
   mutable EcSupplementalControlState           m_ControlState;

   /// utility velocity state vector
   mutable EcVelocityStateVector                m_UtilityVelStateVector;

   /// temporary value of m_IgnoreTimeStep. It's being turned on/off internally depending on
   EcBoolean                                    m_IgnoreTimeStepTemp;

   /// the null control description for error recovery
   static const EcIndividualVelocityControlDescription   m_theNullControlDescription;

   /// the null end effector set for error recovery
   static const EcEndEffectorSet                m_theNullEndEffectorSet;

   /// the null control expression description for error recovery
   static const EcControlExpressionDescription  m_theNullControlExpressionDescription;

   /// the null manipulator active state for error recovery
   static EcManipulatorActiveState              m_theNullActiveState;
};

#endif // ecPosContSystem_H_
