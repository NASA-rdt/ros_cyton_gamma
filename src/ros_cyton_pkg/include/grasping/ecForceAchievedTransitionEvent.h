#ifndef ecForceAchievedTransitionEvent_H_
#define ecForceAchievedTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceAchievedTransitionEvent.h
/// @class EcForceAchievedTransitionEvent
/// @brief This class provides a grasp frame transition event based
///        on force.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEvent.h"

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>

class EC_ACTIN_GRASPING_DECL EcForceAchievedTransitionEvent : public EcGraspFrameTransitionEvent
{
public:
   /// default constructor
   EcForceAchievedTransitionEvent
      (
      );

   /// destructor
   virtual ~EcForceAchievedTransitionEvent
      (
      );

   /// copy constructor
   EcForceAchievedTransitionEvent
      (
      const EcForceAchievedTransitionEvent& orig
      );

   /// assignment operator
   EcForceAchievedTransitionEvent& operator=
      (
      const EcForceAchievedTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceAchievedTransitionEvent& orig
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

   /// get the window of time for testing convergence
   virtual EcReal convergenceWindow
      (
      ) const;

   /// set the window of time for testing convergence
   virtual void setConvergenceWindow
      (
      EcReal convergenceWindow
      );

   /// get the vector of placement indices to test
   virtual const EcXmlU32Vector& testIndices
      (
      ) const;

   /// set the vector of placement indices to test
   virtual void setTestIndices
      (
      const EcXmlU32Vector& testIndices
      );

   /// get the placement tolerance
   virtual EcReal tolerance
      (
      ) const;

   /// set the placement tolerance
   virtual void setTolerance
      (
      EcReal tolerance
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// calculate the end state
   virtual EcGraspFrameTransitionEventStateContainer calculateEndState
      (
      const EcGraspUpdateParams& params,
      const EcGraspFrame& frame
      ) const;

   /// initialize the transition event
   virtual EcBoolean init
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspFrame& frame,
      EcGraspFrameTransitionEventStateContainer& estateContainer
      ) const;

   /// update the trasition event
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspFrame& frame,
      const EcGraspFrameState& fstate,
      EcGraspFrameTransitionEventState& estate
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// window of time for testing convergence
   EcXmlReal m_ConvergenceWindow;

   /// vector of placement indices to test
   EcXmlU32Vector m_TestIndices;

   /// the tolerance for the placement
   EcXmlReal m_Tolerance;
};

#endif // ecForceAchievedTransitionEvent_H_
