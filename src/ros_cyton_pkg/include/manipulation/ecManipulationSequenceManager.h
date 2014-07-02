#ifndef ecManipulationSequenceManager_H_
#define ecManipulationSequenceManager_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSequenceManager.h
/// @class EcManipulationSequenceManager
/// @brief Manages multiple manipulation sequences.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationSequence.h"
#include "ecManipulationStatus.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcManipulationSequenceManagerState;

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationSequenceManager : public EcXmlCompoundType
{
public:
   /// type definition of StringSequenceMap
   typedef EcXmlMapType<EcXmlString, EcManipulationSequence> StringSequenceMap;

   /// default constructor
   EcManipulationSequenceManager
      (
      );

   /// destructor
   virtual ~EcManipulationSequenceManager
      (
      );

   /// copy constructor
   EcManipulationSequenceManager
      (
      const EcManipulationSequenceManager& orig
      );

   /// assignment operator
   EcManipulationSequenceManager& operator=
      (
      const EcManipulationSequenceManager& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSequenceManager& orig
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

   /// return a true if there there are no sequences to manage
   EcBoolean empty
      (
      ) const;

   /// get the sequence map
   const StringSequenceMap& sequenceMap
      (
      ) const;

   /// set the sequence map
   void setSequenceMap
      (
      const StringSequenceMap& map
      );

   /// get the sequence order
   const EcXmlStringVector& sequenceOrder
      (
      ) const;

   /// set the sequence order
   void setSequenceOrder
      (
      const EcXmlStringVector& order
      );

   /// add a sequence to the map of managed sequences
   virtual void add
      (
      const EcString&        key,
      const EcManipulationSequence& sequence
      );

   /// remove a sequence from the map of managed sequences
   virtual void remove
      (
      const EcString& key
      );

   /// get the current sequence
   virtual const EcManipulationSequence* currentSequence
      (
      const EcManipulationSequenceManagerState& mstate
      ) const;

   /// get the current sequence
   virtual EcManipulationSequence* currentSequence
      (
      const EcManipulationSequenceManagerState& mstate
      );

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationSequenceManagerState& mstate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationSequenceManagerState& mstate
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationSequenceManagerState& mstate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationSequenceManagerState& fstate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationSequenceManagerState& fstate
      ) const;

   /// calculate the end state
   virtual EcManipulationSequenceManagerState calculateEndState
      (
      const EcManipulationUpdateParams& params
      ) const;

   /// initialize the manager
   virtual EcBoolean init
      (
      EcManipulationSequenceManagerState& mstate
      ) const;

   /// update the manager
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationSequenceManagerState& mstate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationSequenceManagerState& mstate,
      const EcString& separator
      ) const;

protected:
   /// the order of sequence execution
   EcXmlStringVector m_SequenceOrder;

   /// the sequences being managed
   StringSequenceMap m_SequenceMap;
};

#endif // ecManipulationSequenceManager_H_
