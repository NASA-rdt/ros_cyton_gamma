#ifndef ecGraspOffsetState_H_
#define ecGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspOffsetState.h
/// @class EcGraspOffsetState
/// @brief Abstract class defining the interface for grasp offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcEndEffectorPlacement;

/// Abstract class defining the interface for grasp offsets.
class EC_ACTIN_GRASPING_DECL EcGraspOffsetState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcGraspOffsetState
      (
      );

   /// copy constructor
   EcGraspOffsetState
      (
      const EcGraspOffsetState& orig
      );

   /// assignment operator
   EcGraspOffsetState& operator=
      (
      const EcGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspOffsetState& orig
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

#endif // ecGraspOffsetState_H_
