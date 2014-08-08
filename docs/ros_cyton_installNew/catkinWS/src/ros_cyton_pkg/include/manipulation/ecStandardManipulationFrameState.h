#ifndef ecStandardManipulationFrameState_H_
#define ecStandardManipulationFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStandardManipulationFrameState.h
/// @class EcStandardManipulationFrameState
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrameState.h"
#include "ecManipulationFrameTransitionEventStateContainer.h"
#include "ecManipulationOffsetStateContainer.h"
#include "ecManipulationStatus.h"
#include <control/ecEndEffectorSet.h>
#include <control/ecManipEndEffectorPlace.h>
#include <forceControl/ecForceControllerVector.h>
#include <foundCommon/ecDataMap.h>

// Forward declarations
class EcManipulationSequenceState;
class EcManipulationUpdateParams;

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcStandardManipulationFrameState : public EcManipulationFrameState
{
public:
   /// default constructor
   EcStandardManipulationFrameState
      (
      );

   /// destructor
   virtual ~EcStandardManipulationFrameState
      (
      );

   /// copy constructor
   EcStandardManipulationFrameState
      (
      const EcStandardManipulationFrameState& orig
      );

   /// assignment operator
   EcStandardManipulationFrameState& operator=
      (
      const EcStandardManipulationFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStandardManipulationFrameState& orig
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
   virtual const EcManipulationOffsetState* offsetState
      (
      EcU32 index
      ) const;

   /// get the offset state
   virtual EcManipulationOffsetState* offsetState
      (
      EcU32 index
      );

   /// get the vector of offset containers for this frame
   virtual const EcManipulationOffsetStateContainerVector& offsetStateContainerVector
      (
      ) const;

   /// set the vector of offset containers for this frame
   virtual void setOffsetStateContainerVector
      (
      const EcManipulationOffsetStateContainerVector& stateContainerVector
      );

   /// get the transition event
   virtual EcManipulationFrameTransitionEventState* transitionEventState
      (
      );

   /// get the transition event container
   virtual const EcManipulationFrameTransitionEventStateContainer& transitionEventStateContainer
      (
      ) const;

   /// set the transition event container
   virtual void setTransitionEventStateContainer
      (
      const EcManipulationFrameTransitionEventStateContainer& stateContainer
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

   /// replace a specified manipulation offset state with a new one
   virtual EcBoolean replaceManipulationOffsetState
      (
      EcU32 offsetIndex,
      const EcManipulationOffsetState& newOffsetState
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
   EcManipulationOffsetStateContainerVector         m_ManipulationOffsetStateContainerVector;

   /// the transition event to indicate the end of this frame
   EcManipulationFrameTransitionEventStateContainer m_TransitionEventStateContainer;

   /// the current end effector placements for this frame
   EcManipulatorEndEffectorPlacement         m_CurrentEndEffectorPlacement;

   /// the goal end effector placements for this frame
   EcManipulatorEndEffectorPlacement         m_GoalEndEffectorPlacement;
};

#endif // ecStandardManipulationFrameState_H_
