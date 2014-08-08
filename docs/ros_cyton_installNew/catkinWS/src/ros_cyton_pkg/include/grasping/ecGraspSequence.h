#ifndef ecGraspSequence_H_
#define ecGraspSequence_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspSequence.h
/// @class EcGraspSequence
/// @brief A grasp sequence.
///        This represents a sequence of grasp frames.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameContainer.h"
#include "ecGraspStatus.h"

#include <xml/ecXmlCompType.h>

// Forward declarations
class EcDataMap;
class EcForceControlDescription;
class EcGraspSequenceState;
class EcGraspUpdateParams;
class EcIndividualVelocityControlDescription;
class EcManipulatorEndEffectorForce;
class EcManipulatorEndEffectorPlacement;

/// an XML readable/writable vector of EcForceControlDescription objects
typedef EcXmlVectorType<EcForceControlDescription> EcForceControlDescriptionVector;

/// an XML readable/writable vector of EcIndividualVelocityControlDescription objects
typedef EcXmlVectorType<EcIndividualVelocityControlDescription> EcVelocityControlDescriptionVector;

/// Sensor force is typedef'ed to EcManipulatorEndEffectorForce
typedef EcManipulatorEndEffectorForce EcManipulatorSensorForce;

/// A grasp sequence.
class EC_ACTIN_GRASPING_DECL EcGraspSequence : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGraspSequence
      (
      );

   /// destructor
   virtual ~EcGraspSequence
      (
      );

   /// copy constructor
   EcGraspSequence
      (
      const EcGraspSequence& orig
      );

   /// assignment operator
   EcGraspSequence& operator=
      (
      const EcGraspSequence& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspSequence& orig
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

   /// add element to the back of the grasp frame vector
   virtual void add
      (
      const EcGraspFrame& graspFrame
      );

   /// add element to the back of the grasp frame vector
   virtual void add
      (
      const EcGraspFrameContainer& graspFrameContainer
      );

   /// remove the specified frame from the grasp frame vector
   virtual void deleteFrame
      (
      EcU32 index
      );

   /// get the grasp frame container vector
   virtual const EcGraspFrameContainerVector& graspFrameContainerVector
      (
      ) const;

   /// set the grasp frame container vector
   virtual void setGraspFrameContainerVector
      (
      const EcGraspFrameContainerVector& graspFrameContainerVector
      );

   /// get the current frame state
   virtual const EcGraspFrame* currentFrame
      (
      const EcGraspSequenceState& sstate
      ) const;

   /// get the current frame state
   virtual EcGraspFrame* currentFrame
      (
      const EcGraspSequenceState& sstate
      );

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcGraspSequenceState& sstate
      ) const;

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      const EcGraspSequenceState& sstate
      );

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcGraspSequenceState& sstate
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// modify the string-real map to add those found in the grasp frame containers
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
      const EcGraspSequenceState& sstate
      ) const;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      const EcGraspSequenceState& sstate
      ) const;

   /// calculate the end state
   virtual EcGraspSequenceState calculateEndState
      (
      const EcGraspUpdateParams& params
      ) const;

   /// initialize the grasp sequence
   virtual EcBoolean init
      (
      EcGraspSequenceState& sstate
      ) const;

   /// update the grasp sequence
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      EcGraspSequenceState& sstate
      ) const;

   /// a string describing status
   virtual EcString statusString
      (
      const EcGraspSequenceState& sstate,
      const EcString& separator
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

protected:
   /// the individual frames for this sequence
   EcGraspFrameContainerVector m_GraspFrameContainers;
};

#endif // ecGraspSequence_H_
