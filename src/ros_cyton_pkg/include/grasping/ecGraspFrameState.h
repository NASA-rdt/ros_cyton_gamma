#ifndef ecGraspFrameState_H_
#define ecGraspFrameState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameState.h
/// @class EcGraspFrameState
/// @brief A single frame of a grasp sequence.
///        This represents a snapshot of the desired robot state
///        at a specific point during the grasp sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspStatus.h"

#include <forceControl/ecManipSensorForce.h>
#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcDataMap;
class EcEndEffectorSet;
class EcForceControlDescription;
class EcGraspOffsetStateContainer;
class EcGraspSequenceState;
class EcGraspUpdateParams;
class EcIndividualVelocityControlDescription;
class EcManipulatorEndEffectorPlacement;

/// an XML readable/writable vector of EcGraspOffsetStateContainer objects
typedef EcXmlVectorType<EcGraspOffsetStateContainer> EcGraspOffsetStateContainerVector;

/// an XML readable/writable vector of EcForceControlDescription objects
typedef EcXmlVectorType<EcForceControlDescription> EcForceControlDescriptionVector;

/// an XML readable/writable vector of EcIndividualVelocityControlDescription objects
typedef EcXmlVectorType<EcIndividualVelocityControlDescription> EcVelocityControlDescriptionVector;

/// A single frame of a grasp sequence.
class EC_ACTIN_GRASPING_DECL EcGraspFrameState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspFrameState
      (
      );

   /// destructor
   virtual ~EcGraspFrameState
      (
      );

   /// copy constructor
   EcGraspFrameState
      (
      const EcGraspFrameState& orig
      );

   /// assignment operator
   EcGraspFrameState& operator=
      (
      const EcGraspFrameState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameState& orig
      ) const;

   /// get the vector of offset containers for this frame
   virtual const EcGraspOffsetStateContainerVector& offsetStateContainerVector
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

#endif // ecGraspFrameState_H_
