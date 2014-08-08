#ifndef ecStageICapsuleGraspingRh_H_
#define ecStageICapsuleGraspingRh_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageICapsuleGraspingRh.h
/// @class EcStageICapsuleGraspingRh
/// @brief This class provides stage I capsule grasping for the Robonaut hand
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageIRobonautPalmAndFingers.h"
#include <geometry/ecCapsule.h>

/// This class provides stage I capsule grasping for the Robonaut hand
class EC_ACTIN_GRASPING_DECL EcStageICapsuleGraspingRh : public EcStageIRobonautPalmAndFingers
{
public:
   /// default constructor
   EcStageICapsuleGraspingRh
      (
      );

   /// destructor
   virtual ~EcStageICapsuleGraspingRh
      (
      );

   /// copy constructor
   EcStageICapsuleGraspingRh
      (
      const EcStageICapsuleGraspingRh& orig
      );

   /// assignment operator
   EcStageICapsuleGraspingRh& operator=
      (
      const EcStageICapsuleGraspingRh& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageICapsuleGraspingRh& orig
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

   /// the capsule
   EcCapsule m_Capsule;

   /// the number of fingers on the Robonaut hand
   static const EcU32 s_NumFingers = 5;

   /// a reference radius for the Robonaut hand
   static const EcReal   s_ReferenceRadius;

   /// tip positions for the Robonaut hand
   static const EcVector s_InitialTipPositions[s_NumFingers];

   /// a first set of tip movements for the Robonaut hand
   static const EcVector s_TipMovements0[s_NumFingers];

   /// a second set of tip movements for the Robonaut hand
   static const EcVector s_TipMovements1[s_NumFingers];
};

#endif // ecStageICapsuleGraspingRh_H_
