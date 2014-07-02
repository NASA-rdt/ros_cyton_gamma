#ifndef ecManipulationSequenceManagerState_H_
#define ecManipulationSequenceManagerState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSequenceManagerState.h
/// @class EcManipulationSequenceManagerState
/// @brief State for EcManipulationSequenceManager.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationActionStateContainer.h"

#include <xml/ecXmlCompType.h>

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationSequenceManagerState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationSequenceManagerState
      (
      );

   /// destructor
   virtual ~EcManipulationSequenceManagerState
      (
      );

   /// copy constructor
   EcManipulationSequenceManagerState
      (
      const EcManipulationSequenceManagerState& orig
      );

   /// assignment operator
   EcManipulationSequenceManagerState& operator=
      (
      const EcManipulationSequenceManagerState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSequenceManagerState& orig
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
   virtual const EcManipulationActionStateContainer& currentSequenceStateContainer
      (
      ) const;

   /// get the current sequence state
   virtual EcManipulationActionStateContainer& currentSequenceStateContainer
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
   EcManipulationActionStateContainer m_CurrentSequenceStateContainer;
};

#endif // ecManipulationSequenceManagerState_H_
