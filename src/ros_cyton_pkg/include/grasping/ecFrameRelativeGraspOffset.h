#ifndef ecFrameRelativeGraspOffset_H_
#define ecFrameRelativeGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameRelativeGraspOffset.h
/// @class EcFrameRelativeGraspOffset
/// @brief This class provides a grasp offset that is relative to
///        a grasp offset in another frame.
/// @todo Fix or remove findDataMapReferences(), which does nothing.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeGraspOffset.h"

/// This class provides a grasp offset that is relative to a grasp offset in another frame.
class EC_ACTIN_GRASPING_DECL EcFrameRelativeGraspOffset : public EcRelativeGraspOffset
{
public:
   /// default constructor
   EcFrameRelativeGraspOffset
      (
      );

   /// destructor
   virtual ~EcFrameRelativeGraspOffset
      (
      );

   /// copy constructor
   EcFrameRelativeGraspOffset
      (
      const EcFrameRelativeGraspOffset& orig
      );

   /// assignment operator
   EcFrameRelativeGraspOffset& operator=
      (
      const EcFrameRelativeGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrameRelativeGraspOffset& orig
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

   /// get a flag indicating of the grasping frame is valid
   virtual EcString validGraspingFrame
      (
      ) const;

   /// does nothing
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

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:

   /// Calculates the primary frame
   /// @param[in] params Grasp paramters
   /// @param[in] sequence The grasp sequence
   /// @param[in] sstate The grasp sequence state
   /// @param[in] frameIndex The index for the frame
   /// @param[in] endEffectorIndex The index for the end effector
   /// @param[in] ostate The state for the grasp offset
   /// @param[out] primaryFrame The primary frame position and orientation
   /// @return success Boolean
   virtual EcBoolean calculatePrimaryFrame
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      const EcGraspSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcGraspOffsetState& ostate,
      EcCoordinateSystemTransformation& primaryFrame
      ) const;

   /// the index of the reference frame in the sequence
   EcXmlU32 m_FrameIndex;
};

#endif // ecFrameRelativeGraspOffset_H_
