#ifndef ecLinkRelativeManipulationOffset_H_
#define ecLinkRelativeManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkRelativeManipulationOffset.h
/// @class EcLinkRelativeManipulationOffset
/// @brief This class provides a manipulation offset that is relative to
///        a specified link on the object to be manipulationed.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeManipulationOffset.h"

/// This class provides a manipulation offset that is relative to a specified link on the object to be manipulationed.
class EC_ACTIN_MANIPULATION_DECL EcLinkRelativeManipulationOffset : public EcRelativeManipulationOffset
{
public:
   enum
   {
      PRIMARY_FRAME, //< offset relative to the link's primary frame
      DH_FRAME,      //< offset relative to the link's dh frame
   };

   /// default constructor
   EcLinkRelativeManipulationOffset
      (
      );

   /// destructor
   virtual ~EcLinkRelativeManipulationOffset
      (
      );

   /// copy constructor
   EcLinkRelativeManipulationOffset
      (
      const EcLinkRelativeManipulationOffset& orig
      );

   /// assignment operator
   EcLinkRelativeManipulationOffset& operator=
      (
      const EcLinkRelativeManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkRelativeManipulationOffset& orig
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

   /// the link frame type
   EcXmlEnumU32                     m_LinkFrameType;

   /// the name of the link
   EcXmlString                      m_LinkIdentifier;
};

#endif // ecLinkRelativeManipulationOffset_H_
