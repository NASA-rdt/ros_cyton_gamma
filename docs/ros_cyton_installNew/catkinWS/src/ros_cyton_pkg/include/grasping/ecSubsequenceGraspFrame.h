#ifndef ecSubsequenceGraspFrame_H_
#define ecSubsequenceGraspFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSubsequenceGraspFrame.h
/// @class EcSubsequenceGraspFrame
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrame.h"
#include "ecGraspFrameTransitionEventContainer.h"
#include "ecGraspSequence.h"

// Forward declarations
class EcGraspSequenceState;

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcSubsequenceGraspFrame : public EcGraspFrame
{
public:
   /// default constructor
   EcSubsequenceGraspFrame
      (
      );

   /// destructor
   virtual ~EcSubsequenceGraspFrame
      (
      );

   /// copy constructor
   EcSubsequenceGraspFrame
      (
      const EcSubsequenceGraspFrame& orig
      );

   /// assignment operator
   EcSubsequenceGraspFrame& operator=
      (
      const EcSubsequenceGraspFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSubsequenceGraspFrame& orig
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

   /// get the grasp sequence
   virtual const EcGraspSequence& graspSequence
      (
      ) const;

   /// set the grasp sequence
   virtual void setGraspSequence
      (
      const EcGraspSequence& sequence
      );

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcGraspFrameState& fstate
      ) const;

   /// get the vector of offset containers for this frame
   virtual const EcGraspOffsetContainerVector& offsetContainerVector
      (
      const EcGraspFrameState& fstate
      ) const;

   /// get the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      const EcGraspFrameState& fstate
      ) const;

   /// get the transition event container
   virtual const EcGraspFrameTransitionEventContainer& transitionEventContainer
      (
      const EcGraspFrameState& fstate
      ) const;

   /// set the transition event container
   virtual void setTransitionEventContainer
      (
      const EcGraspFrameTransitionEventContainer& eventContainer
      );

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcGraspFrameState& fstate
      ) const;

   /// pass through to the grasp sequence
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
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
      const EcGraspFrameState& fstate
      ) const;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      const EcGraspFrameState& fstate
      ) const;

   /// calculate the end state
   virtual EcGraspFrameStateContainer calculateEndState
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex
      ) const;

   /// initialize the grasp frame
   virtual EcBoolean init
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcGraspFrameStateContainer& fstateContainer
      ) const;

   /// update the grasp frame
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcGraspFrameState& fstate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcGraspFrameState& fstate,
      const EcString& separator
      ) const;

   /// get the current end effector placement
   virtual const EcManipulatorEndEffectorPlacement& currentEndEffectorPlacement
      (
      const EcGraspFrameState& fstate
      ) const;

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      const EcGraspFrameState& fstate
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
   /// the grasp sequence defining the subsequence of this frame
   EcGraspSequence                      m_GraspSequence;

   /// the transition event to indicate the end of this frame
   EcGraspFrameTransitionEventContainer m_TransitionEventContainer;
};

#endif // ecSubsequenceGraspFrame_H_
