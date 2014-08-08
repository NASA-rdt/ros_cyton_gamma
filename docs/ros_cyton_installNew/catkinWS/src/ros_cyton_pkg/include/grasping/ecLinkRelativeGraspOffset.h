#ifndef ecLinkRelativeGraspOffset_H_
#define ecLinkRelativeGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkRelativeGraspOffset.h
/// @class EcLinkRelativeGraspOffset
/// @brief This class provides a grasp offset that is relative to
///        a specified link on the object to be grasped.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeGraspOffset.h"

/// This class provides a grasp offset that is relative to a specified link on the object to be grasped.
class EC_ACTIN_GRASPING_DECL EcLinkRelativeGraspOffset : public EcRelativeGraspOffset
{
public:
   enum
   {
      PRIMARY_FRAME, //< offset relative to the link's primary frame
      DH_FRAME,      //< offset relative to the link's dh frame
   };

   /// default constructor
   EcLinkRelativeGraspOffset
      (
      );

   /// destructor
   virtual ~EcLinkRelativeGraspOffset
      (
      );

   /// copy constructor
   EcLinkRelativeGraspOffset
      (
      const EcLinkRelativeGraspOffset& orig
      );

   /// assignment operator
   EcLinkRelativeGraspOffset& operator=
      (
      const EcLinkRelativeGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkRelativeGraspOffset& orig
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

   /// get the link frame type
   virtual EcU32 linkFrameType
      (
      ) const;

   /// set the link frame type
   virtual void setLinkFrameType
      (
      EcU32 value
      );

   /// get the link identifier
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// set the link identifier
   virtual void setLinkIdentifier
      (
      const EcString& identifier
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

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:

   /// calculate the location of the primary frame, which is used as a reference
   virtual EcBoolean calculatePrimaryFrame
      (
      const EcGraspUpdateParams& params,
      const EcGraspSequence& sequence,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcCoordinateSystemTransformation& primaryFrame
      ) const;

   /// the link frame type
   EcXmlEnumU32                     m_LinkFrameType;

   /// the name of the link
   EcXmlString                      m_LinkIdentifier;
};

#endif // ecLinkRelativeGraspOffset_H_
