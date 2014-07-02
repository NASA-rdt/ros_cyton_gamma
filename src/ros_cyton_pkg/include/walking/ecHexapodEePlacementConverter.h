#ifndef ecHexapodEePlacementConverter_H_
#define ecHexapodEePlacementConverter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecHexapodEePlacementConverter.h
/// @class EcHexapodEndEffectorPlacementConverter
/// @brief End-effector placement converter for hexapod robot
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseEePlacementConverter.h"

#include <geometry/ecPlane.h>

class EcIndividualManipulator;
class EcManipulatorEndEffectorPlacement;

/**
\class EcHexapodEndEffectorPlacementConverter
\brief A converter used to provide walking capability to a hexapod robot.

This is a simple walking algoritm for a hexapod based on tripod gait.
*/
class EC_ACTIN_WALKING_DECL EcHexapodEndEffectorPlacementConverter : public EcBaseEndEffectorPlacementConverter
{
public:
   /// default constructor
   EcHexapodEndEffectorPlacementConverter
      (
      );

   /// destructor
   virtual ~EcHexapodEndEffectorPlacementConverter
      (
      );

   /// copy constructor
   EcHexapodEndEffectorPlacementConverter
      (
      const EcHexapodEndEffectorPlacementConverter& orig
      );

   /// assignment operator
   EcHexapodEndEffectorPlacementConverter& operator=
      (
      const EcHexapodEndEffectorPlacementConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcHexapodEndEffectorPlacementConverter& orig
      ) const;

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

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// gets the estimated maximum speed of the robot
   virtual EcReal maximumSpeed
      (
      ) const;

   /// sets the estimated maximum speed of the robot. Must be positive.
   virtual void setMaximumSpeed
      (
      EcReal value
      );

   /// gets the size of each foot step
   virtual EcReal footstepSize
      (
      ) const;

   /// sets the size of each foot step. Must be positive.
   virtual void setFootstepSize
      (
      EcReal value
      );

   /// gets the walking plane
   virtual const EcPlane& walkingPlane
      (
      ) const;

   /// sets the walking plane
   virtual void setWalkingPlane
      (
      const EcPlane& value
      );

   /// converts end-effector placement. This converts the desired EE placement of the EE set defined in this converter to the desired EE placement of the EE set defined in and expected from the control system.
   /**
   \param[in] time
   \param[in] manip
   \param[in, out] posControl The active control description could be changed depending on whether the robot needs to walk.
   \param[in] activeState
   \param[in] eePlacementIn
   \param[out] eePlacementOut
   */
   virtual EcBoolean convertEndEffectorPlacement
      (
      EcReal time,
      const EcIndividualManipulator& manip,
      EcPositionControlSystem& posControl,
      EcManipulatorActiveState&  activeState,
      const EcManipulatorEndEffectorPlacement& eePlacementIn,
      EcManipulatorEndEffectorPlacement& eePlacementOut
      );

   /// converts end-effector velocity. This converts the desired EE velocity of the EE set defined in this converter to the desired EE velocity of the EE set defined in and expected from the control system.
   /**
   \param[in] time
   \param[in] manip
   \param[in] posControl
   \param[in] activeState
   \param[in] eeVelocityIn
   \param[out] eeVelocityOut
   */
   virtual EcBoolean convertEndEffectorVelocity
      (
      EcReal time,
      const EcIndividualManipulator& manip,
      const EcPositionControlSystem& posControl,
      EcManipulatorActiveState&  activeState,
      const EcManipulatorEndEffectorVelocity& eeVelocityIn,
      EcManipulatorEndEffectorVelocity& eeVelocityOut
      );

   /// get a null object
   static EcHexapodEndEffectorPlacementConverter nullObject
      (
      );

   /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );
protected:
   /// resize the end-effector placements
   virtual EcBoolean resizeEndEffectorPlacements
      (
      const EcEndEffectorSet& endEffectorSet,
      EcManipulatorEndEffectorPlacement& eePlacementOut
      ) const;

   /// computes the current foot locations
   virtual void computeFootLocations
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState& activeState
      );

   /// returns whether or not the cycle is completed
   virtual EcBoolean isCycleCompleted
      (
      ) const;

   /// continues the cycle
   virtual EcBoolean continueCycle
      (
      EcManipulatorEndEffectorPlacement& eePlacementOut
      );

   /// returns whether or not the robot need to take steps towards the goal
   virtual EcBoolean needToWalk
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      const EcManipulatorEndEffectorPlacement& eePlacementIn
      );

   /// plan the footstep locations for the next cycle
   virtual EcBoolean planFootstepLocations
      (
      );

   /// compute the tripod trajectories for the next cycle
   virtual EcBoolean computeTripodTrajectories
      (
      );

   /// convert the end-effectors that are attached to the body or base
   virtual EcBoolean convertBodyEndEffectors
      (
      const EcVector& step,
      const EcIndividualManipulator& manip,
      const EcEndEffectorSet& endEffectorSet,
      EcManipulatorActiveState&  activeState,
      EcManipulatorEndEffectorPlacement& eePlacementOut
      );

protected:
   /// the estimated maximum speed of the hexapod robot
   EcXmlReal            m_MaximumSpeed;

   /// the maximum footstep size
   EcXmlReal            m_FootstepSize;

   /// the plane on which the robot is walking
   EcPlane              m_WalkingPlane;

   // non-XML data
   /// the current locations of the input EEs
   EcEndEffectorPlacementVector        m_CurrentInputEeLocations;

   /// the current locations of the feet
   EcEndEffectorPlacementVector        m_CurrentFootLocations;

   /// the planned locations of the feet
   EcEndEffectorPlacementVector        m_PlannedFootLocations;

   /// the time period for a footstep
   EcReal               m_FootstepPeriod;

   /// a flag indicating whether or not tripod1 is completed
   EcBoolean            m_IsTripod1Completed;

   /// a flag indicating whether or not tripod2 is completed
   EcBoolean            m_IsTripod2Completed;

   /// the trajectories
   std::vector<EcTrajectoryType>       m_TripodTrajectories;

   /// the maximum translation
   EcVector             m_MaxTranslation;

   /// the maximum projected translation
   EcVector             m_MaxProjTranslation;

   /// the number of feet = 6
   static const EcU32          m_theNumberOfFeet;
};

#endif // ecHexapodEePlacementConverter_H_
