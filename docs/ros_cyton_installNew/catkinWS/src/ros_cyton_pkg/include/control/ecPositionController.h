#ifndef ecPositionController_H_
#define ecPositionController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionController.h
/// @class EcPositionController
/// @brief Holds a description of a position controller for one manipulator
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffectorTool.h"
#include "ecIndVelContDesc.h"
#include "ecManipEndEffectorAcc.h"
#include "ecManipEndEffectorVel.h"
#include "ecPositionControlMethodVector.h"
#include "ecPositionControlOutputFilterVector.h"
#include "ecSupplementalControlState.h"
#include "ecVelocityController.h"
#include <xml/ecXmlCompType.h>

// forward declaration
class EcAntiCollisionPriorityList;

/// Holds a description of a position controller for one manipulator
class EC_ACTIN_CONTROL_DECL EcPositionController : public EcXmlCompoundType
{
public:
   enum {
      POSITIONCONTROLRESULT=0,
      DESIREDVELOCITYBASED=1,
      ZERO=2,
      FINITEDIFFERENCERESULT=3};

   enum {
      POSITION_CONTROL,
      VELOCITY_CONTROL,
      PROFILED_POSITION
   };

   /// default constructor
   EcPositionController
      (
      );

   /// destructor
   virtual ~EcPositionController
      (
      );

   /// copy constructor
   EcPositionController
      (
      const EcPositionController& orig
      );

   /// assignment operator
   EcPositionController& operator=
      (
      const EcPositionController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionController& orig
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

   /// gets the manipulator index for this controller
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// sets the manipulator index for this controller
   virtual void setManipulatorIndex
      (
      EcU32 value
      );

   /// gets the velocity controller
   virtual const EcVelocityController& velocityController
      (
      ) const;

   /// gets the velocity controller -- non-const version
   virtual EcVelocityController& velocityController
      (
      );

   /// sets the velocity controller
   virtual void setVelocityController
      (
      const EcVelocityController& value
      );

   /// gets the vector of position control methods
   virtual const EcPositionControlMethodVector& positionControlMethods
      (
      ) const;

   /// sets the vector of position control methods
   virtual void setPositionControlMethods
      (
      const EcPositionControlMethodVector& value
      );

   /// gets the index of the active position control method
   virtual EcU32 activeControlMethodIndex
      (
      ) const;

   /// sets the index of the active position control method
   virtual EcBoolean setActiveControlMethod
      (
      EcU32 value
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

   /// gets a flag indicating whether or not the position controller is on
   virtual EcBoolean isOn
      (
      ) const;

   /// sets a flag indicating whether or not the position controller is on
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets the velocity state return mode
   virtual EcU32 velocityStateReturnMode
      (
      ) const;

   /// sets the velocity state return mode
   virtual void setVelocityStateReturnMode
      (
      EcU32 velocityStateReturnMode
      );

   /// sets the control mode
   /**
   \param[in] mode The control mode, either POSITION_CONTROL, VELOCITY_CONTROL, or PROFILED_POSITION
   */
   virtual void setControlMode
      (
      EcU32 mode
      );

   /// gets the control mode
   virtual EcU32 controlMode
      (
      ) const;

   /// gets the default feedback assimilation rate
   virtual EcReal defaultFeedbackAssimilationRate
      (
      ) const;

   /// sets the default feedback assimilation rate
   virtual void setDefaultFeedbackAssimilationRate
      (
      EcReal defaultFeedbackAssimilationRate
      );

   /// set the pointer to the stated system
   virtual void setStatedSystem
      (
      EcStatedSystem* value
      );

   /// get the pointer to the stated system
   virtual EcStatedSystem* statedSystem
      (
      ) const;

   /// get the end-effector velocity calculated for velocity control
   virtual const EcManipulatorEndEffectorVelocity& calculatedEndEffectorVelocity
      (
      ) const;

   /// set the end-effector velocity calculated for velocity control
   virtual void setCalculatedEndEffectorVelocity
      (
      const EcManipulatorEndEffectorVelocity& value
      );

   /// set the pointer to the input desired end-effector placement
   virtual void setDesiredEndEffectorPlacement
      (
      EcManipulatorEndEffectorPlacement* value
      );

   /// get the pointer to the input desired end-effector placement
   virtual EcManipulatorEndEffectorPlacement* desiredEndEffectorPlacement
      (
      ) const;

   /// set the pointer to the input desired end-effector velocity
   virtual void setDesiredEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity* value
      );

   /// get the pointer to the input desired end-effector velocity
   virtual EcManipulatorEndEffectorVelocity* desiredEndEffectorVelocity
      (
      ) const;

   /// set the pointer to the actual end-effector placement
   virtual void setActualEndEffectorPlacement
      (
      EcManipulatorEndEffectorPlacement* value
      );

   /// get the pointer to the actual end-effector placement
   virtual EcManipulatorEndEffectorPlacement* actualEndEffectorPlacement
      (
      ) const;

   /// set the pointer to the propagation result data
   virtual void setPropagationResultData
      (
      EcPropagationResultData* value
      );

   /// get the pointer to the propagation result data
   virtual EcPropagationResultData* propagationResultData
      (
      ) const;

   /// set the pointer to the end-effector velocities from previous cycle
   virtual void setPreviousEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity* value
      );

