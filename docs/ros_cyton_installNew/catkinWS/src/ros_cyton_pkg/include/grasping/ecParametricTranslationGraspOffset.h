#ifndef ecParametricTranslationGraspOffset_H_
#define ecParametricTranslationGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricTranslationGraspOffset.h
/// @class EcParametricTranslationGraspOffset
/// @brief This class provides a translation grasp offset that is parametrically defined.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffset.h"
#include "ecGraspOffsetContainer.h"

/// This class provides a translation grasp offset that is parametrically defined.
class EC_ACTIN_GRASPING_DECL EcParametricTranslationGraspOffset : public EcGraspOffset
{
public:
   /// default constructor
   EcParametricTranslationGraspOffset
      (
      );

   /// destructor
   virtual ~EcParametricTranslationGraspOffset
      (
      );

   /// copy constructor
   EcParametricTranslationGraspOffset
      (
      const EcParametricTranslationGraspOffset& orig
      );

   /// assignment operator
   EcParametricTranslationGraspOffset& operator=
      (
      const EcParametricTranslationGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricTranslationGraspOffset& orig
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
   /// target offset to combine with the parametric translation
   EcGraspOffsetContainer m_TargetOffset;

   /// tag used for determining the parametric X value
   EcXmlString            m_ParametricXTag;

   /// tag used for determining the parametric Y value
   EcXmlString            m_ParametricYTag;

   /// tag used for determining the parametric Z value
   EcXmlString            m_ParametricZTag;
};

#endif // ecParametricTranslationGraspOffset_H_
