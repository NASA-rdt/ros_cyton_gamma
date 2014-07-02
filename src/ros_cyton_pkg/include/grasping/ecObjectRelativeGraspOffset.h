#ifndef ecObjectRelativeGraspOffset_H_
#define ecObjectRelativeGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecObjectRelativeGraspOffset.h
/// @class EcObjectRelativeGraspOffset
/// @brief This class provides a grasp offset that is relative to
///        the object to be grasped.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeGraspOffset.h"

/// This class provides a grasp offset that is relative to the object to be grasped.
class EC_ACTIN_GRASPING_DECL EcObjectRelativeGraspOffset : public EcRelativeGraspOffset
{
public:
   /// default constructor
   EcObjectRelativeGraspOffset
      (
      );

   /// destructor
   virtual ~EcObjectRelativeGraspOffset
      (
      );

   /// copy constructor
   EcObjectRelativeGraspOffset
      (
      const EcObjectRelativeGraspOffset& orig
      );

   /// assignment operator
   EcObjectRelativeGraspOffset& operator=
      (
      const EcObjectRelativeGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcObjectRelativeGraspOffset& orig
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

   /// calculate the primary frame, which is used as a reference
   virtual EcBoolean calculatePrimaryFrame
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcCoordinateSystemTransformation& primaryFrame
      ) const;
};

#endif // ecObjectRelativeGraspOffset_H_
