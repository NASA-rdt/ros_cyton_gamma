#ifndef ecManipulationFrameState_H_
#define ecManipulationFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrameState.h
/// @class EcManipulationFrameState
/// @brief A single frame of a manipulation sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the manipulation sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationStatus.h"

#include <forceControl/ecManipSensorForce.h>
#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcDataMap;
class EcEndEffectorSet;
class EcManipulatorEndEffectorPlacement;
class EcManipulationOffsetStateContainer;
class EcManipulationSequenceState;
class EcManipulationUpdateParams;
/// type definition of EcManipulationOffsetStateContainerVector
typedef EcXmlVectorType<EcManipulationOffsetStateContainer> EcManipulationOffsetStateContainerVector;

/// A single frame of a manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrameState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationFrameState
      (
      );

   /// destructor
   virtual ~EcManipulationFrameState
      (
      );

   /// copy constructor
   EcManipulationFrameState
      (
      const EcManipulationFrameState& orig
      );

   /// assignment operator
   EcManipulationFrameState& operator=
      (
      const EcManipulationFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrameState& orig
      ) const;

   /// get the vector of offset containers for this frame
   virtual const EcManipulationOffsetStateContainerVector& offsetStateContainerVector
      (
      ) const = 0;

   /// get the current end effector placement
   virtual const EcManipulatorEndEffectorPlacement& currentEndEffectorPlacement
      (
      ) const = 0;

   /// get the goal end effector placement
   virtual const EcManipulatorEndEffectorPlacement& goalEndEffectorPlacement
      (
      ) const = 0;
};

#endif // ecManipulationFrameState_H_
