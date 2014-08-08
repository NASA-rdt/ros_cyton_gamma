#ifndef ecPerformGraspCallbacks_H_
#define ecPerformGraspCallbacks_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPerformGraspCallbacks.h
/// @class EcPerformGraspCallbacks
/// @brief Callbacks used to customize EcPerformGraspFunctor
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <foundCore/ecTypes.h>
#include "ecGraspStatus.h"

// Forward declarations
class EcManipulatorSystemState;

/// Control interface used inside EcPerformGraspFunctor
class EC_ACTIN_GRASPING_DECL EcPerformGraspCallbacks
{
public:
   /// destructor
   virtual ~EcPerformGraspCallbacks
      (
      )
   {
   }

   /// callback called when the grasp is complete
   virtual void graspComplete
      (
      EcBoolean success
      )
   {
   }

   /// callback called when grasping initialization fails
   virtual void initializationFailed
      (
      )
   {
   }

   /// callback called at the beginning of the grasping loop
   virtual void loopStart
      (
      EcReal time
      )
   {
   }

   /// callback called following state updates
   virtual void updateStates
      (
      const EcManipulatorSystemState& objectSystemState,
      const EcManipulatorSystemState& manipSystemState,
      EcGraspStatus::Enum status
      )
   {
   }
};

#endif // ecPerformGraspCallbacks_H_
