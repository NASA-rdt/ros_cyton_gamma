#ifndef ecStageIIIGraspingContainer_H_
#define ecStageIIIGraspingContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIIIGraspingContainer.h
/// @class EcStageIIIGraspingContainer
/// @brief Container for stage I grasping
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspStatus.h"
#include <control/ecIndVelContDesc.h>
#include <forceControl/ecForceControlDescription.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

// Forward declarations
class EcBaseStageIIIGraspingModule;
class EcBaseStageIIGraspingModule;
class EcGraspInitParams;
class EcGraspUpdateParams;


/// Container for stage I grasping
class EC_ACTIN_GRASPING_DECL EcStageIIIGraspingContainer :
   public EcXmlVariableElementType<EcBaseStageIIIGraspingModule>
{
public:
   /// default constructor
   EcStageIIIGraspingContainer
      (
      );

   /// destructor
   virtual ~EcStageIIIGraspingContainer
      (
      );

   /// copy constructor
   EcStageIIIGraspingContainer
      (
      const EcStageIIIGraspingContainer& orig
      );

   /// assignment operator
   EcStageIIIGraspingContainer& operator=
      (
      const EcStageIIIGraspingContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIIIGraspingContainer& orig
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

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// set the pointer to the Stage II module
   virtual void setPrecursorPointer
      (
      EcBaseStageIIGraspingModule* precursorPointer
      );

   /// null object
   static EcStageIIIGraspingContainer nullObject
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
};

#endif // ecStageIIIGraspingContainer_H_
