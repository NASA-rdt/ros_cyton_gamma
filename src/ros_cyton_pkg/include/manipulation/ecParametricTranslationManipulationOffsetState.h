#ifndef ecParametricTranslationManipulationOffsetState_H_
#define ecParametricTranslationManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricTranslationManipulationOffsetState.h
/// @class EcParametricTranslationManipulationOffsetState
/// @brief This class provides a translation manipulation offset that is parametrically defined.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffsetState.h"
#include "ecManipulationOffsetStateContainer.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a translation manipulation offset that is parametrically defined.
class EC_ACTIN_MANIPULATION_DECL EcParametricTranslationManipulationOffsetState : public EcManipulationOffsetState
{
public:
   /// default constructor
   EcParametricTranslationManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcParametricTranslationManipulationOffsetState
      (
      );

   /// copy constructor
   EcParametricTranslationManipulationOffsetState
      (
      const EcParametricTranslationManipulationOffsetState& orig
      );

   /// assignment operator
   EcParametricTranslationManipulationOffsetState& operator=
      (
      const EcParametricTranslationManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricTranslationManipulationOffsetState& orig
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
   virtual EcManipulationOffsetState* targetOffsetState
      (
      );

   /// get the target offset
   virtual const EcManipulationOffsetState* targetOffsetState
      (
      ) const;

   /// set the target offset
   virtual void setTargetOffsetState
      (
      const EcManipulationOffsetStateContainer& targetOffsetState
      );

   /// get the parametric transform
   virtual const EcEndEffectorPlacement& parametricTransform
      (
      ) const;

   /// set the parametric transform
   virtual void setParametricTransform
      (
      const EcEndEffectorPlacement& transform
      );

   /// get the current offset
   virtual const EcEndEffectorPlacement& currentOffset
      (
      ) const;

   /// set the current offset
   virtual void setCurrentOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
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
   EcManipulationOffsetStateContainer      m_TargetOffsetState;

   /// parametric transform
   EcEndEffectorPlacement m_ParametricTransform;

   /// current offset
   EcEndEffectorPlacement m_CurrentOffset;

   /// goal offset
   mutable EcEndEffectorPlacement m_GoalOffset;
};

#endif // ecParametricTranslationManipulationOffsetState_H_
