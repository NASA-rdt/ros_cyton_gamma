#ifndef ecForceDetectedTransitionEvent_H_
#define ecForceDetectedTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceDetectedTransitionEvent.h
/// @class EcForceDetectedTransitionEvent
/// @brief This class provides a grasp frame transition event based
///        on force.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEvent.h"

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>

class EC_ACTIN_GRASPING_DECL EcForceDetectedTransitionEvent : public EcGraspFrameTransitionEvent
{
public:
   /// default constructor
   EcForceDetectedTransitionEvent
      (
      );

   /// destructor
   virtual ~EcForceDetectedTransitionEvent
      (
      );

   /// copy constructor
   EcForceDetectedTransitionEvent
      (
      const EcForceDetectedTransitionEvent& orig
      );

   /// assignment operator
   EcForceDetectedTransitionEvent& operator=
      (
      const EcForceDetectedTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceDetectedTransitionEvent& orig
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

   /// get the timeout period in seconds of the transition event. If the execution time exceeds this timeout
   /// period without the forces being detected, then the update will return EcGraspStatus::FAILED.
   virtual EcReal timeoutPeriod
      (
      ) const;

   /// get the timeout period in seconds of the transition event
   virtual void setTimeoutPeriod
      (
      EcReal timeoutPeriod
      );

   /// get the vector of placement indices to test
   virtual const EcXmlU32Vector& testIndices
      (
      ) const;

   ///set the vector of placement indices to test
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
   /// timeout period
   EcXmlReal m_TimeoutPeriod;

   /// vector of placement indices to test
   EcXmlU32Vector m_TestIndices;

   /// the tolerance for the placement
   EcXmlReal m_Tolerance;
};

#endif // ecForceDetectedTransitionEvent_H_
