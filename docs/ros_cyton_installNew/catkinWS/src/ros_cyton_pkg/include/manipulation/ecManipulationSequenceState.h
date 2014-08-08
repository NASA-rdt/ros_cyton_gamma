#ifndef ecManipulationSequenceState_H_
#define ecManipulationSequenceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSequenceState.h
/// @class EcManipulationSequenceState
/// @brief A manipulation sequence.
///        This represents a sequence of manipulation frames.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationActionState.h"
#include "ecManipulationFrameStateContainer.h"

// Forward declarations
class EcManipulatorEndEffectorPlacement;

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationSequenceState : public EcManipulationActionState
{
public:
   /// default constructor
   EcManipulationSequenceState
      (
      );

   /// destructor
   virtual ~EcManipulationSequenceState
      (
      );

   /// copy constructor
   EcManipulationSequenceState
      (
      const EcManipulationSequenceState& orig
      );

   /// assignment operator
   EcManipulationSequenceState& operator=
      (
      const EcManipulationSequenceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSequenceState& orig
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

   /// add element to the back of the manipulation frame vector
   virtual void add
      (
      const EcManipulationFrameState& fstate
      );

   /// add element to the back of the manipulation frame vector
   virtual void add
      (
      const EcManipulationFrameStateContainer& fstateContainer
      );

   /// clear the state
   virtual void clear
      (
      );

   /// remove the specified frame from the manipulation frame vector
   virtual void deleteFrame
      (
      EcU32 index
      );

   /// get the manipulation frame container vector
   virtual const EcManipulationFrameStateContainerVector& manipulationFrameStateContainerVector
      (
      ) const;

   /// set the manipulation frame container vector
   virtual void setManipulationFrameStateContainerVector
      (
      const EcManipulationFrameStateContainerVector& fstateContainerVector
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
   virtual const EcManipulationFrameState* currentFrameState
      (
      ) const;

   /// get the current frame state
   virtual EcManipulationFrameState* currentFrameState
      (
      );

   /// get the progress
   virtual EcReal progress
      (
      ) const;

   /// set the progress
   virtual void setProgress
      (
      EcReal value
      );

   /// get the token
   virtual const EcToken& token
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
   /// the current active frame
   EcXmlU32 m_CurrentFrameIndex;

   /// the flag indicating if the current frame needs initialization
   EcXmlBoolean m_CurrentFrameNeedsInit;

   /// the flag indicating if the current frame has completed
   EcXmlBoolean m_CurrentFrameIsComplete;

   /// the individual frames for this sequence
   EcManipulationFrameStateContainerVector m_ManipulationFrameStateContainers;

   /// the progress for this sequence (0.0 = not started, 1.0 = completed)
   EcXmlReal m_Progress;
};

#endif // ecManipulationSequenceState_H_