   /// get the pointer to the end-effector velocities from previous cycle
   virtual EcManipulatorEndEffectorVelocity* previousEndEffectorVelocity
      (
      ) const;

   /// set the pointer to the system active state
   virtual void setSystemActiveState
      (
      EcSystemActiveState* value
      );

   /// get the pointer to the system active state
   virtual EcSystemActiveState* systemActiveState
      (
      ) const;

   /// \copydoc EcVelocityController::setEndEffectorRelativeLinkData
   virtual EcBoolean setEndEffectorRelativeLinkData
      (
      const EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// \copydoc EcVelocityController::endEffectorRelativeLinkData
   virtual const EcEndEffectorRelativeLinkData& endEffectorRelativeLinkData
      (
      const EcU32 endEffectorIndex
      ) const;


   /// \copydoc EcVelocityController::controlExpressionDescription
   virtual const EcControlExpressionDescription& controlExpressionDescription
      (
      ) const;

   /// \copydoc EcVelocityController::setControlExpressionDescription
   virtual void setControlExpressionDescription
      (
      const EcControlExpressionDescription& controlExpressionDescription
      );

   /// \copydoc EcVelocityController::endEffectorSet
   virtual const EcEndEffectorSet& endEffectorSet
      (
      ) const;

   /// \copydoc EcVelocityController::setEndEffectorSet
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet
      );

   /// \copydoc EcVelocityController::addDefaultControlDescriptionAndEndEffectorSet
   virtual EcBoolean addDefaultControlDescriptionAndEndEffectorSet
      (
      const EcIndividualManipulator& manipulator
      );

   /// \copydoc EcVelocityController::controlDescriptions
   virtual const EcControlExpressionDescriptionVector& controlDescriptions
      (
      ) const;

   /// \copydoc EcVelocityController::setControlDescriptions
   virtual EcBoolean setControlDescriptions
      (
      const EcControlExpressionDescriptionVector& controlDescriptions
      );

   /// \copydoc EcVelocityController::setActiveControlDescription
   virtual EcBoolean setActiveControlDescription
      (
      EcU32 index
      );

   /// \copydoc EcVelocityController::activeControlDescriptionIndex
   virtual EcU32 activeControlDescriptionIndex
      (
      ) const;

   /// \copydoc EcVelocityController::endEffectorSets
   virtual const EcEndEffectorSetVector& endEffectorSets
      (
      ) const;

   /// \copydoc EcVelocityController::setEndEffectorSets
   virtual EcBoolean setEndEffectorSets
      (
      const EcEndEffectorSetVector &eeSets
      );

   /// \copydoc EcVelocityController::setActiveEndEffectorSet
   virtual EcBoolean setActiveEndEffectorSet
      (
      EcU32 index
      );

   /// \copydoc EcVelocityController::activeEndEffectorSetIndex
   virtual EcU32 activeEndEffectorSetIndex
      (
      ) const;

   /// \copydoc EcVelocityController::dataMapPointer
   const EcDataMap* dataMapPointer
      (
      ) const;

   /// \copydoc EcVelocityController::setDataMapPointer
   virtual void setDataMapPointer
      (
      const EcDataMap* pDataMap
      );

   /// gets the stopping criteria
   virtual const EcStoppingCriterionVector& stoppingCriteria
      (
      ) const;

   /// sets the stopping criteria
   virtual void setStoppingCriteria
      (
      const EcStoppingCriterionVector& value
      );

   /// gets the threshold for joint velocities. If the magnitude of a joint velocity is
   /// less than this threshold, the joint is considered not moving
   virtual EcReal jointMotionThreshold
      (
      ) const;

   /// sets the joint motion threshold
   virtual void setJointMotionThreshold
      (
      EcReal value
      );

