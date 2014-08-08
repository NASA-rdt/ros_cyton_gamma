#ifndef ecStandardManipulationFrame_H_
#define ecStandardManipulationFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStandardManipulationFrame.h
/// @class EcStandardManipulationFrame
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrame.h"
#include "ecManipulationFrameTransitionEventContainer.h"
#include "ecManipulationOffsetContainer.h"
#include <control/ecEndEffectorSet.h>
#include <forceControl/ecForceControllerVector.h>
#include <foundCommon/ecDataMap.h>


// Forward declarations
class EcManipulationOffsetState;
class EcManipulationSequence;
class EcManipulationUpdateParams;

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcStandardManipulationFrame : public EcManipulationFrame
{
public:
   /// default constructor
   EcStandardManipulationFrame
      (
      );

   /// destructor
   virtual ~EcStandardManipulationFrame
      (
      );

   /// copy constructor
   EcStandardManipulationFrame
      (
      const EcStandardManipulationFrame& orig
      );

   /// assignment operator
   EcStandardManipulationFrame& operator=
      (
      const EcStandardManipulationFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStandardManipulationFrame& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

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

   /// get the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// set the ative control description index to be used for the manipulation
   virtual void setActiveControlDescription
      (
      EcU32 value
      );

   /// get the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// set the ative end-effector set index to be used for the manipulation
   virtual void setActiveEndEffectorSet
      (
      EcU32 value
      );

   /// get the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// set the ative control method index to be used for the manipulation
   virtual void setActiveControlMethod
      (
      EcU32 value
      );

   /// \copydoc EcManipulationFrame::endEffectorSet
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationFrameState& fstate
      ) const;

   /// get the vector of offset containers for this frame
   virtual const EcManipulationOffsetContainerVector& offsetContainerVector
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// set the vector of offset containers for this frame
   virtual void setOffsetContainerVector
      (
      const EcManipulationOffsetContainerVector& offsetContainerVector
      );

   /// get the transition event container
   virtual const EcManipulationFrameTransitionEventContainer& transitionEventContainer
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// set the transition event container
   virtual void setTransitionEventContainer
      (
      const EcManipulationFrameTransitionEventContainer& eventContainer
      );

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// set the data map
   virtual void setDataMap
      (
      const EcDataMap& dm
      );

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// calculate the end state
   virtual EcManipulationFrameStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex
      ) const;

   /// initialize the manipulation frame
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcManipulationFrameStateContainer& fstateContainer
      ) const;

   /// update the manipulation frame
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcManipulationFrameState& fstate
      ) const;

   /// get the overall progress of this frame
   virtual EcReal progress
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationFrameState& fstate,
      const EcString& separator
      ) const;

   /// replace a specified manipulation offset with a new one
   virtual EcBoolean replaceManipulationOffset
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 offsetIndex,
      const EcManipulationOffset& newOffset,
      const EcManipulationOffsetState& oldState,
      EcManipulationOffsetState& newState
      );

   /// get the current end effector placement
   virtual const EcManipulatorEndEffectorPlacement& currentEndEffectorPlacement
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      const EcManipulationFrameState& fstate
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
   /// The active control description index to be used during this manipulation frame
   EcXmlU32                            m_ActiveControlDescription;

   /// The active end-effectr set index to be used during this manipulation frame
   EcXmlU32                            m_ActiveEndEffectorSet;

   /// The active control method index to be used during this manipulation frame
   EcXmlU32                            m_ActiveControlMethod;

   /// the offsets for this frame
   EcManipulationOffsetContainerVector        m_ManipulationOffsetContainerVector;

   /// the transition event to indicate the end of this frame
   EcManipulationFrameTransitionEventContainer   m_TransitionEventContainer;

   /// the data map
   EcDataMap                           m_DataMap;

   /// the null EE set for error recovery
   static const EcEndEffectorSet       m_theNullEndEffectorSet;
};

#endif // ecStandardManipulationFrame_H_
