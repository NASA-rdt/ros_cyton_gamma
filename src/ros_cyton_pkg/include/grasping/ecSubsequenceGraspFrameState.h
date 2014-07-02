#ifndef ecSubsequenceGraspFrameState_H_
#define ecSubsequenceGraspFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSubsequenceGraspFrameState.h
/// @class EcSubsequenceGraspFrameState
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameState.h"
#include "ecGraspFrameTransitionEventStateContainer.h"
//#include "ecGraspOffsetStateContainer.h"
#include "ecGraspSequenceState.h"
//#include "ecGraspStatus.h"

//#include <control/ecDesiredManipForce.h>
//#include <control/ecEndEffectorSet.h>
//#include <control/ecManipEndEffectorPlace.h>
//#include <control/ecSensorProcessorContainer.h>

// Forward declarations
//class EcGraspUpdateParams;

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcSubsequenceGraspFrameState : public EcGraspFrameState
{
public:
   /// default constructor
   EcSubsequenceGraspFrameState
      (
      );

   /// destructor
   virtual ~EcSubsequenceGraspFrameState
      (
      );

   /// copy constructor
   EcSubsequenceGraspFrameState
      (
      const EcSubsequenceGraspFrameState& orig
      );

   /// assignment operator
   EcSubsequenceGraspFrameState& operator=
      (
      const EcSubsequenceGraspFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSubsequenceGraspFrameState& orig
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

   /// get the grasp sequence
   virtual EcGraspSequenceState* graspSequenceState
      (
      );

   /// get the grasp sequence
   virtual const EcGraspSequenceState* graspSequenceState
      (
      ) const;

   /// set the grasp sequence
   virtual void setGraspSequenceState
      (
      const EcGraspSequenceState& sstate
      );

   /// get the vector of offset containers for this frame
   virtual const EcGraspOffsetStateContainerVector& offsetStateContainerVector
      (
      ) const;

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

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the grasp sequence defining the subsequence of this frame
   EcGraspSequenceState                      m_GraspSequenceState;

   /// the transition event to indicate the end of this frame
   EcGraspFrameTransitionEventStateContainer m_TransitionEventStateContainer;
};

#endif // ecSubsequenceGraspFrameState_H_