   /// get the end-effector tool
   virtual const EcEndEffectorTool& endEffectorTool
      (
      ) const;

   /// \copydoc EcXmlCompoundType::read()
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// \copydoc EcXmlCompoundType::write()
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// \copydoc EcXmlCompoundType::token()
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

   /// connects member variables
   virtual void connectComponents
      (
      );

   /// configure the end-effector tool
   virtual void configureEndEffectorTool
      (
      );

   /// save the primary determinant and null space for multipassFilter
   virtual void saveDeterminantAndNullSpace
      (
      ) const;

   /// set the state to the filtered value.  This averages the state
   /// velocities or sets the velocities to zero if a singularity was
   /// crossed.
   virtual void multipassFilter
      (
      const EcVelocityState& passOneState,
      const EcVelocityState& passTwoState,
      EcVelocityState&  outputState
      ) const;

   /// calculate a general motion set that will make a tradeoff
   /// between driving the end effectors from the first set of
   /// locations to the second while achieving the desired
   /// general motion.
   virtual EcBoolean calculateGeneralMotion
      (
      );

   /// calculate velocity state
   virtual void calculateVelocityState
      (
      );

   /// calculate the new placement from the new state
   virtual void calculateNewPlacements
      (
      );

   /// calculate the placement from a given position state
   virtual void calculatePlacements
      (
      const EcPositionState& posState
      );

   /// calculate the new end-effector velocities from the new state
   virtual void calculateNewVelocities
      (
      );

   /// check stopping criteria
   virtual void checkStoppingCriteria
      (
      const EcStatedSystem& statedSystem,
      EcPropagationResultData& propagationResultsData
      ) const;

   /// reset and stop manipulator
   /**
   \param statedSystem stated system to stop during collision
   \param propagationResultData joint limit and collision flags
   \param initialState state date (for getting joint positions)
   */
   virtual void resetAndStopManipulator
      (
      EcStatedSystem& statedSystem,
      const EcPropagationResultData& propagationResultData,
      const EcManipulatorSystemState& initialState
      );

   /// gets the active state
   virtual EcManipulatorActiveState& activeState
      (
      ) const;

   /// invalidates the active states and sets new position and velocity values
   /// This should be called whenever the state changes.
   virtual void resetActiveState
      (
      );

   /// calculate velocity state without the component for position control
   virtual void calculateVelocityStateNoPositionControl
      (
      EcVelocityState& velocityState
      );

   /// calculate the velocity state using finite differencing
   virtual void calculateFiniteDifferenceVelocityState
      (
      const EcPositionState& lastState,
      const EcPositionState& newState,
      EcReal deltaTime,
      EcVelocityState& velocityState
      );

   /// set the velocity state based on the velocity state return mode
   virtual void setVelocityState
      (
      const EcManipulatorSystemState& lastState,
      EcManipulatorSystemState& newState
      );

   /// perform necessary operations specific to the active control method. This method is called
   /// at the start of calculateState
   virtual void preCalculateStateCondition
      (
      );

   /// perform necessary operations specific to the active control method. This method is called
   /// at the end of calculateState
   virtual void postCalculateStateCondition
      (
      );

   /// feed back the externally sensed state to the position controller
   virtual void setSensedState
      (
      const EcPositionState& posState,
      EcReal timeStep,
      EcBoolean baseOnly = EcFalse
      );

   /// set the joint-control EE set as active internally
   virtual void setInternalJointControl
      (
      EcBoolean on
      );

   /// gets the joint control end-effector set
   virtual const EcEndEffectorSet& jointControlEndEffectorSet
      (
      ) const;

   /// return whether the controller is converging towards the desired end-effector placement
   virtual EcBoolean isConverging
      (
      ) const;

   /// reset convergence test
   virtual void resetConvergenceTest
      (
      ) const;

   /// return whether the manipulator under control is moving
   virtual EcBoolean isMoving
      (
      ) const;

   /// sets some end-effectors to follow profiled trajectory. If indices is not empty, the control mode
   /// will automatically be set to PROFILED_POSITION and the speed factors of the end-effectors specified
   /// by indices will be changed to 0 (no limit). If indices is empty, the control mode will be
   /// set back to POSITION_CONTROL and the speed factors of all end-effectors will be set to 1.
   virtual void setProfiledPositionEndEffectors
      (
      const EcU32Vector& indices
      );

   /// get the end-effector placement of the end-effectors in the EE set for a given index.
   virtual const EcManipulatorEndEffectorPlacement& actualEndEffectorPlacement
      (
      EcU32 eeSetIndex
      ) const;

