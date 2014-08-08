#ifndef ecObjectGraspingModule_H_
#define ecObjectGraspingModule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecObjectGraspingModule.h
/// @class EcObjectGraspingModule
/// @brief Container for object grasping modules
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspStatus.h"
#include "ecStageIGraspingContainer.h"
#include "ecStageIIGraspingContainer.h"
#include "ecStageIIIGraspingContainer.h"
#include <xml/ecXmlCompType.h>

/// Container for object grasping modules
class EC_ACTIN_GRASPING_DECL EcObjectGraspingModule : public EcXmlCompoundType
{
public:
   /// default constructor
   EcObjectGraspingModule
      (
      );

   /// destructor
   virtual ~EcObjectGraspingModule
      (
      );

   /// copy constructor
   EcObjectGraspingModule
      (
      const EcObjectGraspingModule& orig
      );

   /// assignment operator
   EcObjectGraspingModule& operator=
      (
      const EcObjectGraspingModule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcObjectGraspingModule& orig
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

   /// register all components
   virtual void registerComponents
      (
      );

   /// null object
   static EcObjectGraspingModule nullObject
      (
      );

   /// get stage I grasping container
   virtual const EcStageIGraspingContainer& stageIGraspingContainer
      (
      ) const;

   /// set stage I grasping container
   virtual void setStageIGraspingContainer
      (
      const EcStageIGraspingContainer& stageIGraspingContainer
      );

   /// get stage II grasping container
   virtual const EcStageIIGraspingContainer& stageIIGraspingContainer
      (
      ) const;

   /// set stage II grasping container
   virtual void setStageIIGraspingContainer
      (
      const EcStageIIGraspingContainer& stageIIGraspingContainer
      );

   /// get stage III grasping container
   virtual const EcStageIIIGraspingContainer& stageIIIGraspingContainer
      (
      ) const;

   /// set stage III grasping container
   virtual void setStageIIIGraspingContainer
      (
      const EcStageIIIGraspingContainer& stageIIIGraspingContainer
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

protected:
   /// stage I grasping container
   EcStageIGraspingContainer m_StageIGraspingContainer;

   /// stage II grasping container
   EcStageIIGraspingContainer m_StageIIGraspingContainer;

   /// stage III grasping container
   EcStageIIIGraspingContainer m_StageIIIGraspingContainer;
};

#endif // ecObjectGraspingModule_H_
