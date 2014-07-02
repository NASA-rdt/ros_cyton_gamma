#ifndef ecRelativeManipulationOffsetState_H_
#define ecRelativeManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecRelativeManipulationOffsetState.h
/// @class EcRelativeManipulationOffsetState
/// @brief This class is an abstract interface for relative manipulation offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffsetState.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class is an abstract interface for relative manipulation offsets.
class EC_ACTIN_MANIPULATION_DECL EcRelativeManipulationOffsetState : public EcManipulationOffsetState
{
public:
   /// default constructor
   EcRelativeManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcRelativeManipulationOffsetState
      (
      );

   /// copy constructor
   EcRelativeManipulationOffsetState
      (
      const EcRelativeManipulationOffsetState& orig
      );

   /// assignment operator
   EcRelativeManipulationOffsetState& operator=
      (
      const EcRelativeManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRelativeManipulationOffsetState& orig
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

#endif // ecRelativeManipulationOffsetState_H_
