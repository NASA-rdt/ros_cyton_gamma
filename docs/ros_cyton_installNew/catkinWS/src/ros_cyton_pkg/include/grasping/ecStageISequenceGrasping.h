#ifndef ecStageISequenceGrasping_H_
#define ecStageISequenceGrasping_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageISequenceGrasping.h
/// @class EcStageISequenceGrasping
/// @brief This class provides foundation stage I grasping for
///        a Robonaut hand.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseStageIGraspingModule.h"
#include "ecGraspSequence.h"
#include "ecGraspSequenceState.h"

/// This class provides foundation stage I grasping for a Robonaut hand.
class EC_ACTIN_GRASPING_DECL EcStageISequenceGrasping : public EcBaseStageIGraspingModule
{
public:
   /// default constructor
   EcStageISequenceGrasping
      (
      );

   /// destructor
   virtual ~EcStageISequenceGrasping
      (
      );

   /// copy constructor
   EcStageISequenceGrasping
      (
      const EcStageISequenceGrasping& orig
      );

   /// assignment operator
   EcStageISequenceGrasping& operator=
      (
      const EcStageISequenceGrasping& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageISequenceGrasping& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
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

   /// register XML member variables
   void registerComponents
      (
      );

   /// initialize the grasp calculation for the specified object and manipulator
   virtual EcBoolean calculateGrasp
      (
      const EcGraspInitParams& params
      );

   /// Append control descriptions required for the calculated grasp to a vector
   virtual void appendControlDescriptions
      (
      EcVelocityControlDescriptionVector& controlDescriptions,
      const EcIndividualVelocityControlDescription& prototype = EcIndividualVelocityControlDescription()
      );

   /// Append force control descriptions required for the calculated grasp to a vector
   virtual void appendForceControlDescriptions
      (
      EcForceControlDescriptionVector& controlDescriptions,
      const EcForceControlDescription& prototype = EcForceControlDescription()
      );

   /// Return the ative control description index to be used for the grasp
   virtual EcU32 activeControlDescription
      (
      );

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      );

   /// Return the grasp status
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params
      );

   /// return the placements for the end effectors used in the grasp motion
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPositions
      (
      );

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      );

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      ) const;

   /// Return the grasp sequence that defines this grasp
   const EcGraspSequence& graspSequence
      (
      ) const;

   /// Set the grasp sequence that defines this grasp
   void setGraspSequence
      (
      const EcGraspSequence& sequence
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the grasp sequence
   EcGraspSequence m_GraspSequence;

   // non-XML data

   /// the grasp sequence state
   EcGraspSequenceState m_GraspSequenceState;
};

#endif // ecStageISequenceGrasping_H_
