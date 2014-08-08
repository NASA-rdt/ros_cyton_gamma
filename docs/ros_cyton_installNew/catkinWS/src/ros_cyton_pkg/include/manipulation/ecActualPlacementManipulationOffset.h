#ifndef ecActualPlacementManipulationOffset_H_
#define ecActualPlacementManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecActualPlacementManipulationOffset.h
/// @class EcActualPlacementManipulationOffset
/// @brief This class provides a manipulation offset that uses the actual EE placement.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffset.h"

/// This class provides a manipulation offset that uses the initial actual EE placement and remains constant throughout the update.
class EC_ACTIN_MANIPULATION_DECL EcActualPlacementManipulationOffset : public EcManipulationOffset
{
public:
   /// default constructor
   EcActualPlacementManipulationOffset
      (
      );

   /// destructor
   virtual ~EcActualPlacementManipulationOffset
      (
      );

   /// copy constructor
   EcActualPlacementManipulationOffset
      (
      const EcActualPlacementManipulationOffset& orig
      );

   /// assignment operator
   EcActualPlacementManipulationOffset& operator=
      (
      const EcActualPlacementManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcActualPlacementManipulationOffset& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// calculate the end state
   virtual EcManipulationOffsetStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex
      ) const;

   /// initialize the transition event
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetStateContainer& ostateContainer
      ) const;

   /// update the trasition event
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetState& ostate
      ) const;

   /// calculate the offset transformation in the system frame
   virtual EcEndEffectorPlacement calculateOffsetTransformationInSystemFrame
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcManipulationOffsetState& ostate
      ) const;

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
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
};

#endif // ecActualPlacementManipulationOffset_H_
