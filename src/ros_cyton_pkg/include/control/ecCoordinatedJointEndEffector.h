#ifndef ecCoordinatedJointEndEffector_H_
#define ecCoordinatedJointEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecCoordinatedJointEndEffector.h
/// @class EcCoordinatedJointEndEffector
/// @brief A class for end effector that is used for coordinated joint control.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecScalarMotionFilter.h"
#include "ecTrapezoidalProfileTool.h"

// forward declarations
class EcManipulatorLink;

/// A class for end effector that is used for coordinated joint control. In this control,
/// multiple joints can be controlled at the same time and they would start and finish their motion
/// (in the joint space) at approximately the same time. Their motions are governed by the trapezoidal
/// velocity profile.
class EC_ACTIN_CONTROL_DECL EcCoordinatedJointEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcCoordinatedJointEndEffector
      (
      );

   /// destructor
   virtual ~EcCoordinatedJointEndEffector
      (
      );

   /// copy constructor
   EcCoordinatedJointEndEffector
      (
      const EcCoordinatedJointEndEffector& orig
      );

   /// assignment operator
   EcCoordinatedJointEndEffector& operator=
      (
      const EcCoordinatedJointEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCoordinatedJointEndEffector& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, it returns the number of joints controlled by this end effector,
   /// i.e. the size of linkLabels()
   virtual EcU32 doc
      (
      ) const;

   /// get the values of all editable components
   virtual const EcXmlStringVector& editableValues
      (
      ) const;

   /// set the values of the editable components
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      );

   /// gets the link labels. These are the labels (names) of links (joints) controlled by this end effector.
   virtual const EcXmlStringVector& linkLabels
      (
      ) const;

   /// sets the link labels
   virtual void setLinkLabels
      (
      const EcXmlStringVector& linkLabels
      );

   /// gets the max velocities
   virtual const EcXmlRealVector& maxVelocities
      (
      ) const;

   /// sets the max velocities
   virtual void setMaxVelocities
      (
      const EcXmlRealVector& value
      );

   /// gets the profile accelerations
   virtual const EcXmlRealVector& profileAccelerations
      (
      ) const;

   /// sets the profile accelerations
   virtual void setProfileAccelerations
      (
      const EcXmlRealVector& value
      );

   /// @copydoc EcEndEffector::motionThreshold()
   /// For this end-effector, it's NOT applicable and this method simply returns 0.
   virtual EcReal motionThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setMotionThreshold()
   /// For this end-effector, it's NOT applicable and this method simply does nothing.
   virtual void setMotionThreshold
      (
      EcReal motionThreshold
      );

   /// @copydoc EcEndEffector::accelerationThreshold()
   /// For this end-effector, it's NOT applicable and this method simply returns 0.
   virtual EcReal accelerationThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setAccelerationThreshold()
   /// For this end-effector, it's NOT applicable and this method simply does nothing.
   virtual void setAccelerationThreshold
      (
      EcReal accelerationThreshold
      );

   /// @copydoc EcEndEffector::insertJacobianComponent()
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const;

   /// @copydoc EcEndEffector::insertSparsityComponent()
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// @copydoc EcEndEffector::insertErrorWeightComponent()
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// @copydoc EcEndEffector::calculatePlacement()
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// @copydoc EcEndEffector::calculateVelocity()
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// @copydoc EcEndEffector::calculateAcceleration()
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
      ) const;

   /// @copydoc EcEndEffector::filterEndEffectorVelocity()
   virtual void filterEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& guide,
      const EcXmlRealVector& inputVelocity,
      const EcXmlRealVector& lastVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcXmlRealVector& filteredVelocity
      ) const;

   /// filter an input end-effector velocity by applying velocity
   /// and acceleration thresholds
   /// @param[in] inputVelocity The desired end effector velocity
   /// @param[in] lastVelocity The current end effector velocity (normally computed from previous step)
   /// @param[in] timeStep The time step
   /// @param[out] filteredVelocity The calculated end effector velocity
   virtual void filterEndEffectorVelocity
      (
      const EcXmlRealVector& inputVelocity,
      const EcXmlRealVector& lastVelocity,
      EcReal timeStep,
      EcXmlRealVector& filteredVelocity
      ) const;

   /// @copydoc EcEndEffector::minimumTime()
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::difference()
   virtual EcReal difference
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::speedFactor()
   virtual EcReal speedFactor
      (
      ) const;

   /// @copydoc EcEndEffector::setSpeedFactor()
   virtual void setSpeedFactor
      (
      EcReal value
      );

   /// @copydoc EcEndEffector::filteringActive()
   virtual EcBoolean filteringActive
      (
      ) const;

   /// @copydoc EcEndEffector::setFilteringActive()
   virtual void setFilteringActive
      (
      EcBoolean value
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// builds and return a default coordinated joint control EE for a given manipulator using the joint rate
   /// limits of the joints in the manipulator and set the profiled accelerations as twice the rate limits.
   /// @param[in] manipulator The manipulator for which to build a default coordinated joint control EE.
   /// @param[in] speedScaleFactor The scale used to adjust the max speed of each joint relative to its rate limit.
   static EcCoordinatedJointEndEffector defaultJointControlEndEffector
      (
      const EcIndividualManipulator& manipulator,
      EcReal speedScaleFactor = 1.0
      );
protected:
   /// initialize
   virtual void initialize
      (
      const EcIndividualManipulator& manip
      ) const;

   /// reset
   virtual void reset
      (
      ) const;

   /// re-order and right-size the joint positions to match up with the joints in the end-effector
   void reorderJointPositions
      (
      const EcXmlRealVector& original,
      EcXmlRealVector& reordered
      ) const;

   // XML data
   /// the default max velocity
   EcXmlReal         m_DefaultMaxVelocity;
   /// the default profile acceleration
   EcXmlReal         m_DefaultProfileAcceleration;
   /// the labels of joints (links) in the coordinated control
   EcXmlStringVector m_LinkLabels;
   /// max velocities
   EcXmlRealVector   m_MaxVelocities;
   /// profile accelerations
   EcXmlRealVector   m_ProfileAccelerations;
   /// the error weight for this end effector
   EcXmlReal         m_ErrorWeight;

   // non-XML below
   /// an array for holding shortcut indices for the links
   mutable EcU32Vector        m_LinkIndices;

   /// vector of scalar motion filters used to filter joint motion
   mutable std::vector< EcScalarMotionFilter >     m_MotionFilters;

   /// vector of trapezoidal profile tools used to compute joint motion profiles
   mutable std::vector< EcTrapezoidalProfileTool > m_ProfileTools;
   mutable EcXmlRealVector    m_PrevGoalJointPositions;     ///< previous goal joint positions
   mutable EcXmlRealVector    m_GoalJointPositions;         ///< current goal joint positions
};

#endif // ecCoordinatedJointEndEffector_H_
