#ifndef ecStandardGraspFrameState_H_
#define ecStandardGraspFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStandardGraspFrameState.h
/// @class EcStandardGraspFrameState
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameState.h"
#include "ecGraspFrameTransitionEventStateContainer.h"
#include "ecGraspOffsetStateContainer.h"
#include "ecGraspStatus.h"
#include <control/ecEndEffectorSet.h>
#include <control/ecManipEndEffectorPlace.h>
#include <forceControl/ecForceControllerVector.h>
#include <foundCommon/ecDataMap.h>

// Forward declarations
class EcGraspSequenceState;
class EcGraspUpdateParams;

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcStandardGraspFrameState : public EcGraspFrameState
{
public:
   /// default constructor
   EcStandardGraspFrameState
      (
      );

   /// destructor
   virtual ~EcStandardGraspFrameState
      (
      );

   /// copy constructor
   EcStandardGraspFrameState
      (
      const EcStandardGraspFrameState& orig
      );

   /// assignment operator
   EcStandardGraspFrameState& operator=
      (
      const EcStandardGraspFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStandardGraspFrameState& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get the offset state
   virtual const EcGraspOffsetState* offsetState
      (
      EcU32 index
      ) const;

   /// get the offset state
   virtual EcGraspOffsetState* offsetState
      (
      EcU32 index
      );

   /// get the vector of offset containers for this frame
   virtual const EcGraspOffsetStateContainerVector& offsetStateContainerVector
      (
      ) const;

   /// set the vector of offset containers for this frame
   virtual void setOffsetStateContainerVector
      (
      const EcGraspOffsetStateContainerVector& stateContainerVector
      );

   /// get the transition event
   virtual EcGraspFrameTransitionEventState* transitionEventState
      (
      );

   /// get the transition event container
   virtual const EcGraspFrameTransitionEventStateContainer& transitionEventStateContainer
      (
      ) const;

   /// set the transition event container
   virtual void setTransitionEventStateContainer
      (
      const EcGraspFrameTransitionEventStateContainer& stateContainer
      );

   /// get the current end effector placement
   virtual const EcManipulatorEndEffectorPlacement& currentEndEffectorPlacement
      (
      ) const;

   /// set the current end effector placement
   virtual void setCurrentEndEffectorPlacement
      (
      const EcManipulatorEndEffectorPlacement& placement
      );

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      ) const;

   /// set the goal end effector placement
   virtual void setGoalEndEffectorPlacement
      (
      const EcManipulatorEndEffectorPlacement& placement
      );

   /// replace a specified grasp offset state with a new one
   virtual EcBoolean replaceGraspOffsetState
      (
      EcU32 offsetIndex,
      const EcGraspOffsetState& newOffsetState
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the offsets for this frame
   EcGraspOffsetStateContainerVector         m_GraspOffsetStateContainerVector;

   /// the transition event to indicate the end of this frame
   EcGraspFrameTransitionEventStateContainer m_TransitionEventStateContainer;

   /// the current end effector placements for this frame
   EcManipulatorEndEffectorPlacement         m_CurrentEndEffectorPlacement;

   /// the goal end effector placements for this frame
   EcManipulatorEndEffectorPlacement         m_GoalEndEffectorPlacement;
};

#endif // ecStandardGraspFrameState_H_
