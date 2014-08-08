#ifndef ecManipulationFrameTransitionEvent_H_
#define ecManipulationFrameTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrameTransitionEvent.h
/// @class EcManipulationFrameTransitionEvent
/// @brief Abstract class defining the interface for transition
///        events.  This interface is used to signal the end of a
///        manipulation frame.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationStatus.h"

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcManipulationFrame;
class EcManipulationFrameState;
class EcManipulationFrameTransitionEventState;
class EcManipulationFrameTransitionEventStateContainer;
class EcManipulationUpdateParams;

/// Abstract class defining the interface for transition events.
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrameTransitionEvent : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationFrameTransitionEvent
      (
      );

   /// destructor
   virtual ~EcManipulationFrameTransitionEvent
      (
      );

   /// copy constructor
   EcManipulationFrameTransitionEvent
      (
      const EcManipulationFrameTransitionEvent& orig
      );

   /// assignment operator
   EcManipulationFrameTransitionEvent& operator=
      (
      const EcManipulationFrameTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrameTransitionEvent& orig
      ) const;

   /// calculate the end state
   virtual EcManipulationFrameTransitionEventStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame
      ) const = 0;

   /// initialize the event
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame,
      EcManipulationFrameTransitionEventStateContainer& estateContainer
      ) const = 0;

   /// update the event
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame,
      const EcManipulationFrameState& fstate,
      EcManipulationFrameTransitionEventState& estate
      ) const = 0;

   /// get the overall progress of this transition event
   virtual EcReal progress
      (
      const EcManipulationFrameTransitionEventState& estate
      ) const = 0;
};

#endif // ecManipulationFrameTransitionEvent_H_
