#ifndef ecSimulationGraspingControlInterface_H_
#define ecSimulationGraspingControlInterface_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationGraspingControlInterface.h
/// @class EcSimulationGraspingControlInterface
/// @brief Control interface used inside EcPerformGraspFunctor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecSysSimulation.h"
#include <grasping/ecGraspDescriptor.h>
#include <grasping/ecGraspingControlInterface.h>

/// Control interface used inside EcPerformGraspFunctor
class EC_ACTIN_SIMULATION_DECL EcSimulationGraspingControlInterface : public EcGraspingControlInterface
{
public:
   /// default  constructor
   EcSimulationGraspingControlInterface
      (
      );

   /// get the simulation time step
   virtual EcReal timeStep
      (
      ) const;

   /// set the simulation time step
   virtual void setTimeStep
      (
      EcReal timeStep
      );

   /// get the simulation
   virtual const EcSystemSimulation& simulation
      (
      ) const;

   /// set the simulation
   virtual void setSimulation
      (
      const EcSystemSimulation& simulation
      );

   /// get the index of the object to be grasped in objectStatedSystem
   virtual EcU32 objectIndex
      (
      ) const;

   /// set the index of the object to be grasped in objectStatedSystem
   virtual void setObjectIndex
      (
      EcU32 index
      );

   /// get the index of the grasping manipulator in manipStatedSystem
   virtual EcU32 manipIndex
      (
      ) const;

   /// set the index of the grasping manipulator in manipStatedSystem
   virtual void setManipIndex
      (
      EcU32 index
      );

   /// get the prototype velocity control description used for building a velocity control description vector
   virtual const EcIndividualVelocityControlDescription& prototypeVelocityControlDescription
      (
      ) const;

   /// set the prototype velocity control description used for building a velocity control description vector
   virtual void setPrototypeVelocityControlDescription
      (
      const EcIndividualVelocityControlDescription& prototype
      );

   /// get the prototype force control description used for building a force control description vector
   virtual const EcForceControlDescription& prototypeForceControlDescription
      (
      ) const;

   /// set the prototype force control description used for building a force control description vector
   virtual void setPrototypeForceControlDescription
      (
      const EcForceControlDescription& prototype
      );

   /// get the grasp descriptor used when initializing the grasping module
   virtual const EcGraspDescriptor& graspDescriptor
      (
      ) const;

   /// set the grasp descriptor used when initializing the grasping module
   virtual void setGraspDescriptor
      (
      const EcGraspDescriptor& descriptor
      );

   /// set the hand descriptor of the grasping module to use for the grasp
   virtual void setGraspingModuleHandDescriptor
      (
      const EcString& handDescriptor
      );
protected:
   /// get the grasp initialization parameters
   virtual EcGraspInitParams graspInitParams
      (
      ) const;

   /// get the grasp update parameters
   virtual EcGraspUpdateParams graspUpdateParams
      (
      ) const;

   /// get the grasping module
   virtual EcBaseHandGraspingModule* graspingModule
      (
      );

   /// set the velocity control descriptions required for this grasp
   virtual void setGraspingVelocityControlDescriptionVector
      (
      const EcVelocityControlDescriptionVector& controlDescriptions
      );

   /// set the active control description index
   virtual void setActiveControlDescriptionIndex
      (
      EcU32 index
      );

   /// set the desired placement for position control
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& placement
      );

   /// set the force control descriptions required for this grasp
   virtual void setGraspingForceControlDescriptionVector
      (
      const EcForceControlDescriptionVector& controlDescriptions
      );

   /// set the active force control description index
   virtual void setActiveForceControlDescriptionIndex
      (
      EcU32 index
      );

   /// set the desired forces for force control
   virtual void setDesiredForce
      (
      const EcDesiredManipulatorForce& graspForce
      );

   /// set whether or not force control is on
   virtual void setIsForceControlOn
      (
      EcBoolean flag
      );

   /// update states for the current time
   virtual void updateStates
      (
      EcReal&                   time,
      EcManipulatorSystemState& objectSystemState,
      EcManipulatorSystemState& manipSystemState
      );

   /// simulation delta time
   EcReal                                 m_TimeStep;

   /// grasping simulation
   EcSystemSimulation                     m_Simulation;

   /// index of the object to be grasped
   EcU32                                  m_ObjectIndex;

   /// index of the grasping manipulator
   EcU32                                  m_ManipIndex;

   /// prototype velocity control description
   EcIndividualVelocityControlDescription m_Prototype;

   /// flag indicating if the prototype was explicitly set
   EcBoolean                              m_PrototypeIsExplicit;

   /// prototype force control description
   EcForceControlDescription              m_ForcePrototype;

   /// flag indicating if the force prototype was explicitly set
   EcBoolean                              m_ForcePrototypeIsExplicit;

   /// grasp descriptor used for initializing the grasp
   EcGraspDescriptor                      m_GraspDescriptor;

   /// hand descriptor of the grasping module to use for the grasp
   EcString                               m_GraspingModuleHandDescriptor;

   /// desired force vector cached to prevent dynamic allocations
   EcDesiredManipulatorForceVector        m_DesiredForceVec;

   /// implicit prototype velocity control description
   mutable EcIndividualVelocityControlDescription  m_ImplicitPrototype;
};

#endif // ecSimulationGraspingControlInterface_H_
