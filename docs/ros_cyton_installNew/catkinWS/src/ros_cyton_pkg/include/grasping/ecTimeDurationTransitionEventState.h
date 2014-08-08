#ifndef ecTimeDurationTransitionEventState_H_
#define ecTimeDurationTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecTimeDurationTransitionEventState.h
/// @class EcTimeDurationTransitionEventState
/// @brief This class provides a grasp frame transition event based on time.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEventState.h"

#include <xml/ecXmlBasicType.h>

/// This class provides foundation stage I grasping for a Robonaut hand.
class EC_ACTIN_GRASPING_DECL EcTimeDurationTransitionEventState : public EcGraspFrameTransitionEventState
{
public:
   /// default constructor
   EcTimeDurationTransitionEventState
      (
      );

   /// destructor
   virtual ~EcTimeDurationTransitionEventState
      (
      );

   /// copy constructor
   EcTimeDurationTransitionEventState
      (
      const EcTimeDurationTransitionEventState& orig
      );

   /// assignment operator
   EcTimeDurationTransitionEventState& operator=
      (
      const EcTimeDurationTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTimeDurationTransitionEventState& orig
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

   /// get the trigger time
   virtual EcReal triggerTime
      (
      ) const;

   /// set the trigger time
   virtual void setTriggerTime
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
   /// the simulation time when this event is triggered
   EcXmlReal m_TriggerTime;
};

#endif // ecTimeDurationTransitionEventState_H_
