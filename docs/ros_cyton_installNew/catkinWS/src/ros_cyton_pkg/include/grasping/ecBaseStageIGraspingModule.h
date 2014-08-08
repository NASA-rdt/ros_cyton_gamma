#ifndef ecBaseStageIGraspingModule_H_
#define ecBaseStageIGraspingModule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseStageIGraspingModule.h
/// @class EcBaseStageIGraspingModule
/// @brief This class is a base class for stage I grasping
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspStatus.h"
#include <control/ecIndVelContDesc.h>
#include <forceControl/ecForceControlDescription.h>
#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcGraspInitParams;
class EcGraspUpdateParams;

/** This class is a base class for stage I grasping
*/
class EC_ACTIN_GRASPING_DECL EcBaseStageIGraspingModule : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseStageIGraspingModule
      (
      );

   /// destructor
   virtual ~EcBaseStageIGraspingModule
      (
      );

   /// copy constructor
   EcBaseStageIGraspingModule
      (
      const EcBaseStageIGraspingModule& orig
      );

   /// assignment operator
   EcBaseStageIGraspingModule& operator=
      (
      const EcBaseStageIGraspingModule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseStageIGraspingModule& orig
      ) const;

   /// register XML member variables
   void registerComponents
      (
      );

   /// initialize the grasp calculation for the specified object and manipulator
   virtual EcBoolean calculateGrasp
      (
      const EcGraspInitParams& params
      ) = 0;

   /// Append control descriptions required for the calculated grasp to a vector
   virtual void appendControlDescriptions
      (
      EcVelocityControlDescriptionVector& controlDescriptions,
      const EcIndividualVelocityControlDescription& prototype = EcIndividualVelocityControlDescription()
      ) = 0;

   /// Append force control descriptions required for the calculated grasp to a vector
   virtual void appendForceControlDescriptions
      (
      EcForceControlDescriptionVector& controlDescriptions,
      const EcForceControlDescription& prototype = EcForceControlDescription()
      ) = 0;

   /// Return the ative control description index to be used for the grasp
   virtual EcU32 activeControlDescription
      (
      ) = 0;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      ) = 0;

   /// Return the grasp status
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params
      ) = 0;

   /// return the placements for the end effectors used in the grasp motion
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPositions
      (
      ) = 0;

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      ) = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      ) const = 0;
};

#endif // ecBaseStageIGraspingModule_H_
