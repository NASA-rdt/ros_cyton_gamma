#ifndef ecParametricTranslationManipulationOffset_H_
#define ecParametricTranslationManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricTranslationManipulationOffset.h
/// @class EcParametricTranslationManipulationOffset
/// @brief This class provides a translation manipulation offset that is parametrically defined.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffset.h"
#include "ecManipulationOffsetContainer.h"

/// This class provides a translation manipulation offset that is parametrically defined.
class EC_ACTIN_MANIPULATION_DECL EcParametricTranslationManipulationOffset : public EcManipulationOffset
{
public:
   /// default constructor
   EcParametricTranslationManipulationOffset
      (
      );

   /// destructor
   virtual ~EcParametricTranslationManipulationOffset
      (
      );

   /// copy constructor
   EcParametricTranslationManipulationOffset
      (
      const EcParametricTranslationManipulationOffset& orig
      );

   /// assignment operator
   EcParametricTranslationManipulationOffset& operator=
      (
      const EcParametricTranslationManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricTranslationManipulationOffset& orig
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

   /// get the tag used for determining the parametric X value
   virtual const EcString& parametricXTag
      (
      ) const;

   /// set the tag used for determining the parametric X value
   virtual void setParametricXTag
      (
      const EcString& tag
      );

   /// get the tag used for determining the parametric Y value
   virtual const EcString& parametricYTag
      (
      ) const;

   /// set the tag used for determining the parametric Y value
   virtual void setParametricYTag
      (
      const EcString& tag
      );

   /// get the tag used for determining the parametric Z value
   virtual const EcString& parametricZTag
      (
      ) const;

   /// set the tag used for determining the parametric Z value
   virtual void setParametricZTag
      (
      const EcString& tag
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
   /// target offset to combine with the parametric translation
   EcManipulationOffsetContainer m_TargetOffset;

   /// tag used for determining the parametric X value
   EcXmlString            m_ParametricXTag;

   /// tag used for determining the parametric Y value
   EcXmlString            m_ParametricYTag;

   /// tag used for determining the parametric Z value
   EcXmlString            m_ParametricZTag;
};

#endif // ecParametricTranslationManipulationOffset_H_
