#ifndef ecTrapezoidalProfileTool_H_
#define ecTrapezoidalProfileTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecTrapezoidalProfileTool.h
/// @class EcTrapezoidalProfileTool
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

// forward declarations

/// Provides a tool to compute properties of trapezoidal profile
/// Should NOT be derived.
class EC_ACTIN_CONTROL_DECL EcTrapezoidalProfileTool
{
public:
   /// default contructor
   EcTrapezoidalProfileTool
      (
      );

   /**
   \param[in] acceleration The acceleration/deceleration.
   \param[in] maxVelocity  The max velocity. MUST be positve.
   \param[in] initVelocity The initial velocity.
   \param[in] finalVelocity The final velocity.
   */
   EcBoolean setParameters
      (
      EcReal acceleration,
      EcReal maxVelocity,
      EcReal initVelocity=0.0,
      EcReal finalVelocity=0.0
      );

   /// set acceleration. MUST be positive.
   void setAcceleration
      (
      EcReal value
      );

   /// set max velocity. MUST be positive.
   void setMaxVelocity
      (
      EcReal value
      );

   /// set the initial velocity.
   void setInitialVelocity
      (
      EcReal value
      );

   /// set the final velocity.
   void setFinalVelocity
      (
      EcReal value
      );

   /// set the speed factor. MUst be positive
   void setSpeedFactor
      (
      EcReal value
      );

   /// compute the minimum time to complete the trajectory.
   /**
   \param[in] displacement The displacement of the trajectory.
   \param[out] minTime The minimum time to complete the trajectory.
   \return True if the trajectory can be generated given the parameters or false otherwise.
   */
   EcBoolean computeMinimumTime
      (
      EcReal displacement,
      EcReal& minTime
      ) const;

   /// compute the profile velocity to achieve the trajectory given the duration. Could be positive or negative but its magnitude cannot be greater than the max velocity.
   /**
   \param[in] displacement The displacement of the trajectory.
   \param[in] duration The duration of the trajectory.
   \param[out] profVel The profile velocity to complete the trajectory.
   \return True if the trajectory can be generated given the parameters or false otherwise.
   */
   EcBoolean computeProfileVelocity
      (
      EcReal displacement,
      EcReal duration,
      EcReal& profVel
      ) const;

protected:
   EcReal   m_Acceleration;   ///< the acceleration
   EcReal   m_MaxVelocity;    ///< the maximum velocity
   EcReal   m_InitVelocity;   ///< the initial velocity
   EcReal   m_FinalVelocity;  ///< the final velocity
   EcReal   m_SpeedFactor;    ///< the speed factor
   mutable EcReal   m_a;      ///< the calculated acceleration
};

#endif // ecPathGeneration_H_
