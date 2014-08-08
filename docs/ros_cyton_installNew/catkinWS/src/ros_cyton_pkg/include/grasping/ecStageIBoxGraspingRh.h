#ifndef ecStageIBoxGraspingRh_H_
#define ecStageIBoxGraspingRh_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIBoxGraspingRh.h
/// @class EcStageIBoxGraspingRh
/// @brief This class provides stage I box grasping for the Robonaut hand
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageIRobonautPalmAndFingers.h"

class EcSystemActiveState;

/// This class provides stage I box grasping for the Robonaut hand
class EC_ACTIN_GRASPING_DECL EcStageIBoxGraspingRh : public EcStageIRobonautPalmAndFingers
{
public:
   /// default constructor
   EcStageIBoxGraspingRh
      (
      );

   /// destructor
   virtual ~EcStageIBoxGraspingRh
      (
      );

   /// copy constructor
   EcStageIBoxGraspingRh
      (
      const EcStageIBoxGraspingRh& orig
      );

   /// assignment operator
   EcStageIBoxGraspingRh& operator=
      (
      const EcStageIBoxGraspingRh& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIBoxGraspingRh& orig
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
};

#endif // ecStageIBoxGraspingRh_H_
