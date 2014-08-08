#ifndef ecInterpolatedGraspOffset_H_
#define ecInterpolatedGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecInterpolatedGraspOffset.h
/// @class EcInterpolatedGraspOffset
/// @brief This class provides a grasp offset that is interpolated.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffset.h"
#include "ecGraspOffsetContainer.h"

/// This class provides a grasp offset that is interpolated.
class EC_ACTIN_GRASPING_DECL EcInterpolatedGraspOffset : public EcGraspOffset
{
public:
   /// default constructor
   EcInterpolatedGraspOffset
      (
      );

   /// destructor
   virtual ~EcInterpolatedGraspOffset
      (
      );

   /// copy constructor
   EcInterpolatedGraspOffset
      (
      const EcInterpolatedGraspOffset& orig
      );

   /// assignment operator
   EcInterpolatedGraspOffset& operator=
      (
      const EcInterpolatedGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcInterpolatedGraspOffset& orig
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
   virtual const EcGraspOffsetContainer& targetOffset
      (
      ) const;

   /// set the target offset
   virtual void setTargetOffset
      (
      const EcGraspOffsetContainer& targetOffset
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
   virtual EcGraspOffsetStateContainer calculateEndState
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex
      ) const;

   /// initialize the transition event
   virtual EcBoolean init
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcGraspOffsetStateContainer& ostateContainer
      ) const;

   /// update the trasition event
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcGraspOffsetState& ostate
      ) const;

   /// calculate the offset transformation in the system frame
   virtual EcEndEffectorPlacement calculateOffsetTransformationInSystemFrame
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcGraspOffsetState& ostate
      ) const;

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
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcGraspOffsetState& ostate
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcGraspOffsetState& ostate
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
   EcGraspOffsetContainer m_TargetOffset;

   /// time of interpolation
   EcXmlReal              m_InterpolationTime;
};

#endif // ecInterpolatedGraspOffset_H_
