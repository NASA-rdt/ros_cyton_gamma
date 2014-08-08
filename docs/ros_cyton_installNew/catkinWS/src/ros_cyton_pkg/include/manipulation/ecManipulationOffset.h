#ifndef ecManipulationOffset_H_
#define ecManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationOffset.h
/// @class EcManipulationOffset
/// @brief Abstract class defining the interface for manipulation offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationStatus.h"

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcEndEffectorPlacement;
class EcManipulationOffsetState;
class EcManipulationOffsetStateContainer;
class EcManipulationSequence;
class EcManipulationSequenceState;
class EcManipulationUpdateParams;

/// Abstract class defining the interface for manipulation offsets.
class EC_ACTIN_MANIPULATION_DECL EcManipulationOffset : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationOffset
      (
      );

   /// destructor
   virtual ~EcManipulationOffset
      (
      );

   /// copy constructor
   EcManipulationOffset
      (
      const EcManipulationOffset& orig
      );

   /// assignment operator
   EcManipulationOffset& operator=
      (
      const EcManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationOffset& orig
      ) const;

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const = 0;

   /// calculate the end state
   virtual EcManipulationOffsetStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex
      ) const = 0;

   /// initialize the offset
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetStateContainer& ostateContainer
      ) const = 0;

   /// update the offset
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetState& ostate
      ) const = 0;

   /// calculate the offset transformation in the system frame
   virtual EcEndEffectorPlacement calculateOffsetTransformationInSystemFrame
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcManipulationOffsetState& ostate
      ) const = 0;

   /// set the offset transformation from an offset defined in the system frame
   virtual void setFromOffsetTransformationInSystemFrame
      (
      const EcEndEffectorPlacement& offset,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetState& ostate
      ) = 0;

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const = 0;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const = 0;
};

#endif // ecManipulationOffset_H_
