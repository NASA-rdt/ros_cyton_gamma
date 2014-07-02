#ifndef ecGraspingControlInterface_H_
#define ecGraspingControlInterface_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspingControlInterface.h
/// @class EcGraspingControlInterface
/// @brief Control interface used inside EcPerformGraspFunctor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <control/ecIndVelContDesc.h>
#include <forceControl/ecForceControlDescription.h>

// Forward declarations
class EcBaseHandGraspingModule;
class EcGraspInitParams;
class EcGraspUpdateParams;
class EcManipulatorEndEffectorPlacement;
class EcPerformGraspCallbacks;
class EcStatedSystem;

/// Control interface used inside EcPerformGraspFunctor
class EC_ACTIN_GRASPING_DECL EcGraspingControlInterface
{
public:
   /// default  constructor
   EcGraspingControlInterface
      (
      );

   /// destructor
   virtual ~EcGraspingControlInterface
      (
      )
   {
   }

   /// get the prototype velocity control description used for building a velocity control description vector
   virtual const EcIndividualVelocityControlDescription& prototypeVelocityControlDescription
      (
      ) const = 0;

   /// get the prototype force control description used for building a force control description vector
   virtual const EcForceControlDescription& prototypeForceControlDescription
      (
      ) const = 0;

   /// perform the entire grasping loop
   virtual EcBoolean performGrasp
      (
      EcReal& time
      );

   /// set callbacks used for customizing the grasping loop
   virtual void setCallbacks
      (
      EcPerformGraspCallbacks* pCallbacks
      );

protected:
   /// get the grasp initialization parameters
   virtual EcGraspInitParams graspInitParams
      (
      ) const = 0;

   /// get the grasp update parameters
   virtual EcGraspUpdateParams graspUpdateParams
      (
      ) const = 0;

   /// get the grasping module
   virtual EcBaseHandGraspingModule* graspingModule
      (
      ) = 0;

   /// set the velocity control descriptions required for this grasp
   virtual void setGraspingVelocityControlDescriptionVector
      (
      const EcVelocityControlDescriptionVector& controlDescriptions
      ) = 0;

   /// set the active control description index
   virtual void setActiveControlDescriptionIndex
      (
      EcU32 index
      ) = 0;

   /// set the desired placement for position control
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& placement
      ) = 0;

   /// set the force control descriptions required for this grasp
   virtual void setGraspingForceControlDescriptionVector
      (
      const EcForceControlDescriptionVector& controlDescriptions
      ) = 0;

   /// set the active force control description index
   virtual void setActiveForceControlDescriptionIndex
      (
      EcU32 index
      ) = 0;

   /// set the desired forces for force control
   virtual void setDesiredForce
      (
      const EcManipulatorSensorForce& graspForce
      ) = 0;

   /// set whether or not force control is on
   virtual void setIsForceControlOn
      (
      EcBoolean flag
      ) = 0;

   /// update states for the current time
   virtual void updateStates
      (
      EcReal&                   time,
      EcManipulatorSystemState& objectSystemState,
      EcManipulatorSystemState& manipSystemState
      ) = 0;

   /// Callbacks for customizing the performGrasp method
   EcPerformGraspCallbacks* m_pCallbacks;
};

#endif // ecGraspingControlInterface_H_
