#ifndef ecGraspSequenceManager_H_
#define ecGraspSequenceManager_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspSequenceManager.h
/// @class EcGraspSequenceManager
/// @brief Manages multiple grasp sequences.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspSequence.h"
#include "ecGraspStatus.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcGraspSequenceManagerState;

/// A grasp sequence.
class EC_ACTIN_GRASPING_DECL EcGraspSequenceManager : public EcXmlCompoundType
{
public:

   /// an XML-readable/writable map from strings to grasp sequences
   typedef EcXmlMapType<EcXmlString, EcGraspSequence> StringSequenceMap;

   /// default constructor
   EcGraspSequenceManager
      (
      );

   /// destructor
   virtual ~EcGraspSequenceManager
      (
      );

   /// copy constructor
   EcGraspSequenceManager
      (
      const EcGraspSequenceManager& orig
      );

   /// assignment operator
   EcGraspSequenceManager& operator=
      (
      const EcGraspSequenceManager& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspSequenceManager& orig
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
      const EcGraspSequence& sequence
      );

   /// remove a sequence from the map of managed sequences
   virtual void remove
      (
      const EcString& key
      );

   /// get the current sequence
   virtual const EcGraspSequence* currentSequence
      (
      const EcGraspSequenceManagerState& mstate
      ) const;

   /// get the current sequence
   virtual EcGraspSequence* currentSequence
      (
      const EcGraspSequenceManagerState& mstate
      );

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcGraspSequenceManagerState& mstate
      ) const;

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      const EcGraspSequenceManagerState& mstate
      );

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcGraspSequenceManagerState& mstate
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// Append control descriptions required for the calculated grasp to a vector
   virtual void appendControlDescriptions
      (
      EcVelocityControlDescriptionVector& controlDescriptions,
      const EcIndividualVelocityControlDescription& prototype
      );

   /// Append force control descriptions required for the calculated grasp to a vector
   virtual void appendForceControlDescriptions
      (
      EcForceControlDescriptionVector& controlDescriptions,
      const EcForceControlDescription& prototype
      );

   /// Return the ative control description index to be used for the grasp
   virtual EcU32 activeControlDescription
      (
      const EcGraspSequenceManagerState& mstate
      ) const;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      const EcGraspSequenceManagerState& mstate
      ) const;

   /// calculate the end state
   virtual EcGraspSequenceManagerState calculateEndState
      (
      const EcGraspUpdateParams& params
      ) const;

   /// initialize the manager
   virtual EcBoolean init
      (
      EcGraspSequenceManagerState& mstate
      ) const;

   /// update the manager
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      EcGraspSequenceManagerState& mstate
      ) const;

   /// a status string found by pass through to the current sequence
   virtual EcString statusString
      (
      const EcGraspSequenceManagerState& mstate,
      const EcString& separator
      ) const;

protected:
   /// the order of sequence execution
   EcXmlStringVector m_SequenceOrder;

   /// the sequences being managed
   StringSequenceMap m_SequenceMap;
};

#endif // ecGraspSequenceManager_H_
