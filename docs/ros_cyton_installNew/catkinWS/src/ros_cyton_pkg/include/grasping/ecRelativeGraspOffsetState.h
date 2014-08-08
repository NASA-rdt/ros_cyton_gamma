#ifndef ecRelativeGraspOffsetState_H_
#define ecRelativeGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecRelativeGraspOffsetState.h
/// @class EcRelativeGraspOffsetState
/// @brief This class is an abstract interface for relative grasp offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffsetState.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class is an abstract interface for relative grasp offsets.
class EC_ACTIN_GRASPING_DECL EcRelativeGraspOffsetState : public EcGraspOffsetState
{
public:
   /// default constructor
   EcRelativeGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcRelativeGraspOffsetState
      (
      );

   /// copy constructor
   EcRelativeGraspOffsetState
      (
      const EcRelativeGraspOffsetState& orig
      );

   /// assignment operator
   EcRelativeGraspOffsetState& operator=
      (
      const EcRelativeGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRelativeGraspOffsetState& orig
      ) const;

   /// get the offset
   virtual const EcEndEffectorPlacement& offset
      (
      ) const;

   /// set the offset
   virtual void setOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      ) const;

protected:
   /// the calculated offset
   EcEndEffectorPlacement m_Offset;
};

#endif // ecRelativeGraspOffsetState_H_
