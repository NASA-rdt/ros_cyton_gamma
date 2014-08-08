#ifndef ecStageIRobonautPalmAndFingers_H_
#define ecStageIRobonautPalmAndFingers_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIRobonautPalmAndFingers.h
/// @class EcStageIRobonautPalmAndFingers
/// @brief This class provides foundation stage I grasping for
///        a Robonaut hand.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseStageIGraspingModule.h"

/// This class provides foundation stage I grasping for a Robonaut hand.
class EC_ACTIN_GRASPING_DECL EcStageIRobonautPalmAndFingers : public EcBaseStageIGraspingModule
{
public:
   /// default constructor
   EcStageIRobonautPalmAndFingers
      (
      );

   /// destructor
   virtual ~EcStageIRobonautPalmAndFingers
      (
      );

   /// copy constructor
   EcStageIRobonautPalmAndFingers
      (
      const EcStageIRobonautPalmAndFingers& orig
      );

   /// assignment operator
   EcStageIRobonautPalmAndFingers& operator=
      (
      const EcStageIRobonautPalmAndFingers& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIRobonautPalmAndFingers& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const=0;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const=0;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const=0;

   /// return a string token
   virtual const EcToken& token
      (
      ) const=0;

   /// register XML member variables
   void registerComponents
      (
      ) = 0;

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
   /// calculate the placements for the end effectors used in the grasp motion
   virtual void calculateEndEffectorPositions
      (
      EcReal gamma,
      EcEndEffectorPlacementVector& positions
      ) = 0;

   /// calculate the placements for the end effectors used in the grasp motion
   /// (for force control)
   virtual void calculateEndEffectorPositionsForForceControl
      (
      EcEndEffectorPlacementVector& positions
      );

   /// calculate the end effectors to be used for the grasp motion
   virtual void calculateEndEffectorSet
      (
      EcEndEffectorSet& eeSet
      );

   // non-XML below

   /// the time at each stage of the grasp
   EcRealVector m_StartTimes;

   /// the current stage of the grasp
   EcU32 m_CurrentGraspStage;

   /// flag indicating if force control is used
   EcBoolean m_UseForceControl;

   /// the starting control description (should be the control description for position control)
   EcU32 m_StartControlDescription;

   /// the active control description
   EcU32 m_ActiveControlDescription;

   /// the active force control description
   EcU32 m_ActiveForceControlDescription;

   /// the positions are returned in the following object
   EcManipulatorEndEffectorPlacement m_ManipulatorEndEffectorPlacement;

   /// the grasp force
   EcManipulatorSensorForce            m_GraspForce;
};

#endif // ecStageIRobonautPalmAndFingers_H_