   /// set pointer to the priority list
   virtual void setPriorityListPointer
      (
      const EcAntiCollisionPriorityList* pList
      );

   /// get flag indicating whether anti-collision is on
   virtual EcBoolean isAntiCollisionOn
      (
      ) const;

   /// set flag indicating whether anti-collision is on
   virtual void setIsAntiCollisionOn
      (
      EcBoolean value
      );

protected:

   /// filter the joint rates based on two passes
   /**
   \param passOneState state from first pass
   \param passTwoState state from second pass
   \param determinant1 determinant from first state
   \param determinant2 determinant from second state
   \param outputState new state (average of two states or zero if singularity hit)
   */
   virtual void multipassFilter
      (
      const EcVelocityState& passOneState,
      const EcVelocityState& passTwoState,
      EcReal determinant1,
      EcReal determinant2,
      EcVelocityState&  outputState
      ) const;

   /// a utility to support NULL space matching
   /**
   \param determinant2 second determinant
   \param nullSpace1 first null space array
   \param nullSpace2 second null space array
   */
   virtual void processDeterminant
      (
      EcReal& determinant2,
      const EcReArray& nullSpace1,
      const EcReArray& nullSpace2
      ) const;

protected:
   /// the velocity controller
   EcVelocityController                         m_VelocityController;

   /// the vector of position control methods
   EcPositionControlMethodVector                m_vControlMethods;

   /// the index of the active control method
   EcXmlU32                                     m_ActiveControlMethodIndex;

   /// the time step for position control
   EcXmlReal                                    m_TimeStep;

   /// a flag indicating whether or not the position control system is operating
   EcXmlBoolean                                 m_IsOn;

   /// the velocity state return mode
   EcXmlEnumU32                                 m_VelocityStateReturnMode;

   /// the control model
   EcXmlEnumU32                                 m_ControlMode;

   /// the default level of sensor feedback assimilation per second
   /// this is only used for foating-base mechanisms
   EcXmlReal                                    m_DefaultFeedbackAssimilationRate;

   /// control-level stopping criteria
   EcStoppingCriterionVector                    m_StoppingCriteria;

   /// the threshold for joint velocities. If the magnitude of a joint velocity is
   /// less than this threshold, the joint is considered not moving
   EcXmlReal                                    m_JointMotionThreshold;

   // nonXML data below
   /// the index of the manipulator for which this controller is
   EcU32                                        m_ManipulatorIndex;

   /// the stated system
   EcStatedSystem*                              m_pStatedSystem;

   /// the desired end-effector velocities calculated for velocity control
   EcManipulatorEndEffectorVelocity             m_VelocityControlVelocity;

   /// the input desired end-effector placements
   EcManipulatorEndEffectorPlacement*           m_pDesiredPlacement;

   /// the input desired end-effector velocities
   EcManipulatorEndEffectorVelocity*            m_pDesiredVelocity;

   /// the new actual end-effector placement
   EcManipulatorEndEffectorPlacement*           m_pActualPlacement;

   /// propagation diagnostics data
   EcPropagationResultData*                     m_pPropagationResultData;

   /// the end-effector velocities from previous cycle
   EcManipulatorEndEffectorVelocity*            m_pPrevEndEffectorVelocity;

   /// the system active state
   EcSystemActiveState*                         m_pSystemActiveState;

   /// a utility end-effector tool
   EcEndEffectorTool                            m_EndEffectorTool;

   /// a variable that is used when calculating joint rates
   /// for no position control contribution
   EcVelocityState                              m_NoPosControlVelocityState;

   /// a variable that is used when calculating joint rates
   /// by finite differencing position control results
   EcVelocityState                              m_FiniteDifferenceVelocityState;

   /// the original EE set index
   EcU32                                        m_OrigEeSetIndex;

   /// flag indicating whether internal joint control is on
   EcBoolean                                    m_InternalJointControl;

   /// utility end-effector placemen
   mutable EcManipulatorEndEffectorPlacement    m_UtilityEndEffectorPlacement;

   /// utility array
   mutable EcReArray                            m_UtilityArray;

   // utility states
   mutable EcVelocityState                      m_UtilityVelState1;  ///< first utility velocity state
   mutable EcVelocityState                      m_UtilityVelState2;  ///< second utility velocity state

   mutable EcReal                               m_Determinant1;      ///< determinant1 used in multi-pass
   mutable EcReArray                            m_NullSpace1;        ///< null-space1 used in multi-pass
};

#endif // ecPositionController_H_
