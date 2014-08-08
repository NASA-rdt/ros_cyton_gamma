#ifndef ecArbiAccelerationTool_H_
#define ecArbiAccelerationTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecArbiAccelerationTool.h
/// @class EcArbiAccelerationTool
/// @brief Provides a tool for calculating joint accelerations
///        using articulated rigid-body inertia.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipActiveState.h"
#include "ecManipTorque.h"
#include "ecTotalTorqueTool.h"

// forward declarations
class EcAccelerationState;
class EcIndividualManipulator;
class EcManipulatorTorque;
class EcPositionState;
class EcStatedSystem;
class EcVelocityState;
class EcManipulatorExternalForce;

/** Provides a tool for calculating joint accelerations using articulated
rigid-body inertia.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcArbiAccelerationTool
{
public:
   /// default constructor
   EcArbiAccelerationTool
      (
      );

   /// destructor
   virtual ~EcArbiAccelerationTool
      (
      );

   /// copy constructor
   EcArbiAccelerationTool
      (
      const EcArbiAccelerationTool& orig
      );

   /// assignment operator
   EcArbiAccelerationTool& operator=
      (
      const EcArbiAccelerationTool& orig
      );

   /// calculate accelerations, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.
   /**
    * @param[in] statedSystem The stated system containing the focus manipulator
    * @param[in] manipulator The focus manipulator
    * @param[in] positionState The position state of the manipulator (only used if activeState is not provided)
    * @param[in] velocityState The velocity state of the manipulator (only used if activeState is not provided)
    * @param[in] appliedTorque The control torques
    * @param[in] manipExtForce The external forces on the manipulator
    * @param[out] accelerationState The acceleration (joint and base) of the manipulator
    * @param[in,out] activeState A pointer to an active state, which may be NULL. If not NULL, its
    *             position and velocity states will be used. If NULL, an internal active state will
    *             be used with the provided positionState and velocityState.
    * @return True
    */
   virtual EcBoolean acceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      const EcManipulatorTorque& appliedTorque,
      const EcManipulatorExternalForce& manipExtForce,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState*  activeState=0
      );

   /// calculate accelerations, using (and setting) the
   /// active position state that is provided. Overloaded for convenience.
   /**
    * @param[in] statedSystem The stated system containing the focus manipulator
    * @param[in] manipulator The focus manipulator
    * @param[in] positionState The position state of the manipulator (NOT used)
    * @param[in] velocityState The velocity state of the manipulator (NOT used)
    * @param[in] appliedTorque The control torques
    * @param[in] manipExtForce The external forces on the manipulator
    * @param[out] accelerationState The acceleration (joint and base) of the manipulator
    * @param[in,out] activeState The active state. Its position and velocity states, instead of the
    *           provided positionState and velocityState, are used in the calculation.
    * @return True
    */
   virtual EcBoolean acceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      const EcManipulatorTorque& appliedTorque,
      const EcManipulatorExternalForce& manipExtForce,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState&  activeState
      );

   /// get a null object
   static EcArbiAccelerationTool nullObject
      (
      );

protected:

   /// resize member variables
   virtual void resize
      (
      );

   /// an active state to use when one is not externally provided
   EcManipulatorActiveState          m_ActiveState;

   /// a utility manipulator torque to prevent dynamic memory allocation.
   mutable EcManipulatorTorque       m_UtilityManipulatorTorque;

   /// a joint-torque tool
   EcTotalTorqueTool                 m_TotalTorqueTool;
};

#endif // ecArbiAccelerationTool_H_
