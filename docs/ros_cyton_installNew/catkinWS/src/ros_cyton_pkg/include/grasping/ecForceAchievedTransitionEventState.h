#ifndef ecForceAchievedTransitionEventState_H_
#define ecForceAchievedTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceAchievedTransitionEventState.h
/// @class EcForceAchievedTransitionEventState
/// @brief This class provides a grasp frame transition event based
///        on force.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEventState.h"

#include <xml/ecXmlBasicType.h>

class EC_ACTIN_GRASPING_DECL EcForceAchievedTransitionEventState : public EcGraspFrameTransitionEventState
{
public:
   /// default constructor
   EcForceAchievedTransitionEventState
      (
      );

   /// destructor
   virtual ~EcForceAchievedTransitionEventState
      (
      );

   /// copy constructor
   EcForceAchievedTransitionEventState
      (
      const EcForceAchievedTransitionEventState& orig
      );

   /// assignment operator
   EcForceAchievedTransitionEventState& operator=
      (
      const EcForceAchievedTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceAchievedTransitionEventState& orig
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

#endif // ecForceAchievedTransitionEventState_H_
