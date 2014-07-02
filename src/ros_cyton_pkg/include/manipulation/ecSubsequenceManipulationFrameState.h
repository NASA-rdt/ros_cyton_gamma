#ifndef ecSubsequenceManipulationFrameState_H_
#define ecSubsequenceManipulationFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSubsequenceManipulationFrameState.h
/// @class EcSubsequenceManipulationFrameState
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationActionStateContainer.h"
#include "ecManipulationFrameState.h"
#include "ecManipulationFrameTransitionEventStateContainer.h"

// Forward declarations
//class EcManipulationUpdateParams;

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcSubsequenceManipulationFrameState : public EcManipulationFrameState
{
public:
   /// default constructor
   EcSubsequenceManipulationFrameState
      (
      );

   /// destructor
   virtual ~EcSubsequenceManipulationFrameState
      (
      );

   /// copy constructor
   EcSubsequenceManipulationFrameState
      (
      const EcSubsequenceManipulationFrameState& orig
      );

   /// assignment operator
   EcSubsequenceManipulationFrameState& operator=
      (
      const EcSubsequenceManipulationFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSubsequenceManipulationFrameState& orig
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

   /// get the subsequence state
   virtual EcManipulationActionState* subsequenceState
      (
      );

   /// get the subsequence state
   virtual const EcManipulationActionState* subsequenceState
      (
      ) const;

   /// get the subsequence state container
   virtual EcManipulationActionStateContainer& subsequenceStateContainer
      (
      );

   /// get the subsequence state container
   virtual const EcManipulationActionStateContainer& subsequenceStateContainer
      (
      ) const;

   /// set the subsequence state container
   virtual void setSubsequenceStateContainer
      (
      const EcManipulationActionStateContainer& astateContainer
      );

   /// get the vector of offset state containers for this frame
   virtual const EcManipulationOffsetStateContainerVector& offsetStateContainerVector
      (
      ) const;

   /// get the transition event state
   virtual EcManipulationFrameTransitionEventState* transitionEventState
      (
      );

   /// get the transition event state container
   virtual const EcManipulationFrameTransitionEventStateContainer& transitionEventStateContainer
      (
      ) const;

   /// set the transition event state container
   virtual void setTransitionEventStateContainer
      (
      const EcManipulationFrameTransitionEventStateContainer& stateContainer
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
   /// the manipulation sequence defining the subsequence of this frame
   EcManipulationActionStateContainer               m_SubsequenceStateContainer;

   /// the transition event to indicate the end of this frame
   EcManipulationFrameTransitionEventStateContainer m_TransitionEventStateContainer;
};

#endif // ecSubsequenceManipulationFrameState_H_
