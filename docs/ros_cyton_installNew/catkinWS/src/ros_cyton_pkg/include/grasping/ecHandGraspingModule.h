#ifndef ecHandGraspingModule_H_
#define ecHandGraspingModule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecHandGraspingModule.h
/// @class EcHandGraspingModule
/// @brief This class provides a grasping module for a generic hand
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseHandGraspingModule.h"

/// This class provides a grasping module for a generic hand
class EC_ACTIN_GRASPING_DECL EcHandGraspingModule : public EcBaseHandGraspingModule
{
public:
   /// default constructor
   EcHandGraspingModule
      (
      );

   /// destructor
   virtual ~EcHandGraspingModule
      (
      );

   /// copy constructor
   EcHandGraspingModule
      (
      const EcHandGraspingModule& orig
      );

   /// assignment operator
   EcHandGraspingModule& operator=
      (
      const EcHandGraspingModule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcHandGraspingModule& orig
      ) const;

   /// register XML member variables
   void registerComponents
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// return a token
   virtual const EcToken& token
      (
      ) const;

   /// virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// Calculate the grasp and save it internally for access
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

   /// Return the placements for the end effectors used in the grasp motion
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
};

#endif // ecHandGraspingModule_H_
