#ifndef ecGraspFrameTransitionEvent_H_
#define ecGraspFrameTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameTransitionEvent.h
/// @class EcGraspFrameTransitionEvent
/// @brief Abstract class defining the interface for transition
///        events.  This interface is used to signal the end of a
///        grasp frame.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspStatus.h"

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcGraspFrame;
class EcGraspFrameState;
class EcGraspFrameTransitionEventState;
class EcGraspFrameTransitionEventStateContainer;
class EcGraspUpdateParams;

/// Abstract class defining the interface for transition events.
class EC_ACTIN_GRASPING_DECL EcGraspFrameTransitionEvent : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspFrameTransitionEvent
      (
      );

   /// destructor
   virtual ~EcGraspFrameTransitionEvent
      (
      );

   /// copy constructor
   EcGraspFrameTransitionEvent
      (
      const EcGraspFrameTransitionEvent& orig
      );

   /// assignment operator
   EcGraspFrameTransitionEvent& operator=
      (
      const EcGraspFrameTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameTransitionEvent& orig
      ) const;

   /// calculate the end state
   virtual EcGraspFrameTransitionEventStateContainer calculateEndState
      (
      const EcGraspUpdateParams& params,
      const EcGraspFrame& frame
      ) const = 0;

   /// initialize the event
   virtual EcBoolean init
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspFrame& frame,
      EcGraspFrameTransitionEventStateContainer& estateContainer
      ) const = 0;

   /// update the event
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspFrame& frame,
      const EcGraspFrameState& fstate,
      EcGraspFrameTransitionEventState& estate
      ) const = 0;
};

#endif // ecGraspFrameTransitionEvent_H_
