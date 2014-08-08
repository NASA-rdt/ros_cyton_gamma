#ifndef ecManipulationFrameTransitionEventState_H_
#define ecManipulationFrameTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrameTransitionEventState.h
/// @class EcManipulationFrameTransitionEventState
/// @brief Abstract class defining the interface for transition
///        event states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

/// Abstract class defining the interface for transition events.
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrameTransitionEventState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationFrameTransitionEventState
      (
      );

   /// destructor
   virtual ~EcManipulationFrameTransitionEventState
      (
      );

   /// copy constructor
   EcManipulationFrameTransitionEventState
      (
      const EcManipulationFrameTransitionEventState& orig
      );

   /// assignment operator
   EcManipulationFrameTransitionEventState& operator=
      (
      const EcManipulationFrameTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrameTransitionEventState& orig
      ) const;
};

#endif // ecManipulationFrameTransitionEventState_H_
