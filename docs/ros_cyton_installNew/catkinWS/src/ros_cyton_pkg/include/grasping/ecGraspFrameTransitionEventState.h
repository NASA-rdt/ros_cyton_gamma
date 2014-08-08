#ifndef ecGraspFrameTransitionEventState_H_
#define ecGraspFrameTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameTransitionEventState.h
/// @class EcGraspFrameTransitionEventState
/// @brief Abstract class defining the interface for transition
///        events.  This interface is used to signal the end of a
///        grasp frame.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

/// Abstract class defining the interface for transition events.
class EC_ACTIN_GRASPING_DECL EcGraspFrameTransitionEventState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspFrameTransitionEventState
      (
      );

   /// destructor
   virtual ~EcGraspFrameTransitionEventState
      (
      );

   /// copy constructor
   EcGraspFrameTransitionEventState
      (
      const EcGraspFrameTransitionEventState& orig
      );

   /// assignment operator
   EcGraspFrameTransitionEventState& operator=
      (
      const EcGraspFrameTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameTransitionEventState& orig
      ) const;
};

#endif // ecGraspFrameTransitionEventState_H_
