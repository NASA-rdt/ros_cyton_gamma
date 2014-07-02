#ifndef ecStageISphereGraspingRh_H_
#define ecStageISphereGraspingRh_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageISphereGraspingRh.h
/// @class EcStageISphereGraspingRh
/// @brief This class provides stage I sphere grasping for the Robonaut hand
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <geometry/ecSphere.h>
#include "ecStageIRobonautPalmAndFingers.h"

/// This class provides stage I sphere grasping for the Robonaut hand
class EC_ACTIN_GRASPING_DECL EcStageISphereGraspingRh : public EcStageIRobonautPalmAndFingers
{
public:
   /// default constructor
   EcStageISphereGraspingRh
      (
      );

   /// destructor
   virtual ~EcStageISphereGraspingRh
      (
      );

   /// copy constructor
   EcStageISphereGraspingRh
      (
      const EcStageISphereGraspingRh& orig
      );

   /// assignment operator
   EcStageISphereGraspingRh& operator=
      (
      const EcStageISphereGraspingRh& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageISphereGraspingRh& orig
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

   /// the sphere
   EcSphere m_Sphere;

   /// the number of fingers for the Robonaut hand
   static const EcU32 s_NumFingers = 5;

   /// a constant reference radius for calculations
   static const EcReal   s_ReferenceRadius;

   /// a tip position for each of the fingers
   static const EcVector s_InitialTipPositions[s_NumFingers];

   /// a first set of movements for each of the fingers
   static const EcVector s_TipMovements0[s_NumFingers];

   /// a second set of movements for each of the fingers
   static const EcVector s_TipMovements1[s_NumFingers];
};

#endif // ecStageISphereGraspingRh_H_
