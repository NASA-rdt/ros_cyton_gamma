#ifndef ecPlacementAchievedTransitionEventState_H_
#define ecPlacementAchievedTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlacementAchievedTransitionEventState.h
/// @class EcPlacementAchievedTransitionEventState
/// @brief This class provides a grasp frame transition event based
///        on placement.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEventState.h"

#include <xml/ecXmlBasicType.h>

/// This class provides foundation stage I grasping for a Robonaut hand.
class EC_ACTIN_GRASPING_DECL EcPlacementAchievedTransitionEventState : public EcGraspFrameTransitionEventState
{
public:
   /// default constructor
   EcPlacementAchievedTransitionEventState
      (
      );

   /// destructor
   virtual ~EcPlacementAchievedTransitionEventState
      (
      );

   /// copy constructor
   EcPlacementAchievedTransitionEventState
      (
      const EcPlacementAchievedTransitionEventState& orig
      );

   /// assignment operator
   EcPlacementAchievedTransitionEventState& operator=
      (
      const EcPlacementAchievedTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlacementAchievedTransitionEventState& orig
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

   /// get the convergence value used for testing convergence
   virtual EcReal convergenceValue
      (
      ) const;

   /// set the convergence value used for testing convergence
   virtual void setConvergenceValue
      (
      EcReal value
      );

   /// get the start time of the convergence window for testing convergence
   virtual EcReal convergenceWindowStartTime
      (
      ) const;

   /// set the start time of the convergence window for testing convergence
   virtual void setConvergenceWindowStartTime
      (
      EcReal time
      );

   /// register XML member variables
   virtual void registerComponents
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

protected:
   /// the convergence value used for testing convergence
   EcXmlReal m_ConvergenceValue;

   /// the start time of the convergence window for testing convergence
   EcXmlReal m_ConvergenceWindowStartTime;
};

#endif // ecPlacementAchievedTransitionEventState_H_
