#ifndef ecInterpolatedManipulationOffset_H_
#define ecInterpolatedManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecInterpolatedManipulationOffset.h
/// @class EcInterpolatedManipulationOffset
/// @brief This class provides a manipulation offset that is interpolated.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffset.h"
#include "ecManipulationOffsetContainer.h"

/// This class provides a manipulation offset that is interpolated.
class EC_ACTIN_MANIPULATION_DECL EcInterpolatedManipulationOffset : public EcManipulationOffset
{
public:
   /// default constructor
   EcInterpolatedManipulationOffset
      (
      );

   /// destructor
   virtual ~EcInterpolatedManipulationOffset
      (
      );

   /// copy constructor
   EcInterpolatedManipulationOffset
      (
      const EcInterpolatedManipulationOffset& orig
      );

   /// assignment operator
   EcInterpolatedManipulationOffset& operator=
      (
      const EcInterpolatedManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcInterpolatedManipulationOffset& orig
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

   /// get the target offset
   virtual const EcManipulationOffsetContainer& targetOffset
      (
      ) const;

   /// set the target offset
   virtual void setTargetOffset
      (
      const EcManipulationOffsetContainer& targetOffset
      );

   /// get the interpolation time
   virtual EcReal interpolationTime
      (
      ) const;

   /// set the interpolation time
   virtual void setInterpolationTime
      (
      EcReal interpolationTime
      );

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

protected:
   /// target offset for the inerpolation
   EcManipulationOffsetContainer m_TargetOffset;

   /// time of interpolation
   EcXmlReal              m_InterpolationTime;
};

#endif // ecInterpolatedManipulationOffset_H_
