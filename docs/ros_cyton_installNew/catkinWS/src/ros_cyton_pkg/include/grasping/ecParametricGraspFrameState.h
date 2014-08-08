#ifndef ecParametricGraspFrameState_H_
#define ecParametricGraspFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricGraspFrameState.h
/// @class EcParametricGraspFrameState
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspFrameState.h"
#include "ecGraspFrameStateContainer.h"
#include "ecGraspFrameTransitionEventStateContainer.h"

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcParametricGraspFrameState : public EcGraspFrameState
{
public:
   /// default constructor
   EcParametricGraspFrameState
      (
      );

   /// destructor
   virtual ~EcParametricGraspFrameState
      (
      );

   /// copy constructor
   EcParametricGraspFrameState
      (
      const EcParametricGraspFrameState& orig
      );

   /// assignment operator
   EcParametricGraspFrameState& operator=
      (
      const EcParametricGraspFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricGraspFrameState& orig
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

   /// get the target frame state
   virtual EcGraspFrameStateContainer* targetFrameState
      (
      );

   /// get the target frame state
   virtual const EcGraspFrameStateContainer* targetFrameState
      (
      ) const;

   /// set the target frame state
   virtual void setTargetFrameState
      (
      const EcGraspFrameStateContainer& fstate
      );

   /// get the current index in the parametric values
   virtual EcU32 parametricIndex
      (
      ) const;

   /// set the current index in the parametric values
   virtual void setParametricIndex
      (
      EcU32 index
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
   /// the target frame state
   EcGraspFrameStateContainer                m_TargetFrameState;

   /// the current index in the parametric values
   EcXmlU32                                  m_ParametricIndex;

   /// the transition event to indicate the end of this frame
   EcGraspFrameTransitionEventStateContainer m_TransitionEventStateContainer;
};

#endif // ecParametricGraspFrameState_H_
