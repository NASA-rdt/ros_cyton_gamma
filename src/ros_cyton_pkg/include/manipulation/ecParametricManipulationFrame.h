#ifndef ecParametricManipulationFrame_H_
#define ecParametricManipulationFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricManipulationFrame.h
/// @class EcParametricManipulationFrame
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrame.h"
#include "ecManipulationFrameContainer.h"
#include "ecManipulationFrameTransitionEventContainer.h"

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcParametricManipulationFrame : public EcManipulationFrame
{
public:
   /// default constructor
   EcParametricManipulationFrame
      (
      );

   /// destructor
   virtual ~EcParametricManipulationFrame
      (
      );

   /// copy constructor
   EcParametricManipulationFrame
      (
      const EcParametricManipulationFrame& orig
      );

   /// assignment operator
   EcParametricManipulationFrame& operator=
      (
      const EcParametricManipulationFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricManipulationFrame& orig
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

   /// get the target frame
   virtual const EcManipulationFrameContainer& targetFrame
      (
      ) const;

   /// set the target frame
   virtual void setTargetFrame
      (
      const EcManipulationFrameContainer& frame
      );

   /// get the tag for setting the parametric value
   virtual const EcString& parametricTag
      (
      ) const;

   /// set the tag for setting the parametric value
   virtual void setParametricTag
      (
      const EcString& tag
      );

   /// get the parametric values
   virtual const EcXmlRealVector& parametricValues
      (
      ) const;

   /// set the parametric values
   virtual void setParametricValues
      (
      const EcXmlRealVector& values
      );

   /// get the vector of offset containers for this frame
   virtual const EcManipulationOffsetContainerVector& offsetContainerVector
      (
      const EcManipulationFrameState& fstate
      ) const;

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

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationFrameState& fstate
      ) const;

   /// \copydoc EcManipulationFrame::endEffectorSet
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationFrameState& fstate
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
   /// the target frame
   EcManipulationFrameContainer                m_TargetFrame;

   /// the tag for setting the parametric value
   EcXmlString                          m_ParametricTag;

   /// the parametric values
   EcXmlRealVector                      m_ParametricValues;

   /// the transition event to indicate the end of this frame
   EcManipulationFrameTransitionEventContainer m_TransitionEventContainer;
};

#endif // ecParametricManipulationFrame_H_
