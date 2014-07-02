#ifndef ecSupplementalControlState_H_
#define ecSupplementalControlState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSupplementalControlState.h
/// @class EcSupplementalControlState
/// @brief Holds the supplemental state of a control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipEndEffectorVel.h"
#include <manipulator/ecManipSysState.h>

/**
\class EcSupplementalControlState

This class holds the supplemental state used in the position control system.
*/
class EC_ACTIN_CONTROL_DECL EcSupplementalControlState
{
public:
   /// default constructor
   EcSupplementalControlState
      (
      );

   /// destructor
   virtual ~EcSupplementalControlState
      (
      );

   /// copy constructor
   EcSupplementalControlState
      (
      const EcSupplementalControlState& orig
      );

   /// assignment operator
   EcSupplementalControlState& operator=
      (
      const EcSupplementalControlState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSupplementalControlState& orig
      ) const;

   /// get the most recent end-effector velocities. These are used to cap the end-effector velocities with acceleration bounds.
   const EcManipulatorEndEffectorVelocityVector& previousEndEffectorVelocities
      (
      ) const;

   /// get the most recent end-effector velocities. Non-const version
   EcManipulatorEndEffectorVelocityVector& previousEndEffectorVelocities
      (
      );

   /// set the most recent end-effector velocities.
   void setPreviousEndEffectorVelocities
      (
      const EcManipulatorEndEffectorVelocityVector&  value
      );

   /// get the most recent actual velocity states. This is obtained by finite-differencing the position states and is not necessary the same as the velocity states normally returned by EcPositionControlSystem::calculateState().
   const EcVelocityStateVector& previousActualVelocityStates
      (
      ) const;

   /// get the most recent actual velocity states. Non-const version
   EcVelocityStateVector& previousActualVelocityStates
      (
      );

   /// set the most recent actual velocity states.
   void setPreviousActualVelocityStates
      (
      const EcVelocityStateVector&  value
      );

   /// get the most recent computed state (time, positions, and velocities). This is typically the state returned by EcPositionControlSystem::calculateState().
   const EcManipulatorSystemState& previousState
      (
      ) const;

   /// get the most recent computed state (time, positions, and velocities). Non-const version
   EcManipulatorSystemState& previousState
      (
      );

   /// set the most recent computed state (time, positions, and velocities). Non-const version
   void setPreviousState
      (
      const EcManipulatorSystemState& value
      );
protected:
   /// stores the most recent end-effector velocities
   EcManipulatorEndEffectorVelocityVector    m_PreviousEndEffectorVelocities;

   /// the most recent actual velocity states
   EcVelocityStateVector                     m_PreviousActualVelocityStates;

   /// the most recent returned state
   EcManipulatorSystemState                  m_PreviousState;
};

#endif // ecSupplementalControlState_H_
