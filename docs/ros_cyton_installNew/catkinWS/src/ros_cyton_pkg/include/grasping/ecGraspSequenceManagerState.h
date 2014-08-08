#ifndef ecGraspSequenceManagerState_H_
#define ecGraspSequenceManagerState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspSequenceManagerState.h
/// @class EcGraspSequenceManagerState
/// @brief State for EcGraspSequenceManager.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspSequenceState.h"

#include <xml/ecXmlCompType.h>

/// A grasp sequence.
class EC_ACTIN_GRASPING_DECL EcGraspSequenceManagerState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGraspSequenceManagerState
      (
      );

   /// destructor
   virtual ~EcGraspSequenceManagerState
      (
      );

   /// copy constructor
   EcGraspSequenceManagerState
      (
      const EcGraspSequenceManagerState& orig
      );

   /// assignment operator
   EcGraspSequenceManagerState& operator=
      (
      const EcGraspSequenceManagerState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspSequenceManagerState& orig
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

   /// clear the state
   virtual void clear
      (
      );

   /// get the current sequence index
   virtual EcU32 currentSequenceIndex
      (
      ) const;

   /// set the current sequence index
   virtual void setCurrentSequenceIndex
      (
      EcU32 index
      );

   /// get the flag indicating if the current sequence needs initialization
   virtual EcBoolean currentSequenceNeedsInit
      (
      ) const;

   /// set the flag indicating if the current sequence needs initialization
   virtual void setCurrentSequenceNeedsInit
      (
      EcBoolean flag
      );

   /// get the flag indicating if the current sequence has completed
   virtual EcBoolean currentSequenceIsComplete
      (
      ) const;

   /// set the flag indicating if the current sequence has completed
   virtual void setCurrentSequenceIsComplete
      (
      EcBoolean flag
      );

   /// get the current sequence state
   virtual const EcGraspSequenceState& currentSequenceState
      (
      ) const;

   /// get the current sequence state
   virtual EcGraspSequenceState& currentSequenceState
      (
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the current sequence index
   EcXmlU32 m_CurrentSequenceIndex;

   /// the flag indicating if the current sequence needs initialization
   EcXmlBoolean m_CurrentSequenceNeedsInit;

   /// the flag indicating if the current sequence has completed
   EcXmlBoolean m_CurrentSequenceIsComplete;

   /// the current sequence state
   EcGraspSequenceState m_CurrentSequenceState;
};

#endif // ecGraspSequenceManagerState_H_
