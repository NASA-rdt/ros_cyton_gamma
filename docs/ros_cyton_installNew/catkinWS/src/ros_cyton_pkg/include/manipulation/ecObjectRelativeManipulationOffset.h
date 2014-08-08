#ifndef ecObjectRelativeManipulationOffset_H_
#define ecObjectRelativeManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecObjectRelativeManipulationOffset.h
/// @class EcObjectRelativeManipulationOffset
/// @brief This class provides a manipulation offset that is relative to
///        the object to be manipulationed.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeManipulationOffset.h"

/// This class provides a manipulation offset that is relative to the object to be manipulationed.
class EC_ACTIN_MANIPULATION_DECL EcObjectRelativeManipulationOffset : public EcRelativeManipulationOffset
{
public:
   /// default constructor
   EcObjectRelativeManipulationOffset
      (
      );

   /// destructor
   virtual ~EcObjectRelativeManipulationOffset
      (
      );

   /// copy constructor
   EcObjectRelativeManipulationOffset
      (
      const EcObjectRelativeManipulationOffset& orig
      );

   /// assignment operator
   EcObjectRelativeManipulationOffset& operator=
      (
      const EcObjectRelativeManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcObjectRelativeManipulationOffset& orig
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

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// calculate primary frame
   virtual EcBoolean calculatePrimaryFrame
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcCoordinateSystemTransformation& primaryFrame
      ) const;
};

#endif // ecObjectRelativeManipulationOffset_H_
