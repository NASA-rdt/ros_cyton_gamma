#ifndef ecManipulationTimeDurationTransitionEventState_H_
#define ecManipulationTimeDurationTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationTimeDurationTransitionEventState.h
/// @class EcManipulationTimeDurationTransitionEventState
/// @brief This class provides a manipulation frame transition event state based on time.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrameTransitionEventState.h"

#include <xml/ecXmlBasicType.h>

/// This class provides a manipulation frame transition event state based on time.
class EC_ACTIN_MANIPULATION_DECL EcManipulationTimeDurationTransitionEventState : public EcManipulationFrameTransitionEventState
{
public:
   /// default constructor
   EcManipulationTimeDurationTransitionEventState
      (
      );

   /// destructor
   virtual ~EcManipulationTimeDurationTransitionEventState
      (
      );

   /// copy constructor
   EcManipulationTimeDurationTransitionEventState
      (
      const EcManipulationTimeDurationTransitionEventState& orig
      );

   /// assignment operator
   EcManipulationTimeDurationTransitionEventState& operator=
      (
      const EcManipulationTimeDurationTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationTimeDurationTransitionEventState& orig
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

   /// get the progress
   virtual EcReal progress
      (
      ) const;

   /// set the progress
   virtual void setProgress
      (
      EcReal value
      );

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

   /// the progress of this event (0.0 = not started, 1.0 = completed)
   EcXmlReal m_Progress;
};

#endif // ecManipulationTimeDurationTransitionEventState_H_
