#ifndef ecGraspOffset_H_
#define ecGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspOffset.h
/// @class EcGraspOffset
/// @brief Abstract class defining the interface for grasp offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspStatus.h"

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcEndEffectorPlacement;
class EcGraspOffsetState;
class EcGraspOffsetStateContainer;
class EcGraspSequence;
class EcGraspSequenceState;
class EcGraspUpdateParams;

/// Abstract class defining the interface for grasp offsets.
class EC_ACTIN_GRASPING_DECL EcGraspOffset : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspOffset
      (
      );

   /// destructor
   virtual ~EcGraspOffset
      (
      );

   /// copy constructor
   EcGraspOffset
      (
      const EcGraspOffset& orig
      );

   /// assignment operator
   EcGraspOffset& operator=
      (
      const EcGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspOffset& orig
      ) const;

   /// method for finding string-real data for reasoning
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const = 0;

   /// calculate the end state
   virtual EcGraspOffsetStateContainer calculateEndState
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex
      ) const = 0;

   /// initialize the offset
   virtual EcBoolean init
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcGraspOffsetStateContainer& ostateContainer
      ) const = 0;

   /// update the offset
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcGraspOffsetState& ostate
      ) const = 0;

   /// calculate the offset transformation in the system frame
   virtual EcEndEffectorPlacement calculateOffsetTransformationInSystemFrame
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcGraspOffsetState& ostate
      ) const = 0;

   /// set the offset transformation from an offset defined in the system frame
   virtual void setFromOffsetTransformationInSystemFrame
      (
      const EcEndEffectorPlacement& offset,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcGraspOffsetState& ostate
      ) = 0;

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcGraspOffsetState& ostate
      ) const = 0;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcGraspOffsetState& ostate
      ) const = 0;
};

#endif // ecGraspOffset_H_
