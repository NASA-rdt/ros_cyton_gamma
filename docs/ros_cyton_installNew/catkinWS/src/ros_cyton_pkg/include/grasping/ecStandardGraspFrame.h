#ifndef ecStandardGraspFrame_H_
#define ecStandardGraspFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStandardGraspFrame.h
/// @class EcStandardGraspFrame
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrame.h"
#include "ecGraspFrameTransitionEventContainer.h"
#include "ecGraspOffsetContainer.h"
#include <control/ecEndEffectorSet.h>
#include <forceControl/ecForceControllerVector.h>
#include <foundCommon/ecDataMap.h>

// Forward declarations
class EcGraspOffsetState;
class EcGraspSequence;
class EcGraspUpdateParams;

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcStandardGraspFrame : public EcGraspFrame
{
public:
   /// default constructor
   EcStandardGraspFrame
      (
      );

   /// destructor
   virtual ~EcStandardGraspFrame
      (
      );

   /// copy constructor
   EcStandardGraspFrame
      (
      const EcStandardGraspFrame& orig
      );

   /// assignment operator
   EcStandardGraspFrame& operator=
      (
      const EcStandardGraspFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStandardGraspFrame& orig
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

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcGraspFrameState& fstate
      ) const;

   /// set the end effector set for this frame
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& eeSet
      );

   /// get the vector of offset containers for this frame
   virtual const EcGraspOffsetContainerVector& offsetContainerVector
      (
      const EcGraspFrameState& fstate
      ) const;

   /// set the vector of offset containers for this frame
   virtual void setOffsetContainerVector
      (
      const EcGraspOffsetContainerVector& offsetContainerVector
      );

   /// get the force controllers for this frame
   virtual const EcForceControllerVector& forceControllers
      (
      const EcGraspFrameState& fstate
      ) const;

   /// set the force controllers for this frame
   virtual void setForceControllers
      (
      const EcForceControllerVector& forceControllers
      );

   /// get the grasp force for this frame
   virtual const EcManipulatorSensorForce& graspForce
      (
      const EcGraspFrameState& fstate
      ) const;

   /// set the grasp force for this frame
   virtual void setGraspForce
      (
      const EcManipulatorSensorForce& graspForce
      );

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

   /// set the data map
   virtual void setDataMap
      (
      const EcDataMap& dm
      );

   /// compiles string-real values from the vector of grasp offsets
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

   /// replace a specified grasp offset with a new one
   virtual EcBoolean replaceGraspOffset
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 offsetIndex,
      const EcGraspOffset& newOffset,
      const EcGraspOffsetState& oldState,
      EcGraspOffsetState& newState
      );

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
   /// the end effector set for this frame
   EcEndEffectorSet                     m_EndEffectorSet;

   /// the offsets for this frame
   EcGraspOffsetContainerVector         m_GraspOffsetContainerVector;

   /// the force controllers for this frame
   EcForceControllerVector              m_ForceControllers;

   /// the grasp force for this frame
   EcManipulatorSensorForce             m_GraspForce;

   /// the transition event to indicate the end of this frame
   EcGraspFrameTransitionEventContainer m_TransitionEventContainer;

   /// the data map
   EcDataMap                            m_DataMap;

   // non-XML data

   /// DEPRECATED used for reading old file formats
   EcManipulatorEndEffectorPlacement    m_DeprecatedPlacement;

   /// The active control description index to be used during this grasp frame
   EcU32                                m_ActiveControlDescription;

   /// The active force control description index to be used during this grasp frame
   EcU32                                m_ActiveForceControlDescription;
};

#endif // ecStandardGraspFrame_H_
