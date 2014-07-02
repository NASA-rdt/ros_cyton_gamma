#ifndef ecManipulationFrame_H_
#define ecManipulationFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrame.h
/// @class EcManipulationFrame
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationStatus.h"

#include <forceControl/ecManipSensorForce.h>
#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcDataMap;
class EcEndEffectorSet;
class EcManipulatorEndEffectorPlacement;
class EcManipulationFrameState;
class EcManipulationFrameStateContainer;
class EcManipulationOffsetContainer;
class EcManipulationSequence;
class EcManipulationSequenceState;
class EcManipulationUpdateParams;
/// type definition of EcManipulationOffsetContainerVector
typedef EcXmlVectorType<EcManipulationOffsetContainer> EcManipulationOffsetContainerVector;

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrame : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationFrame
      (
      );

   /// destructor
   virtual ~EcManipulationFrame
      (
      );

   /// copy constructor
   EcManipulationFrame
      (
      const EcManipulationFrame& orig
      );

   /// assignment operator
   EcManipulationFrame& operator=
      (
      const EcManipulationFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrame& orig
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

   /// get the vector of offset containers for this frame
   virtual const EcManipulationOffsetContainerVector& offsetContainerVector
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const = 0;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// calculate the end state
   virtual EcManipulationFrameStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex
      ) const = 0;

   /// initialize the manipulation frame
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcManipulationFrameStateContainer& fstateContainer
      ) const = 0;

   /// update the manipulation frame
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcManipulationFrameState& fstate
      ) const = 0;

   /// get the overall progress of this frame
   virtual EcReal progress
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationFrameState& fstate,
      const EcString& separator
      ) const = 0;

   /// get the current end effector placement
   virtual const EcManipulatorEndEffectorPlacement& currentEndEffectorPlacement
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      const EcManipulationFrameState& fstate
      ) const = 0;

protected:
   /// tag used for referencing this frame
   EcXmlString m_Tag;
};

#endif // ecManipulationFrame_H_
