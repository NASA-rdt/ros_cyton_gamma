#ifndef ecParametricManipulationFrameState_H_
#define ecParametricManipulationFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricManipulationFrameState.h
/// @class EcParametricManipulationFrameState
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationFrameState.h"
#include "ecManipulationFrameStateContainer.h"
#include "ecManipulationFrameTransitionEventStateContainer.h"

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcParametricManipulationFrameState : public EcManipulationFrameState
{
public:
   /// default constructor
   EcParametricManipulationFrameState
      (
      );

   /// destructor
   virtual ~EcParametricManipulationFrameState
      (
      );

   /// copy constructor
   EcParametricManipulationFrameState
      (
      const EcParametricManipulationFrameState& orig
      );

   /// assignment operator
   EcParametricManipulationFrameState& operator=
      (
      const EcParametricManipulationFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricManipulationFrameState& orig
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
   virtual EcManipulationFrameStateContainer* targetFrameState
      (
      );

   /// get the target frame state
   virtual const EcManipulationFrameStateContainer* targetFrameState
      (
      ) const;

   /// set the target frame state
   virtual void setTargetFrameState
      (
      const EcManipulationFrameStateContainer& fstate
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
   virtual const EcManipulationOffsetStateContainerVector& offsetStateContainerVector
      (
      ) const;

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
   EcManipulationFrameStateContainer                m_TargetFrameState;

   /// the current index in the parametric values
   EcXmlU32                                  m_ParametricIndex;

   /// the transition event to indicate the end of this frame
   EcManipulationFrameTransitionEventStateContainer m_TransitionEventStateContainer;
};

#endif // ecParametricManipulationFrameState_H_
