#ifndef ecTotalTorqueTool_H_
#define ecTotalTorqueTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecTotalTorqueTool.h
/// @class EcTotalTorqueTool
/// @brief Provides a tool for torque/force calculation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipActiveState.h"
#include "ecManipTorque.h"

// forward declarations
class EcIndividualManipulator;
class EcManipulatorExternalForce;
class EcStatedSystemStruct;

/** Provides a tool for torque/force calculation.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcTotalTorqueTool
{
public:
   /// enumeration for supported types of computed torques
   typedef enum
   {
      TOTAL_TORQUE,       ///< Torque from manipulator dynamics + actuator dynamics
      TOTAL_LINEAR_TORQUE,   ///< Torque from manipulator dynamics + linear actuator dynamics (e.g. no dry friction, no backlash)
      MANIPULATOR_TORQUE  ///< Torque from manipulator dynamics only
   } EcTotalTorqueType;

   /// default constructor
   EcTotalTorqueTool
      (
      );

   /// destructor
   virtual ~EcTotalTorqueTool
      (
      );

   /// copy constructor
   EcTotalTorqueTool
      (
      const EcTotalTorqueTool& orig
      );

   /// assignment operator
   EcTotalTorqueTool& operator=
      (
      const EcTotalTorqueTool& orig
      );

   /// get manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// set manipulator
   virtual void setManipulator
      (
      const EcIndividualManipulator* manipulator
      );

   /// set the base acceleration using the gravity vector in represented
   /// in system coordinates.  This is only used when the
   /// internal active state is used.
   virtual void setBaseAccelerationFromGravityVector
      (
      const EcVector& gravityVector
      );

   /// set the position state.  This is only used if no external active
   /// state is provided when calculating the torques
   virtual void setPositionState
      (
      const EcPositionState& positionState
      );

   /// set the velocity state.  This is only used if no external active
   /// state is provided when calculating the torques
   virtual void setVelocityState
      (
      const EcVelocityState& velocityState
      );

   /// set the acceleration state.  This is only used if no external active
   /// state is provided when calculating the torques
   virtual void setAccelerationState
      (
      const EcAccelerationState& accelerationState
      );

   /// returns the current total torque type
   virtual const EcTotalTorqueType& totalTorqueType
      (
      );

   /// sets the total torque type
   virtual void setTotalTorqueType
      (
      const EcTotalTorqueType& type
      );

   /// calculate torques/forces and base force/moment, using (and setting)
   /// the active state that is provided.  If the pointer is null
   /// null, an internal active state is used.
   virtual const EcManipulatorTorque& torques
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate torques/forces and base force/moment, using (and setting)
   /// the active state that is provided.  The
   /// torques/forces are the values required to counter gravity
   /// and achieve the motion specified through the active state.
   virtual const EcManipulatorTorque& torques
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// Assuming floating base with no applied force/moment on the base,
   /// calculate torques/forces and base force/moment, using (and setting)
   /// the active state that is provided.  If the pointer is null
   /// null, an internal active state is used.
   virtual const EcManipulatorTorque& torquesNoBaseForce
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// Assuming floating base with no applied force/moment on the base,
   /// calculate torques/forces and base force/moment, using (and setting)
   /// the active state that is provided.  The joint
   /// torques/forces are the values required to counter gravity
   /// and achieve the joint accelerations specified through the active
   /// state with an arbitrary base acceleration.
   virtual const EcManipulatorTorque& torquesNoBaseForce
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate torques/force on a single joint, using (and setting)
   /// the active state that is provided.  If the pointer is
   /// null, an internal active state is used.
   virtual EcReal torque
      (
      EcU32 joint,
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate torques/force on a single joint, using (and setting)
   /// the active state that is provided.  The
   /// torques/forces are the values required to counter gravity
   /// and achieve the motion specified through the active state.
   virtual EcReal torque
      (
      EcU32 joint,
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate the force on the base, using (and setting)
   /// the active state that is provided.  If the pointer is
   /// null, an internal active state is used.
   virtual const EcGeneralForce& generalForce
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate the force on the base, using (and setting)
   /// the active state that is provided.  The
   /// torques/forces are the values required to counter gravity
   /// and achieve the motion specified through the active state.
   virtual const EcGeneralForce& generalForce
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// get a null object
   static EcTotalTorqueTool nullObject
      (
      );

protected:

   /// resize member variables
   virtual void resize
      (
      );

   /// a constant pointer to the manipulator
   const EcIndividualManipulator*    m_pManipulator;

   /// an active state that is used if none is provided
   EcManipulatorActiveState          m_ActiveState;

   /// the manipulator torque that is calculated
   EcManipulatorTorque               m_ManipulatorTorque;

   /// a flag indicating which type of torque to be computed
   EcTotalTorqueType                 m_TotalTorqueType;

   /// a utility torque for multipass calculations
   EcManipulatorTorque               m_FirstPassManipulatorTorque;

   /// a utility array representing force
   EcReArray                         m_UtilityForceArray;

   /// a utility array representing acceleration
   EcReArray                         m_UtilityAccelerationArray;

   /// a utility acceleration state
   EcAccelerationState               m_UtilityAccelerationState;
};

#endif // ecTotalTorqueTool_H_
