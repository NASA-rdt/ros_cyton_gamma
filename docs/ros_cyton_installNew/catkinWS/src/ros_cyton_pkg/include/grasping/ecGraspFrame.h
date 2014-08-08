#ifndef ecGraspFrame_H_
#define ecGraspFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrame.h
/// @class EcGraspFrame
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspStatus.h"

#include <forceControl/ecManipSensorForce.h>
#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcDataMap;
class EcEndEffectorSet;
class EcForceControlDescription;
class EcGraspFrameState;
class EcGraspFrameStateContainer;
class EcGraspOffsetContainer;
class EcGraspSequence;
class EcGraspSequenceState;
class EcGraspUpdateParams;
class EcIndividualVelocityControlDescription;
class EcManipulatorEndEffectorPlacement;

/// an XML readable/writable vector of EcGraspOffsetContainer objects
typedef EcXmlVectorType<EcGraspOffsetContainer> EcGraspOffsetContainerVector;

/// an XML readable/writable vector of EcForceControlDescription objects
typedef EcXmlVectorType<EcForceControlDescription> EcForceControlDescriptionVector;

/// an XML readable/writable vector of EcIndividualVelocityControlDescription objects
typedef EcXmlVectorType<EcIndividualVelocityControlDescription> EcVelocityControlDescriptionVector;

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcGraspFrame : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspFrame
      (
      );

   /// destructor
   virtual ~EcGraspFrame
      (
      );

   /// copy constructor
   EcGraspFrame
      (
      const EcGraspFrame& orig
      );

   /// assignment operator
   EcGraspFrame& operator=
      (
      const EcGraspFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrame& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// Get tag used for referencing this frame
   virtual const EcXmlString& tag
      (
      ) const;

   /// Set tag used for referencing this frame
   virtual void setTag
      (
      const EcXmlString& tag
      );

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// get the vector of offset containers for this frame
   virtual const EcGraspOffsetContainerVector& offsetContainerVector
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// virtual method to establish string-real pairs
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const = 0;

   /// Append control descriptions required for the calculated grasp to a vector
   virtual void appendControlDescriptions
      (
      EcVelocityControlDescriptionVector& controlDescriptions,
      const EcIndividualVelocityControlDescription& prototype
      ) = 0;

   /// Append force control descriptions required for the calculated grasp to a vector
   virtual void appendForceControlDescriptions
      (
      EcForceControlDescriptionVector& controlDescriptions,
      const EcForceControlDescription& prototype
      ) = 0;

   /// Return the ative control description index to be used for the grasp
   virtual EcU32 activeControlDescription
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// calculate the end state
   virtual EcGraspFrameStateContainer calculateEndState
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex
      ) const = 0;

   /// initialize the grasp frame
   virtual EcBoolean init
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcGraspFrameStateContainer& fstateContainer
      ) const = 0;

   /// update the grasp frame
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcGraspFrameState& fstate
      ) const = 0;

   /// get the status string
   virtual EcString statusString
      (
      const EcGraspFrameState& fstate,
      const EcString& separator
      ) const = 0;

   /// get the current end effector placement
   virtual const EcManipulatorEndEffectorPlacement& currentEndEffectorPlacement
      (
      const EcGraspFrameState& fstate
      ) const = 0;

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      const EcGraspFrameState& fstate
      ) const = 0;

protected:
   /// tag used for referencing this frame
   EcXmlString m_Tag;
};

#endif // ecGraspFrame_H_
