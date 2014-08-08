#ifndef ecManipulationOffsetState_H_
#define ecManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationOffsetState.h
/// @class EcManipulationOffsetState
/// @brief Abstract class defining the interface for manipulation offset states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcEndEffectorPlacement;

/// Abstract class defining the interface for manipulation offset states.
class EC_ACTIN_MANIPULATION_DECL EcManipulationOffsetState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcManipulationOffsetState
      (
      );

   /// copy constructor
   EcManipulationOffsetState
      (
      const EcManipulationOffsetState& orig
      );

   /// assignment operator
   EcManipulationOffsetState& operator=
      (
      const EcManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationOffsetState& orig
      ) const;

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      ) const = 0;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      ) const = 0;
};

#endif // ecManipulationOffsetState_H_
