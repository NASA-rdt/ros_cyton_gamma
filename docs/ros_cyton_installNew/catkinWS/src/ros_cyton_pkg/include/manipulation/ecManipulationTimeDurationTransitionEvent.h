#ifndef ecManipulationTimeDurationTransitionEvent_H_
#define ecManipulationTimeDurationTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationTimeDurationTransitionEvent.h
/// @class EcManipulationTimeDurationTransitionEvent
/// @brief This class provides a manipulation frame transition event based on time.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrameTransitionEvent.h"

#include <xml/ecXmlBasicType.h>

/// This class provides a manipulation frame transition event based on time.
class EC_ACTIN_MANIPULATION_DECL EcManipulationTimeDurationTransitionEvent : public EcManipulationFrameTransitionEvent
{
public:
   /// default constructor
   EcManipulationTimeDurationTransitionEvent
      (
      );

   /// destructor
   virtual ~EcManipulationTimeDurationTransitionEvent
      (
      );

   /// copy constructor
   EcManipulationTimeDurationTransitionEvent
      (
      const EcManipulationTimeDurationTransitionEvent& orig
      );

   /// assignment operator
   EcManipulationTimeDurationTransitionEvent& operator=
      (
      const EcManipulationTimeDurationTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationTimeDurationTransitionEvent& orig
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
   virtual EcManipulationFrameTransitionEventStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame
      ) const;

   /// initialize the transition event
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame,
      EcManipulationFrameTransitionEventStateContainer& estateContainer
      ) const;

   /// update the trasition event
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame,
      const EcManipulationFrameState& fstate,
      EcManipulationFrameTransitionEventState& estate
      ) const;

   /// get the overall progress of this transition event
   virtual EcReal progress
      (
      const EcManipulationFrameTransitionEventState& estate
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
   EcXmlReal m_TimeDuration;     ///< time duration
};

#endif // ecManipulationTimeDurationTransitionEvent_H_
