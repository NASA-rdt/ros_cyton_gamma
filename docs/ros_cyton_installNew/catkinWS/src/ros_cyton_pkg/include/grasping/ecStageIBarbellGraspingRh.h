#ifndef ecStageIBarbellGraspingRh_H_
#define ecStageIBarbellGraspingRh_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIBarbellGraspingRh.h
/// @class EcStageIBarbellGraspingRh
/// @brief This class provides stage I barbell grasping for the Robonaut hand.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageIRobonautPalmAndFingers.h"
#include <geometry/ecSphere.h>

/// This class provides stage I barbell grasping for the Robonaut hand.
class EC_ACTIN_GRASPING_DECL EcStageIBarbellGraspingRh : public EcStageIRobonautPalmAndFingers
{
public:
   /// default constructor
   EcStageIBarbellGraspingRh
      (
      );

   /// destructor
   virtual ~EcStageIBarbellGraspingRh
      (
      );

   /// copy constructor
   EcStageIBarbellGraspingRh
      (
      const EcStageIBarbellGraspingRh& orig
      );

   /// assignment operator
   EcStageIBarbellGraspingRh& operator=
      (
      const EcStageIBarbellGraspingRh& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIBarbellGraspingRh& orig
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

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// calculate the placements for the end effectors used in the grasp motion
   virtual void calculateEndEffectorPositions
      (
      EcReal gamma,
      EcEndEffectorPlacementVector& positions
      );

   // non-XML below

   /// the parameters
   EcCapsule m_CapsuleBoundingVolume;
};

#endif // ecStageIBarbellGraspingRh_H_
