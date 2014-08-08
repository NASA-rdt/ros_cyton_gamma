#ifndef ecManipulationSequence_H_
#define ecManipulationSequence_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSequence.h
/// @class EcManipulationSequence
/// @brief A manipulation sequence.
///        This represents a sequence of manipulation frames.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationAction.h"
#include "ecManipulationFrameContainer.h"

// Forward declarations
class EcDataMap;
class EcManipulationSequenceState;

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationSequence : public EcManipulationAction
{
public:
   /// default constructor
   EcManipulationSequence
      (
      );

   /// destructor
   virtual ~EcManipulationSequence
      (
      );

   /// copy constructor
   EcManipulationSequence
      (
      const EcManipulationSequence& orig
      );

   /// assignment operator
   EcManipulationSequence& operator=
      (
      const EcManipulationSequence& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSequence& orig
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
      const EcManipulationFrame& manipulationFrame
      );

   /// add element to the back of the manipulation frame vector
   virtual void add
      (
      const EcManipulationFrameContainer& manipulationFrameContainer
      );

   /// remove the specified frame from the manipulation frame vector
   virtual void deleteFrame
      (
      EcU32 index
      );

   /// get the manipulation frame container vector
   virtual const EcManipulationFrameContainerVector& manipulationFrameContainerVector
      (
      ) const;

   /// set the manipulation frame container vector
   virtual void setManipulationFrameContainerVector
      (
      const EcManipulationFrameContainerVector& manipulationFrameContainerVector
      );

   /// get the current frame state
   virtual const EcManipulationFrame* currentFrame
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the current frame state
   virtual EcManipulationFrame* currentFrame
      (
      const EcManipulationActionState& astate
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// calculate the end state
   virtual EcManipulationSequenceState calculateEndState
      (
      const EcManipulationUpdateParams& params
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   //---
   // Implementation of EcManipulationAction interface
   //---

   /// initialize the manipulation sequence
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const;

   /// update the manipulation sequence
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const;

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState&  astate
      ) const;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the overall progress of this action
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationActionState& astate,
      const EcString& separator
      ) const;

   /// @copydoc EcManipulationAction::profiledPositionEndEffectorIndices()
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationActionState& astate
      ) const;

protected:
   /// the individual frames for this sequence
   EcManipulationFrameContainerVector m_ManipulationFrameContainers;

   /// non-XML
   static const EcU32Vector           m_theNullU32Vector;
};

#endif // ecManipulationSequence_H_
