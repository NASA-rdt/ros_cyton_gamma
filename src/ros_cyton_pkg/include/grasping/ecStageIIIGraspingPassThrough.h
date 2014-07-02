#ifndef ecStageIIIGraspingPassThrough_H_
#define ecStageIIIGraspingPassThrough_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIIIGraspingPassThrough.h
/// @class EcStageIIIGraspingPassThrough
/// @brief This class provides a pass-through Stage II processor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseStageIIIGraspingModule.h"

/// This class provides a pass-through Stage II processor.
class EC_ACTIN_GRASPING_DECL EcStageIIIGraspingPassThrough : public EcBaseStageIIIGraspingModule
{
public:
   /// default constructor
   EcStageIIIGraspingPassThrough
      (
      );

   /// destructor
   virtual ~EcStageIIIGraspingPassThrough
      (
      );

   /// copy constructor
   EcStageIIIGraspingPassThrough
      (
      const EcStageIIIGraspingPassThrough& orig
      );

   /// assignment operator
   EcStageIIIGraspingPassThrough& operator=
      (
      const EcStageIIIGraspingPassThrough& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIIIGraspingPassThrough& orig
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

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
};

#endif // ecStageIIIGraspingPassThrough_H_
