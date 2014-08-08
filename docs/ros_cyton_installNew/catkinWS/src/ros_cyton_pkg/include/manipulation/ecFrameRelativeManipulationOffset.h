#ifndef ecFrameRelativeManipulationOffset_H_
#define ecFrameRelativeManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameRelativeManipulationOffset.h
/// @class EcFrameRelativeManipulationOffset
/// @brief This class provides a manipulation offset that is relative to
///        a manipulation offset in another frame.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeManipulationOffset.h"

/// This class provides a manipulation offset that is relative to a manipulation offset in another frame.
class EC_ACTIN_MANIPULATION_DECL EcFrameRelativeManipulationOffset : public EcRelativeManipulationOffset
{
public:
   /// default constructor
   EcFrameRelativeManipulationOffset
      (
      );

   /// destructor
   virtual ~EcFrameRelativeManipulationOffset
      (
      );

   /// copy constructor
   EcFrameRelativeManipulationOffset
      (
      const EcFrameRelativeManipulationOffset& orig
      );

   /// assignment operator
   EcFrameRelativeManipulationOffset& operator=
      (
      const EcFrameRelativeManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrameRelativeManipulationOffset& orig
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

   /// get the frame index
   virtual EcU32 frameIndex
      (
      ) const;

   /// set the frame index
   virtual void setFrameIndex
      (
      EcU32 index
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get a flag indicating of the manipulation frame is valid
   virtual EcString validManipulationFrame
      (
      ) const;

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
   /// calculate manipulation frame
   virtual EcBoolean calculatePrimaryFrame
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcManipulationOffsetState& ostate,
      EcCoordinateSystemTransformation& primaryFrame
      ) const;

   /// the index of the reference frame in the sequence
   EcXmlU32 m_FrameIndex;
};

#endif // ecFrameRelativeManipulationOffset_H_
