#ifndef ecTimeDurationTransitionEvent_H_
#define ecTimeDurationTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecTimeDurationTransitionEvent.h
/// @class EcTimeDurationTransitionEvent
/// @brief This class provides a grasp frame transition event based on time.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEvent.h"

#include <xml/ecXmlBasicType.h>

/// This class provides foundation stage I grasping for a Robonaut hand.
class EC_ACTIN_GRASPING_DECL EcTimeDurationTransitionEvent : public EcGraspFrameTransitionEvent
{
public:
   /// default constructor
   EcTimeDurationTransitionEvent
      (
      );

   /// destructor
   virtual ~EcTimeDurationTransitionEvent
      (
      );

   /// copy constructor
   EcTimeDurationTransitionEvent
      (
      const EcTimeDurationTransitionEvent& orig
      );

   /// assignment operator
   EcTimeDurationTransitionEvent& operator=
      (
      const EcTimeDurationTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTimeDurationTransitionEvent& orig
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

   /// get the time duration
   virtual EcReal timeDuration
      (
      ) const;

   /// set the time duration
   virtual void setTimeDuration
      (
      EcReal timeDuration
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

   /// the time for the transition
   EcXmlReal m_TimeDuration;
};

#endif // ecTimeDurationTransitionEvent_H_
