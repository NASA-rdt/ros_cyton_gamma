#ifndef ecGraspSequenceState_H_
#define ecGraspSequenceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspSequenceState.h
/// @class EcGraspSequenceState
/// @brief A grasp sequence.
///        This represents a sequence of grasp frames.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameStateContainer.h"

#include <xml/ecXmlCompType.h>

// Forward declarations
class EcManipulatorEndEffectorPlacement;

/// A grasp sequence.
class EC_ACTIN_GRASPING_DECL EcGraspSequenceState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGraspSequenceState
      (
      );

   /// destructor
   virtual ~EcGraspSequenceState
      (
      );

   /// copy constructor
   EcGraspSequenceState
      (
      const EcGraspSequenceState& orig
      );

   /// assignment operator
   EcGraspSequenceState& operator=
      (
      const EcGraspSequenceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspSequenceState& orig
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

   /// add element to the back of the grasp frame vector
   virtual void add
      (
      const EcGraspFrameState& fstate
      );

   /// add element to the back of the grasp frame vector
   virtual void add
      (
      const EcGraspFrameStateContainer& fstateContainer
      );

   /// clear the state
   virtual void clear
      (
      );

   /// remove the specified frame from the grasp frame vector
   virtual void deleteFrame
      (
      EcU32 index
      );

   /// get the grasp frame container vector
   virtual const EcGraspFrameStateContainerVector& graspFrameStateContainerVector
      (
      ) const;

   /// set the grasp frame container vector
   virtual void setGraspFrameStateContainerVector
      (
      const EcGraspFrameStateContainerVector& fstateContainerVector
      );

   /// get the current frame index
   virtual EcU32 currentFrameIndex
      (
      ) const;

   /// set the current frame index
   virtual void setCurrentFrameIndex
      (
      EcU32 index
      );

   /// get the flag indicating if the current frame needs initialization
   virtual EcBoolean currentFrameNeedsInit
      (
      ) const;

   /// set the flag indicating if the current frame needs initialization
   virtual void setCurrentFrameNeedsInit
      (
      EcBoolean flag
      );

   /// get the flag indicating if the current frame has completed
   virtual EcBoolean currentFrameIsComplete
      (
      ) const;

   /// set the flag indicating if the current frame has completed
   virtual void setCurrentFrameIsComplete
      (
      EcBoolean flag
      );

   /// get the current frame state
   virtual const EcGraspFrameState* currentFrameState
      (
      ) const;

   /// get the current frame state
   virtual EcGraspFrameState* currentFrameState
      (
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the current active frame
   EcXmlU32 m_CurrentFrameIndex;

   /// the flag indicating if the current frame needs initialization
   EcXmlBoolean m_CurrentFrameNeedsInit;

   /// the flag indicating if the current frame has completed
   EcXmlBoolean m_CurrentFrameIsComplete;

   /// the individual frames for this sequence
   EcGraspFrameStateContainerVector m_GraspFrameStateContainers;
};

#endif // ecGraspSequenceState_H_
